#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


#define BUFFER_SIZE 8

struct Products {
    int buffer[BUFFER_SIZE];
    /*保证存取操作的原子性 互斥性*/
    pthread_mutex_t locker;
    /*是否可读*/
    pthread_cond_t notEmpty;
    /*是否可写*/
    pthread_cond_t notFull;
    int posReadFrom;
    int posWriteTo;
};

int BufferIsFull(struct Products* products) {
    if ((products->posWriteTo + 1) % BUFFER_SIZE == products->posReadFrom) {
        return (1);
    }
    return (0);
}

int BufferIsEmpty(struct Products* products) {
    if (products->posWriteTo == products->posReadFrom) {
        return (1);
    }
    return (0);
}

/*制造产品*/


void Produce(struct Products* products, int item) {
    /*原子操作*/
    pthread_mutex_lock(&products->locker);
    /*无空间可写入*/
    while (BufferIsFull(products)) {
        pthread_cond_wait(&products->notFull, &products->locker);
    }

    /*写入数据*/
    products->buffer[products->posWriteTo] = item;
    products->posWriteTo++;
    if (products->posWriteTo >= BUFFER_SIZE)
        products->posWriteTo = 0;
    /*发信*/
    pthread_cond_signal(&products->notEmpty);
    /*解锁*/
    pthread_mutex_unlock(&products->locker);
}

int Consume(struct Products* products) {
    int item;
    pthread_mutex_lock(&products->locker);
    /*为空时持续等待,无数据可读*/
    while (BufferIsEmpty(products)) {
        pthread_cond_wait(&products->notEmpty, &products->locker);
    }
    /*提取数据*/
    item = products->buffer[products->posReadFrom];
    products->posReadFrom++;
    /*如果到末尾,从头读取*/
    if (products->posReadFrom >= BUFFER_SIZE)
        products->posReadFrom = 0;
    pthread_cond_signal(&products->notFull);
    pthread_mutex_unlock(&products->locker);
    return item;
}




#define END_FLAG (-1)
struct Products products;

void* ProducerThread(void* data) {
    int i;
    for (i = 0; i < 16; ++i) {
        printf("producer: %d\n", i);
        Produce(&products, i);
    }
    Produce(&products, END_FLAG);
    return NULL;
}

void* ConsumerThread(void* data) {
    int item;
    while (1) {
        item = Consume(&products);
        if (END_FLAG == item)
            break;
        printf("consumer: %d\n", item);
    }
    return (NULL);
}

int main(int argc, char* argv[]) {
    pthread_t producer;
    pthread_t consumer;
    int result;
    pthread_create(&producer, NULL, &ProducerThread, NULL);
    pthread_create(&consumer, NULL, &ConsumerThread, NULL);
    pthread_join(producer, (void *) &result);
    pthread_join(consumer, (void *) &result);
    exit(EXIT_SUCCESS);
}

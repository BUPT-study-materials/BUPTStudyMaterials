#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define SHMKEY 75
int sharemid,i;   char *addr;

char *argv[ ]={"OS is really interesting..."};

void B( )
{
	sharemid=shmget(SHMKEY,512,0777);      //打开共享存储区

	addr=shmat(sharemid,0,0);           //获得共享存储区首地址

	memset(addr,'\0',512);       //将addr的512字节设置成字符'\0'

	strncpy(addr,argv[0],512); //将数组argv的前512字节存入共享区addr

	exit(0);
}

void A( )
{
	sharemid=shmget(SHMKEY,512,0777|IPC_CREAT); //创建共享存储区
	addr=shmat(sharemid,0,0);        //获取首地址

	printf("get '%s' from shared memory\n",addr);

	exit(0);
}

int main( )
{
	while ((i=fork( ))==-1);
	if (!i) A();

	while ((i=fork( ))==-1);
	if (!i) B();

	wait(0);
	wait(0);
}

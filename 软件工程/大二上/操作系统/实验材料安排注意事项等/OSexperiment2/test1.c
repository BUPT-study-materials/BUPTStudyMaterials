#include <unistd.h>  
#include <stdio.h>   
int main ()   
{   
    pid_t fpid; //fpid表示fork函数返回的值   
    fpid=fork();   
    if (fpid < 0)   
        printf("error in fork!");   
    else if (fpid == 0) 
    {  
        printf("b\n");
        printf("i am the child process, my process id is %d\n",getpid()); 
	execlp("/bin/ls","ls",NULL);  
     
    }  
    else 
    {  
        printf("a\n"); 
        printf("i am the parent process, my process id is %d\n",getpid());
	wait(NULL);
	fpid = fork();
        if (fpid < 0)   
            printf("error in fork!");  
	else if (fpid == 0) 
        {  
            printf("c\n"); 
	    printf("i am the child process, my process id is %d\n",getpid());      
        }  
    }   
    return 0;  
}  

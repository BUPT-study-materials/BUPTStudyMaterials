#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<stdio.h>
#include<stdlib.h>
#define MSGKEY 75

struct msgform

{
	long mtype;

	char mtext[250];

}msg;

int msgqid,pid,*pint,i;

void client()
{
	msgqid=msgget(MSGKEY,0777);   //打开75#消息队列

	pid=getpid();

	pint=(int *)msg.mtext;

	*pint=pid;

	msg.mtype=1;              //消息类型为1

	msgsnd(msgqid,&msg,sizeof(int),0);//添加消息

	msgrcv(msgqid,&msg,250,pid,0);     //接收消息

	printf("(client):receive reply from pid=%d\n",*pint); //显示server进程标识数

	exit(0);

}

void server( )
{
    msgqid=msgget(MSGKEY,0777|IPC_CREAT); //创建75#消息队列

	msgrcv(msgqid,&msg,250,1,0);   //接收消息

	pint=(int *)msg.mtext;     //把正文的内容传给pint，并强制转换类型

	pid=*pint;                    //获得cilent进程标识数

	printf("(server):serving for client pid=%d\n",pid);

	msg.mtype=pid;     //消息类型为client进程标识数

	*pint=getpid();      //获取server进程标识数

	msgsnd(msgqid,&msg,sizeof(int),0); //发送消息

	exit(0);

}

int main()
{
	while((i=fork())==-1){}; //创建进程1
	if(!i)server();

	while((i=fork())==-1){}; //创建进程2
	if(!i) client();

	wait(0);
	wait(0);
}

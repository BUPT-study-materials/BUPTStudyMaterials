#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<syslog.h>
#include<string.h>
#include<stdlib.h>
#define MAX 128
int chmd();
int chmd ()
{
	int c;
	mode_t mode=S_IWUSR;
	printf(" 0. 所有用户读写执行\n 1. 所有用户只可读\n 2. 所有用户只可写 \n 3. 所有用户只可执行\n 4. 用户组读写执行\n 5. 用户组只可读\n 6. 用户组只可写\n 7. 用户组只可执行\n "); 
	printf("请选择0-7:");
	scanf("%d",&c);
	switch(c)
	{
		case 0: chmod("newfile",S_IRWXU);break;
		case 1: chmod("newfile ",S_IRUSR);break;
		case 2: chmod("newfile ",S_IWUSR);break;
		case 3: chmod("newfile ",S_IXUSR);break;
       	case 4: chmod("newfile ", S_IRWXG);break;
     	case5: chmod("newfile ",S_IRGRP);break;
       	case6: chmod("newfile ",S_IWGRP);break;
case7: chmod("newfile ", S_IXGRP);break;
		default:printf("error choice!\n");		
	}
	return(0);
}
void main()
{
	int fd;
	int num;    
	int choice;
	char buffer[MAX];
	struct stat buf;
	char* path="/bin/ls";
char* argv[4]={"ls","-l","newfile",NULL};
   while(1)
   {
	printf("********************************\n");
	printf("0. 退出\n");
	printf("1. 创建新文件\n");
	printf("2. 写文件\n");
	printf("3. 读文件\n");
	printf("4. 修改文件权限\n");
	printf("5. 查看当前文件的权限修改文件权限\n");	
 	printf("********************************\n");
	
    printf("请选择(0-5):");
    scanf("%d",&choice);    
    
        switch(choice)
        {
           	case 0:close(fd); 
  		  	exit(0); 
	   		case 1:
                fd=open("newfile",O_RDWR|O_TRUNC|O_CREAT,0750);
                if(fd==-1)
                    printf("File Create Failed!\n");
                else
                    printf("fd = %d\n",fd); 
                break;
            	case 2:
                num=read(0,buffer,MAX);
	            write(fd,buffer,num);
                break;
            	case 3:
         
                read(fd,buffer,MAX);
                write(1,buffer,num);
                break;
            	case 4:
                chmd ();
                printf("成功改变格式!\n");
                break;
 			case 5:
               	execv(path,argv);
                break;           
            	default:
                printf("error choice!\n");
        }
  }    
}

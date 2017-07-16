#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

#define FIFO_NAME "myfifo"
#define BUF_SIZE 1024

int main()
{
	int fd;
	char buf[BUF_SIZE] = "Hello prowrite,i come from process named processed!";
	
	umask(0);
	
	if(mkfifo(FIFO_NAME,S_IFIFO | 0666) == -1)
	{
		perror("mkfifo error!");
		exit(1);
	}

	if((fd = open(FIFO_NAME,O_WRONLY)) == -1)
	{//以只写方式打开FIFO
		perror("fopen error!");
		exit(1);
	}
	write(fd,buf,strlen(buf)+1);//向管道写数据
	close(fd);
	exit(0);
}

#include"../utili.h"
#define BUFFER_SIZE 64


int main()
{
	struct sockaddr_in server_address;
	bzero(&server_address,sizeof(server_address));
	server_address.sin_family = AF_INET;
	inet_pton(AF_INET,SERVER_IP,&server_address.sin_addr);
	server_address.sin_port = htons(SERVER_PORT);

	int sockfd = socket(PF_INET,SOCK_STREAM,0);
	assert(sockfd >= 0);
	if(connect(sockfd,(struct sockaddr*)&server_address,sizeof(server_address)) < 0)
	{
		printf("connection failed\n");
		close(sockfd);
		return 1;
	}

	struct pollfd fds[2];
	fds[0].fd = 0;
	fds[0].events = POLLIN;
	fds[0].revents = 0;
	fds[1].fd = sockfd;
	fds[1].events = POLLIN | POLLRDHUP;
	fds[1].revents = 0;
	char read_buf[BUFFER_SIZE];
	int pipefd[2];
	int ret = pipe(pipefd);
	assert(ret != -1);

	while(1)
	{
		ret = poll(fds,2,-1);
		if(ret < 0)
		{
			printf("poll failture\n");
			break;
		}

		if(fds[1].revents & POLLRDHUP)
		{
			printf("server close the connection\n");
			break;
		}
		else if(fds[1].revents & POLLIN)
		{
			memset(read_buf,'\0',BUFFER_SIZE);
			recv(fds[1].fd,read_buf,BUFFER_SIZE-1,0);
			printf("%s\n",read_buf);
		}

		if(fds[0].revents & POLLIN)
		{
			ret = splice(0,NULL,pipefd[1],NULL,32768,SPLICE_F_MORE | SPLICE_F_MOVE);
			ret = splice(pipefd[0],NULL,sockfd,NULL,32768,SPLICE_F_MORE | SPLICE_F_MOVE);

		}
	}
	close(sockfd);
	return 0;
}

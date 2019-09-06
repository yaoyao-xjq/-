#include <../include/mysocket.h>
extern int STATE;
int createsocket(char *ip,int port)
{
	struct sockaddr_in sock_addr_server ,sock_addr_client;
	//init socaddr
	memset(&sock_addr_client,0,sizeof(sock_addr_client));
	sock_addr_server.sin_family=AF_INET;//ipv4 / ipv6
	sock_addr_server.sin_port=htons(port);//host to net short
	//sock_addr.sin_addr.s_addr=htonl(INADDR_ANY);//long
	inet_pton(AF_INET,ip,&sock_addr_server.sin_addr.s_addr);


	//create sockfd
	int sockfd=socket(AF_INET,SOCK_STREAM,0);

	//connet
	if(0==(connect(sockfd, (struct sockaddr *)&sock_addr_server, sizeof(sock_addr_server))))
	{
		return sockfd;
	}else
	{
		return 0;
	}

}
void* clientcommunicat(void* arg)
{
	pthread_detach(pthread_self());
	int n=0;
	char buf[BUFSIZE];
	int sockfd = (long)arg;
	printf("thread ready \n");
	while(1)
	{
		memset(buf,0,sizeof(buf));
		if((n=read(sockfd,buf,BUFSIZE))>0)
		{
			printf("from server:%s",buf);
			//to ABCD
			if(!strcmp(buf,"open\n"))
				keepdooropen();
			if(!strcmp(buf,"close\n"))
				keepdoorclose();
			if(!strcmp(buf,"normal\n"))
				STATE=STATE_NORMAL;
			if(!strcmp(buf,"video\n"))
				printf("D\n");
		}
	}
}
void* uploadlog(void*arg)
{
	stu_arg* stuarg = (stu_arg*)arg;
	int serfd=stuarg->sockfd;
	struct tm* starttime = stuarg->starttm;
	struct tm* endtime   = stuarg->endtm;
	int logfd;
	int n;
	char buf[BUFSIZE];
	while(1)
	{
		logfd = open("./IOlog.log",O_RDONLY);
		n=0;
		while(1)
		{
			if( 1 )//判断时间段函数
				break;
			else
				sleep(100);
		}
		sleep(120);
		while((n=read(logfd,buf,BUFSIZE))>0)
		{

			write(serfd,buf,n);
			memset(buf,0,sizeof(buf));
		}
		if(n==0)
			printf("upload success\n");
		else
			printf("upload read err\n");
		close(logfd);
	}
}
void opendoor()
{
	printf("Open the door\n");
	//sleep(3);
}
void closedoor()
{
	printf("Close the door\n");
	//sleep(3);
}
void keepdoorclose()
{
	printf("Door close\n");
	STATE=STATE_CLOSE;
	closedoor();
}
void keepdooropen()
{
	printf("Door open\n");
	STATE=STATE_OPEN;
	opendoor();
}

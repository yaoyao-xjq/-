#include <resources.h>
#ifndef _MYSOCKET_H_
#define _MYSOCKET_H_
typedef struct
{
	int sockfd;
	struct tm* starttm;
	struct tm* endtm;
}stu_arg;
int createsocket(char *ip,int port);
void* uploadlog(void* arg);				//上传
void* clientcommunicat(void* arg);				//读指
void closedoor();							//关门
void opendoor();					//开门
void keepdooropen();						//常开
void keepdoorclose();						//常闭
#endif

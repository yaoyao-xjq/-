//#program once
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include "cv.h"
#include "highgui.h"
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <iostream>
#ifndef _RESOURES_H_
#define _RESOURES_H_
#define BUFSIZE 1500                    //缓冲区大小
#define LISTENSIZE  10
#define NAMESIZE 20			//名字长度
#define WRITEBUF 1024			//写缓冲区大小
#define IPSIZE   260
#define LED_NUM 2
#define LED_C 2	
#define ERR_MALLOC 1
#define ERR_UNEXPECTED 2
#define ERR_LOAD 3
#define STATE_NORMAL 0  	//正常
#define STATE_OPEN 1		//常开
#define STATE_CLOSE 2		//常闭
#define STATE_VEDIO 3		//监控
#endif

//#program once
#include <resources.h>
#ifndef _IMAGE_H_
#define _IMAGE_H_
/*int IMG_HEIGHT = 200;			//默认图片高度
int IMG_WIDTH = 180;			//默认图片宽度
double MATCHING_RATE = 0.1;			//默认匹配率
int TOTALNUM = 12;                         //默认train库总人数
int IMGPERPEOPLE = 4;			//默认train库每人图片数
#define TRAIN_NUM (TOTALNUM * IMGPERPEOPLE)      //train库总图片数*/
typedef struct {
	char** elem; //存储空间基地址
	char ip[IPSIZE];				//ip地址
	int port;		//端口号
	double matching_rate;//匹配率
	int img_width;		//图片宽度
	int img_height ;	//图片高度
	int peoplenum; //当前人数
	int imgperpeople; //train库每人图片数
	int ser_idtofd;	//机器号
	struct tm starttime; //起止时间
	struct tm endtime;
} Sconfig;
#endif

#include <resources.h>
#include <image.h>
#ifndef _LOADCONF_H_
#define _LOADCONF_H_
Sconfig* createSconfig();					//创建结构体
void destorySconfig(Sconfig *Sc);				//释放存储空间
int  get_line(int conffd,char* buf);//获取文件一行内容
int  loadconfig(Sconfig* sc);//本函数返回指针为malloc实现 释放空间需要先释放内部各个姓名空间 
#endif


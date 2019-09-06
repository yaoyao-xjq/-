#include <../include/resources.h>
#include <../include/image.h>
#include <../include/mysocket.h>
#include <../include/loadconf.h>
#include <../include/loadimg.h>
#include <../include/myPCA.h>


int STATE = STATE_NORMAL;
using namespace cv;
using namespace std;
int IMG_HEIGHT = 200;			//默认图片高度
int IMG_WIDTH = 180;			//默认图片宽度
double MATCHING_RATE = 0.1;			//默认匹配率
int TOTALNUM = 12;                         //默认train库总人数
int IMGPERPEOPLE = 4;			//默认train库每人图片数
int TRAIN_NUM = (TOTALNUM * IMGPERPEOPLE) ;     //train库总图片数



void IOlog(char*str);			//记录进出日志



int btime(struct tm tmstart , struct tm tmend);//判断是否在时间要求之内


int btime(struct tm tmstart , struct tm tmend)//判断是否在时间要求之内
{
	struct tm* temptm;
	time_t mtime;
	time(&mtime);
	temptm = localtime(&mtime);
	int nowtime=temptm->tm_hour*3600+temptm->tm_min*60+temptm->tm_sec;
	int starttime=tmstart.tm_hour*3600+tmstart.tm_min*60+tmstart.tm_sec;
	int endtime=tmend.tm_hour*3600+tmend.tm_min*60+tmend.tm_sec;
	if(nowtime<=endtime&&nowtime>=starttime)// 8-19之间通过
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

void IOlog(char*str)
{
	int logfd=0;
	//char *iolog = "./IOlog.log";
	time_t mtime;
	char tempbuf[WRITEBUF];
	memset(tempbuf,0,WRITEBUF);
	time(&mtime);
	if((logfd = open("./IOlog.log",O_WRONLY|O_CREAT|O_APPEND,0664))<0)
		printf("open log failed\n");  	
	else{
		sprintf(tempbuf,"%s %s",str,ctime(&mtime));
		write(logfd,tempbuf,strlen(tempbuf));
	}
	close(logfd);
	printf("%s %s",str,ctime(&mtime));
}


int main(int argc, char* argv[])
{





	printf("start\n");

	double *OriginalData = NULL, *CovarianceMatrix = NULL, *Average = NULL;
	double *Eigenvalue = NULL,*FeatureVectors = NULL, *C=NULL, *p_q = NULL;
	double *projected_train = NULL, *TestData = NULL, *projected_test = NULL;
	double *eigenvector = NULL, *Euc_dist = NULL;
	double temp = 0;
	const double eps = 0.000001;
	int i, j, flag = 0, num_q;
	const int iteration = 60;
	int bflag = 0;
	/*****************************/

	char* strname = (char*)malloc(50); //如果用char res[50] 会导致栈溢出
	memset(strname, 0, 50);
	/*****************************/
	Sconfig *config = NULL;
	config = createSconfig();
	if(config == NULL)
	{
		perror("malloc failed!\n");
		exit(ERR_MALLOC);
	}

	bflag = loadconfig(config);
	if(bflag == 0)
	{
		perror("Load config failed!\n");
		exit(ERR_LOAD);
	}
	puts("load success!\n");
	IMG_HEIGHT = config->img_height; //图片高度
	IMG_WIDTH = config->img_width;	//图片宽度
	MATCHING_RATE = config->matching_rate;	//匹配率					
	TOTALNUM  = config->peoplenum ;                //train库总人数
	TRAIN_NUM = (TOTALNUM * IMGPERPEOPLE) ;
	//printf("%d\n",TOTALNUM);
	IMGPERPEOPLE = config->imgperpeople;
	/*******************************/
	//建立网络连接
	//create sockaddr
	int sockfd=createsocket(config->ip,config->port);

	int n=0;
	int num=0;
	char buf[1024];

	printf("sockfd=%d\n",sockfd);
	if(sockfd!=0)
	{
		pthread_t  tid_cts,tid_stu;//cts: communacate to server ,stu:sleep to upload
		pthread_create(&tid_cts,NULL,clientcommunicat,(void*)sockfd);
		stu_arg  stuarg;
		stuarg.sockfd=sockfd;
		//time_t mtime;
		//time(&mtime);
		//temptm = localtime(&mtime);
		stuarg.starttm= &config->starttime ;
		stuarg.endtm= &config->endtime;
		pthread_create(&tid_stu,NULL,uploadlog,(void*)&stuarg);
		puts("Enter online mode!\n");
	}
	//fcntl(sockfd,F_SETFL,O_NONBLOCK); //设定非阻塞

	else 
		puts("Enter offline mode!\n");


	printf("ready to work\n");
	/*******************************/
	IplImage *tmp_img, *test_img;
	Mat image;
	OriginalData = (double *)malloc(sizeof(double)*IMG_HEIGHT*IMG_WIDTH*TRAIN_NUM);	//原始数据T
	TestData = (double *)malloc(sizeof(double)*IMG_HEIGHT*IMG_WIDTH);		//测试数据
	Average = (double *)malloc(sizeof(double)*IMG_HEIGHT*IMG_WIDTH);		//平均值
	CovarianceMatrix = (double *)malloc(sizeof(double)*TRAIN_NUM*TRAIN_NUM);		//协方差矩阵，L=T'*T
	Eigenvalue = (double *)malloc(sizeof(double)*TRAIN_NUM);				//L的特征值
	FeatureVectors = (double *)malloc(sizeof(double)*TRAIN_NUM*TRAIN_NUM);	//L特征值对应的特征向量
	C = (double *)malloc(sizeof(double)*TRAIN_NUM);				//实对称三对角矩阵的次对角线元素
	if(OriginalData == NULL || TestData == NULL || Average == NULL || CovarianceMatrix == NULL\
			||Eigenvalue == NULL || FeatureVectors == NULL || C ==NULL)
	{
		perror("malloc failed!\n");
		exit(ERR_MALLOC);
	}
	memset(CovarianceMatrix, 0, sizeof(double)*TRAIN_NUM*TRAIN_NUM);
	printf("start reading the image!\n");
	//存储图像数据到T矩阵
//	printf("%d\n",TRAIN_NUM);
	if(0==loadimage(OriginalData,tmp_img))
	{
		perror("malloc failed!\n");
		exit(ERR_MALLOC);
	}
	/*for (i = 1; i <= TRAIN_NUM; i++)
	  {
	  sprintf(res, "../train_lib/%d.jpg", i);
	  tmp_img = cvLoadImage(res, CV_LOAD_IMAGE_GRAYSCALE);
	//cvShowImage("src", tmp_img);
	//cvWaitKey();
	memset(res, 0, 50);
	load_data(OriginalData, tmp_img, i);
	}
	printf("B\n");
	free(res);*/
	//求T矩阵行的平均值
	else printf("Read the image successfully!\n");
	calc_aver(OriginalData, Average);

	//构造协方差矩阵
	calc_covariance_matrix(OriginalData, CovarianceMatrix, Average);

	//求L的特征值，特征向量

	get_elementary_matrix(CovarianceMatrix, TRAIN_NUM, FeatureVectors, Eigenvalue, C);
	flag = QR_iteration(TRAIN_NUM, Eigenvalue, C, FeatureVectors, eps, iteration); //数组q中第j列为数组b中第j个特征值对应的特征向量
	if (flag <= 0)
	{
		perror("Unexpected failed!\n");
		exit(ERR_UNEXPECTED);
	}
	else
	{
		printf("Success to get eigen value and vector\n");
	}

	//对Eigenvalue挑选合适的特征值，过滤特征向量
	num_q = 0;
	for (i = 0; i < TRAIN_NUM; i++)
	{
		if (Eigenvalue[i] > 1)
		{
			//	printf("%d,%f\n", i + 1, Eigenvalue[i]);
			num_q++;
		}
	}
	//printf("...................\n");
	p_q = (double *)malloc(sizeof(double)*TRAIN_NUM*TRAIN_NUM);			//挑选后的Eigenvalue的特征向量，仅过滤，未排序
	projected_train = (double *)malloc(sizeof(double)*TRAIN_NUM*num_q);	//投影后的训练样本特征空间
	eigenvector = (double *)malloc(sizeof(double)*IMG_HEIGHT*IMG_WIDTH*num_q);//Pe=λe,Q(Xe)=λ(Xe)，投影变换向量
	get_eignevalue(Eigenvalue, FeatureVectors, p_q, num_q);
	get_eigenface(p_q, OriginalData, num_q, projected_train, eigenvector);
	//开启摄像头
//	VideoCapture capture(0);
	//设置分辨率
	//capture.set(CV_CAP_PROP_FRAME_WIDTH,3*180);

	//capture.set(CV_CAP_PROP_FRAME_HEIGHT,3*200);

	int delay =1000/30;//设置帧数
	Mat frame;
	int key;
	Mat srimage;
	Mat newimage;
	while(1)
	{

//		capture>>frame;
//		imshow("window",frame);

		key = waitKey(delay);
		if(27 == (char)key)
		{
			imwrite("../test_lib/sctmp.jpg",frame);
			srimage = imread("../test_lib/sctmp.jpg", 1 );
			if ( !srimage.data )
			{
				printf("No image data \n");
				//continue;
			}
			//namedWindow("Display Image", WINDOW_AUTOSIZE );
			//imshow("Display Image", image);
			//waitKey(0);
			if((STATE==STATE_CLOSE)||!btime(config->starttime,config->endtime))

			{
				printf("It's not accessible at this time.\n");
				continue;
			}else if((STATE==STATE_OPEN))
			{
				printf("The door was already open.\n");
				continue;
			}else
			{
				resize(srimage,newimage,Size(IMG_WIDTH,IMG_HEIGHT)); //图像大小转换  

				//imshow("newimage", newimage);  //显示变换大小后的图像  
				//waitKey(0);  
				imwrite("../test_lib/tmp.jpg", newimage); //保存图片  
				//waitKey(0); 


				//	while(!(STATE & STATE_NORMAL))
				//	{
				//		if(STATE & STATE_OPEN)
				//			keepdooropen();
				//		else if(STATE & STATE_CLOSE)
				//			keepdoorclose();
				//read**************************************************************************************************
				//	}
				//read_GPIO();
				//读取测试图像
				test_img = cvLoadImage("../test_lib/tmp.jpg", CV_LOAD_IMAGE_GRAYSCALE);
				projected_test = (double *)malloc(sizeof(double)*num_q * 1);//在特征空间投影后的测试样本
				for (i = 0; i < IMG_HEIGHT; i++)
				{
					for (j = 0; j < IMG_WIDTH; j++)
					{
						TestData[i*IMG_WIDTH + j] = (double)(unsigned char)test_img->imageData[i*IMG_WIDTH + j] - Average[i*IMG_WIDTH + j];
					}
				}

				//将待测数据投影到特征空间
				memset(projected_test, 0, sizeof(double)*num_q);
				matrix_multiplication(projected_test, eigenvector, TestData, num_q, IMG_WIDTH*IMG_HEIGHT, 1);

				//计算projected_test与projected_train中每个向量的欧氏距离
				Euc_dist = (double *)malloc(sizeof(double)*TRAIN_NUM);
				for (i = 0; i < TRAIN_NUM; i++)
				{
					temp = 0;
					for (j = 0; j < num_q; j++)
					{
						temp = temp + (projected_test[j] - projected_train[j*TRAIN_NUM + i])*(projected_test[j] - projected_train[j*TRAIN_NUM + i]);
					}
					Euc_dist[i] = temp;
					//printf("%f \n", temp);
				}
				//寻找最小距离
				double min = Euc_dist[0];
				int label;
				double sum = 0;
				double aver;
				for (i = 0; i < TRAIN_NUM; i++)
				{
					sum += Euc_dist[i];
					if (min >= Euc_dist[i])
					{
						min = Euc_dist[i];
						label = i;
					}
				}
				aver = getaver(label ,Euc_dist ,sum);//计算aver值
				/****************************************************/
				for(int i=0;i<TRAIN_NUM;i++)
				{
					printf("%lf\t\t%lf\n", Euc_dist[i], Euc_dist[i] / aver);
				}

				printf("%lf\n", min / aver);
				printf("%lf\n",MATCHING_RATE);
				if (min / aver <= MATCHING_RATE)
				{
					opendoor();
					printf("%d.jpg is mathcing!\n", (label + 1));
					printf("%s is mathcing!\n", config->elem[(label / IMGPERPEOPLE)]);
					IOlog(config->elem[(label / IMGPERPEOPLE)]);
					sprintf(strname, "../train_lib/%d.jpg", (label + 1));

					image = imread(strname, 1 );
					//namedWindow("Display Image", WINDOW_AUTOSIZE );
					imshow(config->elem[(label / IMGPERPEOPLE)], image);
					waitKey(10000);
					destroyWindow(config->elem[(label / IMGPERPEOPLE)]);
					closedoor();						

					//led_green();
				}
				else
				{
					printf("Matching failed!\n");
					//led_red();
					//拍摄
					//buzz();

				}
			}
			//	break;
		}
	}
	destorySconfig(config);
	//system("pause");
	return 0;
}













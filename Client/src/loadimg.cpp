#include <../include/loadimg.h>
extern int IMGPERPEOPLE;
extern int TOTALNUM;
extern int IMG_WIDTH;
extern int IMG_HEIGHT;
extern double MATCHING_RATE;
extern int TRAIN_NUM;
int loadimage(double *OriginalData,IplImage *tmp_img)
{
	char* res = (char*)malloc(50); //如果用char res[50] 会导致栈溢出
	if(res==NULL)
	{
		return 0;
	}
	memset(res, 0, 50);
	int i;
	for (i = 1; i <= TRAIN_NUM; i++)
	{

		sprintf(res, "../train_lib/%d.jpg", i);
		tmp_img = cvLoadImage(res, CV_LOAD_IMAGE_GRAYSCALE);
		//cvShowImage("src", tmp_img);
		//cvWaitKey();
		memset(res, 0, 50);
		load_data(OriginalData, tmp_img, i);
	}
	free(res);
	return 1;
}
void load_data(double *T, IplImage *src, int k)
{
	int i, j;
	//一副图像压缩成一维的，存在T的一列里
	for (i = 0; i<IMG_HEIGHT; i++)
	{
		for (j = 0; j<IMG_WIDTH; j++)
		{
			T[(i*IMG_WIDTH + j)*TRAIN_NUM + k - 1] = (double)(unsigned char)src->imageData[i*IMG_WIDTH + j];
		}
	}
}



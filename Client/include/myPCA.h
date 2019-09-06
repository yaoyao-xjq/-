#include <resources.h>
#ifndef _MYPCA_H_
#define _MYPCA_H_
void calc_aver(double *T, double *m);						//计算平均值
void calc_covariance_matrix(double *T, double *L, double *m);	//计算特征向量
void get_eignevalue(double *b, double *q, double *p_q, int num_q);	//获取特征值
void get_eigenface(double *p_q, double *T, int num_q, double *projected, double *eigenvector);	//获取特征脸
void get_elementary_matrix(double a[], int n, double q[], double b[], double c[]);//Household transformation 镜像变换
int QR_iteration(int n, double b[], double c[], double q[], double eps, int l);	//QR迭代算法求解特征值和特征向量
void matrix_multiplication(double *c, double *a, double *b, int x, int y, int z);//矩阵乘法
void matrix_reverse(double *src, double *dest, int row, int col);	//矩阵转置
double getaver(int label ,double *Euc,double sum);//计算aver值
#endif

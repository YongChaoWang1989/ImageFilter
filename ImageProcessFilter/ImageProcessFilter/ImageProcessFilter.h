#ifndef IMAGE_PROCESS_FILTER_H
#define IMAGE_PROCESS_FILTER_H

#include<iostream>
#include"opencv2/core/core.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

void RGBtoYUV(Mat src, unsigned char *buf_Y, unsigned char *buf_U, unsigned char *buf_V, int height, int width);
void  NV21toRGB(Mat &processImg, unsigned char *buf_Y, unsigned char *buf_U, unsigned char *buf_V, int height, int width);
bool YUV2RGBLine(unsigned char *buf_Y, unsigned char *buf_U, unsigned char *buf_V, Mat &B, Mat &G, Mat &R);
void YUV2RGBPoint(unsigned char *buf_Y, unsigned char *buf_U, unsigned char *buf_V, Mat &B, Mat &G, Mat &R, int m, bool *isEnd);

void fastIntegralMean(unsigned char* inputMatrix, unsigned long* outputMatrixSum, int height, int width);
void myBoxFilter(unsigned char *buf_Y, unsigned long * sumIntegral, int height, int  width, int size);


void blackWhiteFilter(Mat &inputImg,Mat &outputImg);//�ڰ��˾�
void brickFilter(Mat &inputImg, Mat &outputImg);//��ľЧ������������
void brightContrastFilter(Mat &inputImg, Mat &outputImg);//�����Աȶ���Ч
void FrostedGlassFilter(Mat inputImg, Mat &outputImg);//ë�����˾�
void HighPassFilter(Mat inputImg, Mat &outputImg);//�߷����
void MosaicFilter(Mat inputImg, Mat &outputImg);//������
void CameoFilter(Mat inputImg, Mat &outputImg);//����
void EdgeDetectionFilter(Mat inputImg, Mat &outputImg);//��Ե���
void skinAdjust(Mat inputImg, Mat &outputImg);//Ƥ�����ȵ��������

void skinColorAdjust(Mat inputImg, Mat &outputImg);//Ƥ����ɫ����
void skinRedOrWhite(Mat inputImg, Mat &outputImg);//Ƥ���������





#endif
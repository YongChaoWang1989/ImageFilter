#include"ImageProcessFilter.h"
/*
*���ߣ�������
*���ܣ�ë����Ч���˾�
*���룺Mat inputImg
*�����Mat &outputImg
*����ֵ:��
*/
void FrostedGlassFilter(Mat inputImg, Mat &outputImg)
{
	outputImg = inputImg.clone();
	int width = inputImg.cols, height = inputImg.rows;
	int imgsize = height*width;
	unsigned char *buf_Y, *buf_U, *buf_V;//ԭʼYUV
	buf_Y = new unsigned char[imgsize];
	buf_U = new unsigned char[imgsize / 4];
	buf_V = new unsigned char[imgsize / 4];//����YUV420sp��ʽ
	unsigned long *sumIntegral = new unsigned long[imgsize];//�ۼƻ���ͼ
	RGBtoYUV(inputImg, buf_Y, buf_U, buf_V, height, width);
	fastIntegralMean(buf_Y, sumIntegral, height, width);
	myBoxFilter(buf_Y, sumIntegral, height,width,8);//�޸Ĳ����ﵽ��ͬЧ��
    NV21toRGB(outputImg, buf_Y, buf_U, buf_V, height, width);
	delete[]buf_Y;
	delete[]buf_U;
	delete[]buf_V;
	delete[]sumIntegral;
}
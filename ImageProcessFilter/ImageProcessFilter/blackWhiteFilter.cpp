#include"ImageProcessFilter.h"
/*
*���ߣ�������
*���ܣ��ڰ��˾�
*���룺Mat &inputImg
*�����Mat &outputImg
*����ֵ:��
*/
void blackWhiteFilter(Mat &inputImg, Mat &outputImg)
{
	int row = inputImg.rows;
	int col = inputImg.cols;
	int channel = inputImg.channels();
	outputImg = Mat::zeros(row,col,CV_8UC1);
	for (int i = 0; i < row; i++)
	{
		uchar* dataSrc = inputImg.ptr<uchar>(i);
		uchar* dataFinal = outputImg.ptr<uchar>(i);
		for (int j = 0; j < col; j++)
		{
			dataFinal[j] = dataSrc[j*channel] * 0.59 + dataSrc[j*channel + 1] * 0.11 + dataSrc[j*channel + 2] * 0.3;//BGRBGRBGRBGR....Mat�������ݴ洢��ʽ
		}
	}
}
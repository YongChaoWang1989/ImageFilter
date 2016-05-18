#include"ImageProcessFilter.h"
/*
*���ߣ�������
*���ܣ�������Ч���˾�
*���룺Mat inputImg
*�����Mat &outputImg
*����ֵ:��
*/
void MosaicFilter(Mat inputImg, Mat &outputImg)
{
	int MosiacSize = 16;
	int width = inputImg.cols, height = inputImg.rows;
	int r = 0, g = 0, b = 0;
	outputImg = inputImg.clone();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i % MosiacSize == 0)
			{
				if (j%MosiacSize == 0)
				{//������ʱ��ȡ���ظ�ֵ                      	 
					r = outputImg.at<uchar>(i, j * 3 + 2);
					g = outputImg.at<uchar>(i, j * 3 + 1);
					b = outputImg.at<uchar>(i, j * 3);
				}
				outputImg.at<uchar>(i, j * 3 + 2) = r;
				outputImg.at<uchar>(i, j * 3 + 1) = g;
				outputImg.at<uchar>(i, j * 3) = b;
			}
			else
			{ //������һ��           	       		 
				outputImg.at<uchar>(i, j * 3 + 2) = outputImg.at<uchar>(i - 1, j * 3 + 2);
				outputImg.at<uchar>(i, j * 3 + 1) = outputImg.at<uchar>(i - 1, j * 3 + 1);
				outputImg.at<uchar>(i, j * 3) = outputImg.at<uchar>(i - 1, j * 3);
			}
		}


	}
}
#include "ImageProcessFilter.h"
/*
*���ߣ�������
*���ܣ�����Ƥ����ɫ�ı�,�����ڻƹ��»�ɫ�����������ڰ���ɫ
*���룺Mat inputImg
*�����Mat outputImg
*����ֵ:��
*/
void skinColorAdjust(Mat inputImg, Mat &outputImg)
{
	float rParameter = 1.2;//ֵ��1��10ȡ(1.5,2.5,5.0,10.0)��������ɫ���ȷ�����ֵԽ�󣬺�ɫԽ����Ϊ1ʱ��������
	Mat imgRed, imgGreen, imgBlue, processImg;
	vector<Mat> mbgr(inputImg.channels());
	imgRed = cv::Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC1);
	imgGreen = cv::Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC1);
	imgBlue = cv::Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC1);
	processImg = cv::Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC3);
	for (int i = 0; i < inputImg.rows; i++)
	{
		for (int j = 0; j < inputImg.cols; j++)
		{
			int b = inputImg.at<Vec3b>(i, j)[1];//��ɫͨ������ɫ���棬ʹ������ƫ���
			int g = inputImg.at<Vec3b>(i, j)[1];
			int r = inputImg.at<Vec3b>(i, j)[2];
			imgBlue.at<uchar>(i, j) = b;
			imgGreen.at<uchar>(i, j) = g;
			imgRed.at<uchar>(i, j) = 255 * pow(r / 255.0, rParameter);
		}
	}
	mbgr[0] = imgBlue;
	mbgr[1] = imgGreen;
	mbgr[2] = imgRed;
	merge(mbgr, outputImg);//�ϲ���ͨ�����ݵ�һ��ͼ��
	skinAdjust(outputImg, outputImg);
}

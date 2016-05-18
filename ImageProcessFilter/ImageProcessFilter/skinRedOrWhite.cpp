#include"ImageProcessFilter.h"
/*
*���ߣ�������
*���ܣ������ɫ�ı䣬�������
*���룺Mat inputImg
*�����Mat outputImg
*����ֵ:��
*/
void skinRedOrWhite(Mat inputImg, Mat &outputImg)
{
	//float rParameter = 0.9;//ֵ��1��10ȡ(1.5,2.5,5.0,10.0)��������ɫ���ȷ�����ֵԽ�󣬺�ɫԽ����Ϊ1ʱ��������
	//Mat imgRed, imgGreen, imgBlue, processImg;
	//vector<Mat> mbgr(inputImg.channels());
	//imgRed = cv::Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC1);
	//imgGreen = cv::Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC1);
	//imgBlue = cv::Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC1);
	//processImg = cv::Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC3);
	//for (int i = 0; i < inputImg.rows; i++)
	//{
	//	for (int j = 0; j < inputImg.cols; j++)
	//	{
	//		int b = inputImg.at<Vec3b>(i, j)[0];//��ɫͨ������ɫ���棬ʹ������ƫ���
	//		int g = inputImg.at<Vec3b>(i, j)[1];
	//		int r = inputImg.at<Vec3b>(i, j)[2];
	//		imgBlue.at<uchar>(i, j) = 255 * pow(b / 255.0, rParameter);
	//		imgGreen.at<uchar>(i, j) = g;
	//		imgRed.at<uchar>(i, j) = r;
	//	}
	//}
	//mbgr[0] = imgBlue;
	//mbgr[1] = imgGreen;
	//mbgr[2] = imgRed;
	//merge(mbgr, outputImg);//�ϲ���ͨ�����ݵ�һ��ͼ��
	float rParameter = 0.1;
	Mat imgY, imgCb, imgCr, tempImg;
	tempImg = cv::Mat::zeros(inputImg.rows, inputImg.cols, CV_8UC3);
	cvtColor(inputImg, tempImg, CV_RGB2YCrCb);
	vector<Mat> mbgr(tempImg.channels());
	imgY = cv::Mat::zeros(tempImg.rows, tempImg.cols, CV_8UC1);
	imgCb = cv::Mat::zeros(tempImg.rows, tempImg.cols, CV_8UC1);
	imgCr = cv::Mat::zeros(tempImg.rows, tempImg.cols, CV_8UC1);
	for (int i = 0; i < tempImg.rows; i++)
	{
		for (int j = 0; j < tempImg.cols; j++)
		{
			float y = tempImg.at<Vec3b>(i, j)[0]/255.0;
			float cb = tempImg.at<Vec3b>(i, j)[1];
			float cr = tempImg.at<Vec3b>(i, j)[2];
			y=(float)log((float)y * (1.5 - 1) + 1) / log(1.5);
			y *= 255;
			int yi = y > 255 ? 255 : (y < 0 ? 0 : y);
			imgY.at<uchar>(i, j) = yi;
			imgCb.at<uchar>(i, j) = cb;
			imgCr.at<uchar>(i, j) = 255 * pow(cr / 255.0, 1.0);
		}
	}
	mbgr[0] = imgY;
	mbgr[1] = imgCb;
	mbgr[2] = imgCr;
	merge(mbgr, tempImg);//�ϲ���ͨ�����ݵ�һ��ͼ��
	cvtColor(tempImg, outputImg, CV_YCrCb2RGB);
}
#include"ImageProcessFilter.h"
//���ܣ����ټ����ۼƻ���ͼ
//���������unsigned char* inputMatrix,height,width
//���������unsigned long* outputMatrixSum
//����ֵ����
void fastIntegralMean(unsigned char* inputMatrix, unsigned long* outputMatrixSum, int height, int width)
{
	unsigned long *columnSum = new unsigned long[width]; // sum of each column  
	// calculate integral of the first line  
	for (int i = 0; i<width; i++){
		columnSum[i] = inputMatrix[i];
		outputMatrixSum[i] = inputMatrix[i];
		if (i>0){
			outputMatrixSum[i] += outputMatrixSum[i - 1];
		}
	}
	for (int i = 1; i<height; i++){
		int offset = i*width;
		// first column of each line  
		columnSum[0] += inputMatrix[offset];
		outputMatrixSum[offset] = columnSum[0];
		// other columns   
		for (int j = 1; j<width; j++){
			columnSum[j] += inputMatrix[offset + j];
			outputMatrixSum[offset + j] = outputMatrixSum[offset + j - 1] + columnSum[j];
		}
	}
	return;
}
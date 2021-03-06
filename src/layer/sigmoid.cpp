#include "sigmoid.h"
#include "config.h"

vector <Mat> Sigmoid::Activation() {
	int Size = input.size();
	int row = input[0].rows;
	int col = input[0].cols;
	vector <Mat> output;
	output.resize(Size);
	for (int i = 0; i < Size; i++) {
		Mat dest(row, col, CV_32FC1);
		Mat exp_x(row, col, CV_32FC1);
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				exp_x.at<float>(j, k) = exp(-input[i].at<float>(j, k));
			}
		}
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				dest.at<float>(j, k) = 1.0 / (1.0 + exp_x.at<float>(j, k));
			}
		}
		output[i] = dest;
	}
	return output;
}

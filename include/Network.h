#pragma once
#include <iostream>
#include <ctime>
#include <random>
#include <opencv2\opencv.hpp>
using namespace std;
using namespace cv;

class Net
{
public:
	//每一层的神经元数目
	vector <int> layer_neuron_num;
	//层，使用Opencv的Mat
	vector <Mat> layer;
	//权值矩阵
	vector <Mat> weights;
	//偏置矩阵
	vector <Mat> biases;
	//初始化策略
	//0表示[-1，1]随机初始化
	//1表示均值为GaussMean方差为GaussSigma的高斯初始化
	int InitType = 0;
	//高斯初始化的方差默认为1.0
	float GaussSigma = 1.0;
	//高斯初始化的均值默认为0
	float GaussMean = 0;
	//openmp线程数, 默认为1
	int openmp_num_threads = 1;
	//激活函数类型
	string activation_func = "sigmoid";
	//损失函数类型
	string loss_type = "L1";
	//定义损失函数的值
	float loss;
	//定义标签Mat
	Mat label;
	//前向传播的最后一层的输出，反向传播的起点
	Mat output_error;
	//损失函数对所有参数的梯度
	vector <Mat> delta;
	//根据去求取的梯度和学习率参数更新
	void UpdateParameters();
	//反向传播函数
	void backward();
	//学习率
	float learning_rate;
public:
	Net() {};
	~Net() {};
	//初始化网络
	void initNet(vector <int> layer_neuron_num_);
	//产生普通的随机数
	float *random_uniform(int length);
	//产生高斯分布随机数
	float *random_gaussian(int length);
	//初始化权重
	void initWeights();
	//初始化偏置
	void initBiases();
	//设置网络运行的线程数
	void SetThreads(int num);
	//初始化每层Layer激活函数类型
	void SetActivation(string input);
	//前向传播
	void forward();
	//反向传播求梯度（链式法则）
	void getGrad();
};
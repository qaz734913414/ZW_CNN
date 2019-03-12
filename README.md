﻿# 介绍
大家好，这是我和XiwoWu用C++开发的一个用OpenCV中的Mat作为基础数据结构的的CNN，目标是利用多线程技术，指令集优化技术打造一个在PC端的CPU上运行的快速卷积神经网络，并完全开放源码，欢迎大家STAR或者加入QQ群与我们一起讨论开发CNN或计算机视觉相关的算法问题。
# 依赖
- OpenCV 2.4.13 可以使用tools下面的csv2xml_opencv2.4.13.cpp转换。
- OpenCV 3.4.0  因为OpenCV3存在一个读取csv转Mat的BUG，会导致读取CSV少一行，可以使用OpenCV2.4.13或者使用Python转换。
# 目录
- include 实现神经网络的头文件。
- src 实现神经网络的源码。
- data 保存了Mnist数据集的xml文件，通过tools下的工具从csv文件转换过来。
- tools 实现了csv文件和xml文件转换，训练，测试工具。
- examples 训练MNIST手写数据集的例子。
- benchmark 一些测试结果记录。
# 训练

- 运行examples下面的train.cpp进行训练和模型保存

# 测试

- 运行examples下面的test.cpp加载模型并测试

# 开发历程
- 2019.3.3 构造神经网络的基础部分，在Net.h中定义Net类和神经网络的基础结构，开始实现initNet()初始化神经网络的函数。Done!
- 2019.3.3 实现初始化方式的时候发现应该给权重和偏置赋初始值，这里需要实现2个函数，并且考虑到不同的初始值对神经网络训练出的模型的准确率会有影响，因此考虑实现随机小数赋值和正态分布赋值。Done!
- 2019.3.4 实现随机小数赋值和正态分布赋值，并实现初始化权值weights和偏置biases。Done!
- 2019.3.4 测试神经网络初始化函数。Done！
- 2019.3.4 实现Sigmoid激活函数前向和反向求导。Done!
- 2019.3.4 实现Tanh激活函数前向和反向求导。Done!
- 2019.3.4 增加Openmp多线程支持。Done!
- 2019.3.5 实现ReLU激活函数的前向和反向求导。Done!
- 2019.3.5 开始实现前向传播forward。Done!
- 2019.3.5 开始考虑Loss损失函数的计算方法。Done!
- 2019.3.6 开始实现反向传播部分。Done!
- 2019.3.7 开始实现神经网络训练部分。Done!
- 2019.3.9 开始实现神经网络的测试部分。Done!
- 2019.3.9 开始实现神经网络的模型保存和测试部分。Done!
- 2019.3.10 开始实现xml和csv转换工具。Done!

- 2019.3.10 开始实现对MInst手写数距的训练。Done!

- 2019.3.11 开始修复一个调用类的Public函数的BUG。Done!

# QQ群
- 663852348
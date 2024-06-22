import cv2
import math
import os
import struct

import matplotlib.pyplot as plt
import numpy as np
from skimage.feature import hog
from sklearn import datasets
from sklearn.svm import LinearSVC
import joblib
import sklearn.metrics as metrics

# %matplotlib inline
# %config InlinBackend figure format="retina"
plt.rcParams['font.sans-serif'] = ['SimHei']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号


# 读数据
def load_mnist(path, labelfile, datafile):
    labels_path = os.path.join(path, labelfile)
    images_path = os.path.join(path, datafile)
    with open(labels_path, 'rb') as lbpath:
        magic, n = struct.unpack('>II', lbpath.read(8))
        labels = np.fromfile(lbpath, dtype=np.uint8)
    with open(images_path, 'rb') as imgpath:
        magic, num, rows, cols = struct.unpack(">IIII", imgpath.read(16))
        images = np.fromfile(imgpath, dtype=np.uint8).reshape(len(labels), 784)
    return images, labels


# 读训练集
features0, labels0 = load_mnist("./mnist", "train-labels-idx1-ubyte", "train-images-idx3-ubyte")
features = features0[0:6000, :]  # 仅使用前6000张图片
labels = labels0[0:6000]

# 读测试集
testfeatures0, testlabels0 = load_mnist("./mnist", "t10k-labels-idx1-ubyte", "t10k-images-idx3-ubyte")
testfeatures = testfeatures0[0:10000, :]  # 仅使用前10000张图片
testlabels = testlabels0[0:10000]

# print("训练集行数：%d, 列数：%d" % (features.shape[0], features.shape[1]))
# x = np.array(features[0, :])  # 提取第一行数据
# x = x.reshape([28, 28])
# 显示第一张图片
# plt.imshow(x, cmap="gray_r")
# plt.show()

# 提取训练集HOG特征
list_hog_fd = []
for feature in features:
    fd = hog(feature.reshape((28, 28)),  # 提取HOG特征
             orientations=9,
             pixels_per_cell=(14, 14),
             cells_per_block=(1, 1),
             visualize=False)
    list_hog_fd.append(fd)
hog_features = np.array(list_hog_fd, 'float64')
# print(hog_features.shape)

# 提取测试集HOG特征
list_hog_tfd = []
for testfeature in testfeatures:
    tfd = hog(testfeature.reshape((28, 28)),  # 提取HOG特征
              orientations=9,
              pixels_per_cell=(14, 14),
              cells_per_block=(1, 1),
              visualize=False)
    list_hog_tfd.append(tfd)
hog_testfeatures = np.array(list_hog_tfd, 'float64')

# 使用SVM支持向量机分类器进行分类
# 建立并训练SVM模型
svm_model = LinearSVC()  # 建立SVM模型
svm_model.fit(hog_features, labels)  # 训练SVM模型

# 测试SVM模型测试单个图像，输出结果为图像所属类别
testnumber = svm_model.predict(hog_testfeatures)
SVMscore = svm_model.score(hog_testfeatures, testlabels)
# print("测试集第一个图像数字是:", testnumber[0])
# print("HOG+SVM分类精度:", SVMscore)  # 平均分类精度


print("---------混淆矩阵------------")
print(metrics.confusion_matrix(testlabels, testnumber))  # 混淆矩阵
print("--------分类评估报告----------")
print(metrics.classification_report(testlabels, testnumber))

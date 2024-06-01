import torch
import torch.nn as nn
import torch.optim as optim
import os
import struct
import numpy as np
from torch.utils.data import DataLoader, TensorDataset
import tkinter as tk
from tkinter import Canvas
from PIL import Image, ImageDraw
from tkinter import messagebox


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
features0, labels0 = load_mnist("./MNIST", "train-labels-idx1-ubyte", "train-images-idx3-ubyte")
features = features0[0:10000, :]  # 仅使用前10000张图片
labels = labels0[0:10000]

# 读测试集
testfeatures0, testlabels0 = load_mnist("./MNIST", "t10k-labels-idx1-ubyte", "t10k-images-idx3-ubyte")
testfeatures = testfeatures0[0:10000, :]  # 仅使用前10000张图片
testlabels = testlabels0[0:10000]

# 转为torch.Tensor
features = torch.tensor(features, dtype=torch.float32) / 255.0  # 归一化
labels = torch.tensor(labels, dtype=torch.long)
testfeatures = torch.tensor(testfeatures, dtype=torch.float32) / 255.0  # 归一化
testlabels = torch.tensor(testlabels, dtype=torch.long)

# 定义数据加载器
batch_size = 128
train_dataset = TensorDataset(features, labels)
test_dataset = TensorDataset(testfeatures, testlabels)
train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
test_loader = DataLoader(test_dataset, batch_size=batch_size, shuffle=False)

# 定义模型
class BPNetwork(nn.Module):
    def __init__(self):
        super(BPNetwork, self).__init__()
        # 神经网络模型结构
        self.fc1 = nn.Linear(784, 256) 
        self.fc2 = nn.Linear(256, 128)
        self.fc3 = nn.Linear(128, 64)
        self.fc4 = nn.Linear(64, 10)
        self.dropout = nn.Dropout(0.20)  # 添加Dropout层,防止过拟合
    
    def forward(self, x):# 向前传播
        x = torch.relu(self.fc1(x))
        x = self.dropout(x)
        x = torch.relu(self.fc2(x))
        x = self.dropout(x)
        x = torch.relu(self.fc3(x))
        x = self.dropout(x)
        x = self.fc4(x)
        return x

model = BPNetwork()

# 定义误差函数和优化器
criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)  # 使用Adam优化器

# 训练模型
num_epochs = 30  # 训练轮数
for epoch in range(num_epochs):
    model.train()
    running_loss = 0.0
    for inputs, targets in train_loader:
        optimizer.zero_grad()
        outputs = model(inputs) # 向前传播
        loss = criterion(outputs, targets)
        loss.backward()  # 反向传播
        optimizer.step()  
        running_loss += loss.item()
    print(f'Epoch [{epoch+1}/{num_epochs}], Loss: {running_loss/len(train_loader):.4f}')

# 测试模型
model.eval()
correct = 0
total = 0
with torch.no_grad():
    for inputs, targets in test_loader:
        outputs = model(inputs)
        _, predicted = torch.max(outputs.data, 1)
        total += targets.size(0)
        correct += (predicted == targets).sum().item()
print(correct,total)
print(f'Accuracy of the model on the test images: {100 * correct / total:.2f}%')
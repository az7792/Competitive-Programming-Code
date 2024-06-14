import torch
import torch.nn as nn
import torch.optim as optim
import os
import struct
import numpy as np
from torch.utils.data import DataLoader, TensorDataset
import torch.nn.functional as F

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

# 定义卷积神经网络
class CNN(nn.Module):
    def __init__(self):
        super(CNN, self).__init__()
        self.conv1 = nn.Conv2d(in_channels=1, out_channels=16, kernel_size=3, padding=1)
        self.conv2 = nn.Conv2d(in_channels=16, out_channels=32, kernel_size=3, padding=1)
        self.pool = nn.MaxPool2d(kernel_size=2, stride=2)
        self.fc1 = nn.Linear(32 * 7 * 7, 128)
        self.fc2 = nn.Linear(128, 10)

    def forward(self, x):
        x = self.pool(F.relu(self.conv1(x)))
        x = self.pool(F.relu(self.conv2(x)))
        x = x.view(-1, 32 * 7 * 7)
        x = F.relu(self.fc1(x))
        x = self.fc2(x)
        return x

# 实例化模型
model = CNN()

# 定义损失函数和优化器
criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)

# 训练模型
num_epochs = 5
for epoch in range(num_epochs):
    model.train()
    running_loss = 0.0
    for i, (inputs, labels) in enumerate(train_loader):
        optimizer.zero_grad()
        outputs = model(inputs.view(-1, 1, 28, 28))
        loss = criterion(outputs, labels)
        loss.backward()
        optimizer.step()
        running_loss += loss.item()
        if (i+1) % 10 == 0:
            print(f"第 [{epoch+1}/{num_epochs}] 轮, 第 [{i+1}/{len(train_loader)}] 步, 损失: {running_loss / 100:.4f}")

# 评估模型
model.eval()
correct = 0
total = 0
with torch.no_grad():
    for inputs, labels in test_loader:
        outputs = model(inputs.view(-1, 1, 28, 28))
        _, predicted = torch.max(outputs.data, 1)
        total += labels.size(0)
        correct += (predicted == labels).sum().item()

accuracy = correct / total
print(f"在测试集上的准确率: {100 * accuracy:.2f}%")
import numpy as np

# 创建一个 3x3 的数组
shape = [10,10]
pxy = np.array([[0, 1, 0], [1, -4, 1], [0, 1, 0]])#约束矩阵
xLen,yLen = (shape[0] - pxy.shape[0])//2,(shape[1] - pxy.shape[1])//2
puv = np.pad(pxy, ((xLen, shape[0]-pxy.shape[0]-xLen), (yLen, shape[1]-pxy.shape[1]-yLen)))


print(puv)
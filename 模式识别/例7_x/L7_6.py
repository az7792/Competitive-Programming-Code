import cv2
import numpy as np
import matplotlib.pyplot as plt

#原图
inImg = cv2.imread('hole.jpg', cv2.IMREAD_GRAYSCALE)
#二值化
_, binaryImg = cv2.threshold(inImg, 127, 255, cv2.THRESH_BINARY)

binaryImg_ct = cv2.bitwise_not(binaryImg)#binaryImg的补集

X = np.zeros(binaryImg.shape,dtype=np.uint8)
where = np.where(binaryImg == 255)

X[where[0][0]][where[1][0]]=255

#核
kernel = np.array([[0, 255, 0], [255, 255, 255], [0, 255, 0]], dtype=np.uint8)

#使用形态学填充背景
ok = 0
while ok==0:
    Xp = X
    X = cv2.dilate(X,kernel) & binaryImg_ct
    if np.array_equal(X,Xp):
        ok = 1

#将背景取反与原二值图求并
res = (~X) | binaryImg

plt.figure(figsize=(6, 3))
plt.subplot(121), plt.title("inImg"), plt.axis('off'), plt.imshow(inImg, 'gray')
plt.subplot(122), plt.title("res"), plt.axis('off'), plt.imshow(res, 'gray')
plt.show()
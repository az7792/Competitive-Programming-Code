import cv2
import numpy as np
import matplotlib.pyplot as plt

#原图
inImg = cv2.imread('mask2.jpg', cv2.IMREAD_GRAYSCALE)
#二值化
_, binaryImg = cv2.threshold(inImg, 127, 255, cv2.THRESH_BINARY)

plt.figure(figsize=(11, 3))
plt.subplot(151), plt.title("inImg"), plt.axis('off'), plt.imshow(inImg, 'gray')

#结构元素
kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(30,30))

#腐蚀
res = cv2.erode(binaryImg,kernel,1)
plt.subplot(152), plt.title("erode"), plt.axis('off'), plt.imshow(res, 'gray')

#膨胀
res = cv2.dilate(binaryImg,kernel,1)
plt.subplot(153), plt.title("dilate"), plt.axis('off'), plt.imshow(res, 'gray')

#开运算
res = cv2.morphologyEx(binaryImg,cv2.MORPH_OPEN,kernel)
plt.subplot(154), plt.title("OPEN"), plt.axis('off'), plt.imshow(res, 'gray')

#闭运算
res = cv2.morphologyEx(binaryImg,cv2.MORPH_CLOSE,kernel)
plt.subplot(155), plt.title("CLOSE"), plt.axis('off'), plt.imshow(res, 'gray')
plt.show()
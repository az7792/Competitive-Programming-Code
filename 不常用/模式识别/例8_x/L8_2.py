import cv2
import numpy as np
import matplotlib.pyplot as plt

#原图
inImg = cv2.cvtColor(cv2.imread('coin.jpg'), cv2.COLOR_BGR2RGB)
#二值化
_, binaryImg = cv2.threshold(cv2.cvtColor(inImg, cv2.COLOR_RGB2GRAY), 0, 255, cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)

#开运算去噪
kernel = np.ones((3,3),np.uint8)
openImg = cv2.morphologyEx(binaryImg,cv2.MORPH_OPEN,kernel,1)

bgImg = cv2.dilate(openImg,kernel,3)#背景

dist_transform = cv2.distanceTransform(openImg,cv2.DIST_L2,5)
_,fgImg = cv2.threshold(dist_transform,0.7*dist_transform.max(),255,0)#前景

fgImg = np.uint8(fgImg)
unknown = cv2.subtract(bgImg,fgImg)

_,markers = cv2.connectedComponents(fgImg)
markers = markers + 1
markers[unknown==255]=0

plt.figure(figsize=(12, 3))
plt.subplot(143), plt.title("markers"), plt.axis('off'), plt.imshow(markers, 'gray')


markers = cv2.watershed(inImg,markers)
res = np.copy(inImg)
res[markers==-1]=[255,0,0]

plt.subplot(141), plt.title("inImg"), plt.axis('off'), plt.imshow(inImg, 'gray')
plt.subplot(142), plt.title("fgImg"), plt.axis('off'), plt.imshow(fgImg, 'gray')
plt.subplot(144), plt.title("res"), plt.axis('off'), plt.imshow(res, 'gray')

plt.show()
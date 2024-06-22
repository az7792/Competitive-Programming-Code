import cv2
import numpy as np
import matplotlib.pyplot as plt

#原图
inImg = cv2.imread('wirebond-mask.jpg', cv2.IMREAD_GRAYSCALE)
#二值化
_, binaryImg = cv2.threshold(inImg, 127, 255, cv2.THRESH_BINARY)

size = [11,15,45]
res = [None]*3 #结果
for i in range(3):
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT,(size[i],size[i]))
    res[i] = cv2.erode(binaryImg,kernel,1)

plt.figure(figsize=(11, 3))
plt.subplot(141), plt.title("inImg"), plt.axis('off'), plt.imshow(binaryImg, 'gray')
plt.subplot(142), plt.title("11*11"), plt.axis('off'), plt.imshow(res[0], 'gray')
plt.subplot(143), plt.title("15*15"), plt.axis('off'), plt.imshow(res[1], 'gray')
plt.subplot(144), plt.title("45*45"), plt.axis('off'), plt.imshow(res[2], 'gray')
plt.show()
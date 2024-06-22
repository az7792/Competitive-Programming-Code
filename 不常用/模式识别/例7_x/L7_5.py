import cv2
import numpy as np
import matplotlib.pyplot as plt

#原图
inImg = cv2.imread('mapleleaf.jpg', cv2.IMREAD_GRAYSCALE)
#二值化
_, binaryImg = cv2.threshold(inImg, 127, 255, cv2.THRESH_BINARY)

size = [3,9,15]
res = [None]*3 #结果
for i in range(3):
    kernel = cv2.getStructuringElement(cv2.MORPH_RECT,(size[i],size[i]))
    res[i] = cv2.morphologyEx(binaryImg,cv2.MORPH_GRADIENT,kernel)
    #res[i] = cv2.dilate(binaryImg,kernel,1) - cv2.erode(binaryImg,kernel,1)
    #res[i] = binaryImg - cv2.erode(binaryImg,kernel,1)

plt.figure(figsize=(11, 3))
plt.subplot(141), plt.title("inImg"), plt.axis('off'), plt.imshow(inImg, 'gray')
plt.subplot(142), plt.title("3*3"), plt.axis('off'), plt.imshow(res[0], 'gray')
plt.subplot(143), plt.title("9*9"), plt.axis('off'), plt.imshow(res[1], 'gray')
plt.subplot(144), plt.title("15*15"), plt.axis('off'), plt.imshow(res[2], 'gray')
plt.show()
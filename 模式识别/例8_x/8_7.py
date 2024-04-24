import cv2
import numpy as np
import matplotlib.pyplot as plt

#原图
inImg1 = cv2.imread('moving_threshold.jpg',cv2.IMREAD_GRAYSCALE)
inImg2 = cv2.imread('light_bar.png',cv2.IMREAD_GRAYSCALE)

def movingThreshold(img, n, b):
        shape = img.shape
        img[1:img.shape[0]:2, :] = np.fliplr(img[1:img.shape[0]:2, :])  #翻转奇数行
        img = img.flatten()  #展平为一维
        img = img.reshape(len(img),1)
        kernel = np.ones((n,1))/n #卷积核

        aaa = cv2.filter2D(img,-1,kernel)#卷积运算

        res = np.array(img>aaa*b).astype(np.uint8)#大于阈值的为1
        res = res.reshape(shape)     

        res[1:res.shape[0]:2, :] = np.fliplr(res[1:res.shape[0]:2, :])  #翻转奇数行
        return res*255 #[0,1]->[0,255]


res1 = movingThreshold(np.copy(inImg1),25,0.93)
res2 = movingThreshold(np.copy(inImg2),13,0.93)

plt.figure(figsize=(7, 6))
plt.subplot(221), plt.title("moving_threshold"), plt.axis('off'), plt.imshow(inImg1, 'gray')
plt.subplot(223), plt.title("light_bar"), plt.axis('off'), plt.imshow(inImg2, 'gray')
plt.subplot(222), plt.title("moving_threshold_res"), plt.axis('off'), plt.imshow(res1, 'gray')
plt.subplot(224), plt.title("light_bar_res"), plt.axis('off'), plt.imshow(res2, 'gray')

plt.show()
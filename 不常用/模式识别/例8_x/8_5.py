import cv2
import numpy as np
import matplotlib.pyplot as plt

#原图
inImg = cv2.imread('paopao.jpg',cv2.IMREAD_GRAYSCALE)

def globalThreshold(img):
    threshold = np.mean(img)#阈值
    max_iterations = 100 #最大迭代步数

    for i in range(max_iterations):        
        #计算前后景的灰度均值
        fgMean = np.mean(img[img > threshold])
        bgMean = np.mean(img[img <= threshold])
        
        # 计算新的阈值
        newThreshold = (fgMean+bgMean) / 2
        
        # 如果收敛则停止迭代
        if abs(newThreshold - threshold) < 0.5:
            break
        
        threshold = newThreshold
    
    _, res = cv2.threshold(img, threshold, 255, cv2.THRESH_BINARY)#居于当前阈值将图像分割为前后景
    return res   


res = globalThreshold(np.copy(inImg))

plt.figure(figsize=(7, 6))
plt.subplot(121), plt.title("paopao"), plt.axis('off'), plt.imshow(inImg, 'gray')
plt.subplot(122), plt.title("paopao_res"), plt.axis('off'), plt.imshow(res, 'gray')
plt.show()
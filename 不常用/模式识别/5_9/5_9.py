import cv2
import random
import numpy as np
import matplotlib.pyplot as plt
def getMotionPSF(shape, angle, dist):#生成指定大小的方向的点扩散函数
    xCenter = shape[0] // 2
    yCenter = shape[1] // 2
    sinTheta = np.sin(angle / 180 * np.pi)
    cosTheta = np.cos(angle / 180 * np.pi)

    PSF = np.zeros(shape)
    for i in range(dist):  #遍历斜边,将对应角度边上dist个点置成1
        x = round(sinTheta * i)
        y = round(cosTheta * i)
        if 0 <= xCenter - x <PSF.shape[0] and 0 <= yCenter + y <PSF.shape[1]:
            PSF[xCenter - x, yCenter + y] = 1
        else:
            break
    return PSF / PSF.sum() #归一化

def getMotionBlurImg(image,PSF):#将模糊函数作用于图像上
    #傅里叶变换
    fftImg = np.fft.fft2(image)
    fftPSF = np.fft.fft2(PSF)
    #逆傅里叶变换
    fftBlur = np.fft.ifft2(fftImg * fftPSF)
    return np.abs(np.fft.fftshift(fftBlur))

def getPuv(shape,pxy): #将约束矩阵扩展到与图像相同大小
    xLen,yLen = (shape[0] - pxy.shape[0])//2,(shape[1] - pxy.shape[1])//2
    puv = np.pad(pxy, ((xLen, shape[0]-pxy.shape[0]-xLen), (yLen, shape[1]-pxy.shape[1]-yLen)))
    return np.fft.fft2(puv)

def leastSquareFilter(image, PSF, var, gamma, pxy):#有约束最小二乘滤波
    fftImg = np.fft.fft2(image) #G(u,v)
    fftPSF = np.fft.fft2(PSF) #H(u,v)
    fftPuv = getPuv(image.shape,pxy) #P(u,v)
    #fftPSF.conj() #共轭 H*(u,v)

    Fuv = np.fft.ifft2((fftPSF.conj() / (np.abs(fftPSF)**2 + gamma * (np.abs(fftPuv)**2)))*fftImg)
    Fuv = np.abs(np.fft.fftshift(Fuv))

    return np.uint8(cv2.normalize(Fuv,None,0,255,cv2.NORM_MINMAX))#像数值归一化到[0, 255]
    

#原图
inImg = cv2.imread('image_5_9.jpg', cv2.IMREAD_GRAYSCALE)

#运动模糊图像
PSF = getMotionPSF(inImg.shape, 60, 70)  #运动模糊函数
motionBlurImg = getMotionBlurImg(inImg,PSF) #生成运动模糊图像

#高斯噪声图像
var = 10 #噪声方差
gaussImg = cv2.add(motionBlurImg, np.random.normal(0, var, motionBlurImg.shape).astype(motionBlurImg.dtype))

pxy = np.array([[0, 1, 0], [1, -4, 1], [0, 1, 0]])#约束矩阵
LSFImg = leastSquareFilter(gaussImg, PSF, var,0.1,pxy)  # 约束最小二乘方滤波

plt.figure(figsize=(11, 3))
plt.subplot(141), plt.title("inImg"), plt.axis('off'), plt.imshow(inImg, 'gray')
plt.subplot(142), plt.title("motionBlurImg"), plt.axis('off'), plt.imshow(motionBlurImg, 'gray')
plt.subplot(143), plt.title("gaussImg"), plt.axis('off'), plt.imshow(gaussImg, 'gray')
plt.subplot(144), plt.title("outImg"), plt.axis('off'), plt.imshow(LSFImg, 'gray')
plt.show()

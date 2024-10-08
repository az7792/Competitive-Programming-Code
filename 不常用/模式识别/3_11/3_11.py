import cv2
import random
import numpy as np

inImg = cv2.imread('image.png', cv2.IMREAD_GRAYSCALE)

op = '11'
# 噪声 0:高斯噪声 1:椒盐噪声
# 滤波 0:均值滤波 1:中值滤波

if op[0] == '0':
    # 高斯噪声
    gauss = np.random.normal(0, 1, inImg.shape).astype(np.uint8)
    img = cv2.add(inImg, gauss)
    cv2.imwrite('Gaussian.png', img)
elif op[0] == '1':
    # 椒盐噪声
    def salt_pepper_noise(image: np.ndarray, prob=0.01):
        for i in range(image.shape[0]):
            for j in range(image.shape[1]):
                if random.random() < prob:
                    image[i][j] = 0 if random.random() < 0.5 else 255
                else:
                    image[i][j] = image[i][j]
        return image


    img = salt_pepper_noise(inImg)
    cv2.imwrite('Salt&Pepper.png', img)

image = np.zeros((img.shape[0], img.shape[1]), dtype=np.uint8)

if op[1] == '0':
    # 均值滤波
    w = np.array([[1 / 9, 1 / 9, 1 / 9],
                  [1 / 9, 1 / 9, 1 / 9],
                  [1 / 9, 1 / 9, 1 / 9]])
    for x in range(img.shape[0]):
        for y in range(img.shape[1]):
            tmp = 0
            for i in range(w.shape[0]):
                for j in range(w.shape[1]):
                    X, Y = x - w.shape[0] // 2 + i, y - (w.shape[1] // 2) + j
                    if X < 0 or Y < 0 or X >= img.shape[0] or Y >= img.shape[1]:
                        tmp += 0
                    else:
                        tmp += w[i][j] * img[X][Y]
            image[x][y] = int(round(tmp))
    cv2.imwrite('Mean.png', image)
elif op[1] == '1':
    # 中值滤波
    # image = cv2.medianBlur(img,3)
    W1, W2 = 3, 3
    for x in range(img.shape[0]):
        for y in range(img.shape[1]):
            tmp = []
            for i in range(W1):
                for j in range(W2):
                    X, Y = x - W1 // 2 + i, y - W2 // 2 + j
                    if X < 0 or Y < 0 or X >= img.shape[0] or Y >= img.shape[1]:
                        tmp.append(0)
                    else:
                        tmp.append(img[X][Y])
            tmp = sorted(tmp)
            image[x][y] = int(tmp[len(tmp) // 2])
    cv2.imwrite('Median.png', image)

# 算子 0:Roberts算子 1:Prewitt算子 2:Sobel算子
for xx in range(3):
    if xx == 0:
        # Roberts算子
        dx = np.array([[-1, 0], [0, 1]], dtype=int)
        dy = np.array([[0, -1], [1, 0]], dtype=int)
    elif xx == 1:
        # Prewitt算子
        dx = np.array([[1, 0, -1], [1, 0, -1], [1, 0, -1]], dtype=int)
        dy = np.array([[-1, -1, -1], [0, 0, 0], [1, 1, 1]], dtype=int)
    elif xx == 2:
        # Sobel算子
        dx = np.array([[1, 0, -1], [2, 0, -2], [1, 0, -1]], dtype=int)
        dy = np.array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]], dtype=int)

    # DX = cv2.filter2D(image,-1,dx)
    # DY = cv2.filter2D(image,-1,dy)
    # NewImg = abs(DX) + abs(DY)

    NewImg = np.zeros((image.shape[0], image.shape[1]), dtype=int)
    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            Dx, Dy = 0, 0
            for x in range(dx.shape[0]):
                for y in range(dx.shape[1]):
                    if i + x >= image.shape[0] or j + y >= image.shape[1]:
                        Dx += 0
                        Dy += 0
                    else:
                        Dx += dx[x][y] * image[i + x][j + y]
                        Dy += dy[x][y] * image[i + x][j + y]
            NewImg[i][j] = abs(Dx) + abs(Dy)

    str0 = 'Gaussian_' if op[0] == '0' else 'Salt&Pepper_'
    str1 = 'Mean_' if op[1] == '0' else 'Median_'
    str2 = 'Roberts' if xx == 0 else ('Prewitt' if xx == 1 else 'Sobel')
    cv2.imwrite(str0 + str1 + str2 + '.png', NewImg)

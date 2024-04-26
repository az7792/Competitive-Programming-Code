import cv2
import random
import numpy as np
import matplotlib.pyplot as plt

image = np.array(  [[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
                    [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
                    [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
                    [1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1],
                    [1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1],
                    [1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1],
                    [1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1],
                    [1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1],
                    [1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1],
                    [1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1],
                    [1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1],
                    [1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1],
                    [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
                    [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
                    [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1],
                    [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]],dtype=np.uint8)

image = image ^ 1

# 计算面积
area = cv2.countNonZero(image)

# 计算轮廓
contours, _ = cv2.findContours(image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
contour = contours[0]

# 计算周长
perimeter = cv2.arcLength(contour, True)

# 计算质心
M = cv2.moments(image) 
centroid_x = int(M['m10'] / M['m00'])
centroid_y = int(M['m01'] / M['m00'])

# 计算最小外接矩形
x, y, w, h = cv2.boundingRect(contour)

# 计算圆形度
circularity = 4 * np.pi * area / (perimeter * perimeter)

# 计算矩形度
rectangularity = area / (w * h)

# 计算长宽比
aspect_ratio = w / h


print("面积:", area)
print("周长:", perimeter)
print("质心:", (centroid_x, centroid_y))
print("圆形度:", circularity)
print("矩形度:", rectangularity)
print("长宽比:", aspect_ratio)


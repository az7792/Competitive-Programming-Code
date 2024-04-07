import numpy as np
import math
import cv2

def draw_line(matrix, angle_degrees):
    n = len(matrix)
    center = n // 2  # 计算中心点坐标
    angle_radians = math.radians(angle_degrees)  # 将角度转换为弧度

    # 计算直线的起点和终点坐标
    start_x = center + (center * math.cos(angle_radians))
    start_y = center + (center * math.sin(angle_radians))
    end_x = center - (center * math.cos(angle_radians))
    end_y = center - (center * math.sin(angle_radians))

    # 使用 Bresenham 直线算法绘制直线
    x0, y0, x1, y1 = int(start_x), int(start_y), int(end_x), int(end_y)
    dx = abs(x1 - x0)
    dy = abs(y1 - y0)
    sx = 1 if x0 < x1 else -1
    sy = 1 if y0 < y1 else -1
    err = dx - dy

    while x0 != x1 or y0 != y1:
        matrix[y0][x0] = 1
        e2 = 2 * err
        if e2 > -dy:
            err -= dy
            x0 += sx
        if e2 < dx:
            err += dx
            y0 += sy
    matrix[y1][x1] = 1  # 绘制终点

# 创建一个矩阵
matrix = np.zeros((9,9),dtype=int)

# 画一条直线
draw_line(matrix, -60)

# 打印结果
#print(matrix)
#cv2.imwrite('line.png', matrix)
oneNum = np.sum(matrix)
print('np.array(',end='[')
for i in range(matrix.shape[0]):  
    print(end='[')  
    for j in range(matrix.shape[1]):    
        if matrix[i][j]==1:
            print(matrix[i][j]/oneNum,end='')
        else:
            print(matrix[i][j],end='')
        if j < matrix.shape[1] - 1:
            print(end=',')
    print(end=']')
    if i < matrix.shape[0] - 1:
        print(",")
print("],dtype=np.float32)")
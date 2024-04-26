import cv2
import random
import numpy as np
import matplotlib.pyplot as plt

image = np.array(  [[0,0,0,0,1,1],
                    [0,0,0,0,1,1],
                    [0,0,0,0,1,1],
                    [0,0,0,0,1,1],
                    [2,2,2,2,3,3],
                    [2,2,2,2,3,3]])


P = np.zeros((4,4),dtype=int)
for x in range(image.shape[0]):
    for y in range(image.shape[1]):
        #x+1 y-1 or x-1 y+1
        if 0<=x+1<image.shape[0] and 0<=y-1<image.shape[1]:
            P[image[x][y]][image[x+1][y-1]]+=1
        if 0<=x-1<image.shape[0] and 0<=y+1<image.shape[1]:
            P[image[x][y]][image[x-1][y+1]]+=1

print(P)


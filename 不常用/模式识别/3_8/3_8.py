import numpy as np
import cv2

image = np.array([[1,1,1,1,3],
                  [1,1,1,3,7],
                  [1,1,3,7,7],
                  [1,3,7,1,7],
                  [3,7,7,7,7]])

w = np.array([[1/9,1/9,1/9],
              [1/9,1/9,1/9],
              [1/9,1/9,1/9]])

W = np.ones((3,3),dtype=int)

Image = cv2.blur(image,(3,3),borderType=cv2.BORDER_CONSTANT)

def Bget(x,y):
     if x<0 or y<0 or x>=image.shape[0] or y>=image.shape[1]:
          return 0
     else:
          return image[x][y]

def Mget(x,y):
     if x<0 or y<0 or x>=image.shape[0] or y>=image.shape[1]:
          return 0
     else:
          return image[x][y]

Bimage = np.zeros((image.shape[0],image.shape[1]),dtype=int)
Mimage = np.zeros((image.shape[0],image.shape[1]),dtype=int)

for x in range(image.shape[0]):
     for y in range(image.shape[1]):
          tmp = 0          
          for i in range(w.shape[0]):
               for j in range(w.shape[1]):
                    tmp += w[i][j] * Bget(x-(w.shape[0]//2)+i,y-(w.shape[1]//2)+j)
          Bimage[x][y]= int(round(tmp))

for x in range(image.shape[0]):
     for y in range(image.shape[1]):
          tmp = []          
          for i in range(W.shape[0]):
               for j in range(W.shape[1]):
                    if W[i][j]==1:
                         tmp.append(Mget(x-(w.shape[0]//2)+i,y-(w.shape[1]//2)+j))
          tmp = sorted(tmp)
          Mimage[x][y]= int(tmp[len(tmp)//2])


#print(image)
#print(Image)
print(Bimage)
print(Mimage)


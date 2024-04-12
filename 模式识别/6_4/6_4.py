import numpy as np

arr = np.array([[1,3,7,3],[2,6,0,6],[8,2,6,5],[9,2,6,0]])

horizontally = np.zeros((arr.shape))
vertically=np.zeros((arr.shape))
horizontallyAndVertically=np.zeros((arr.shape))

for i in range(arr.shape[0]):
    for j in range(arr.shape[1]):
        horizontally[i][j] = arr[i][arr.shape[1]-j-1]

for i in range(arr.shape[0]):
    for j in range(arr.shape[1]):
        vertically[i][j] = arr[arr.shape[0]-i-1][j]

for i in range(arr.shape[0]):
    for j in range(arr.shape[1]):
        horizontallyAndVertically[i][j] = arr[arr.shape[0]-i-1][arr.shape[1]-j-1]

print(horizontally)
print(vertically)
print(horizontallyAndVertically)
import random
import math
import time
import matplotlib.pyplot as plt
import matplotlib
n = 19#结点个数
w = [[0 for j in range(n)] for i in range(n)]#wij 点i与点j的权重
b = [0 for j in range(n)]#偏置
l = 0.1#学习率

def BPNN4(train,f):#f0 训练 f1预测
    o = [0 for i in range(n)]
    e = [0 for i in range(n)]
    s = [0 for i in range(n)]
    E = [0,0,0]#误差
    for i in range(4):
        o[i]=train[i]
    sc = train[4:]#真实值
    # 前向传播
    for i in range(4,11):#1 到 2
        for j in range(0,4):
            s[i] += o[j]*w[j][i]
        s[i] += b[0]
        o[i] = 1/(1+math.exp(-s[i]))

    for i in range(11,16):#2 到 3
        for j in range(4,11):
            s[i] += o[j]*w[j][i]
        s[i] += b[0]
        o[i] = 1/(1+math.exp(-s[i]))

    for i in range(16,19):#3 到 4
        for j in range(11,16):
            s[i] += o[j]*w[j][i]
        s[i] += b[0]
        o[i] = 1/(1+math.exp(-s[i]))
        e[i] = o[i]*(1-o[i])*(o[i]-sc[i-16])
        E[i-16] = 0.5*(sc[i-16]-o[i])*(sc[i-16]-o[i])
    if f == 1:#仅预测
        return E[0]+E[1]+E[2],o[16],o[17],o[18]
# 反向传播
    for i in range(11,16):
        for j in range(16,19):
            e[i]=w[i][j]*e[j]
        e[i] = e[i] * o[i]*(1-o[i])

    for i in range(4,11):
        for j in range(11,16):
            e[i]=w[i][j]*e[j]
        e[i] = e[i] * o[i]*(1-o[i])
    # 更新权重
    for i in range(0,4):
        for j in range(4,11):
            w[i][j]=w[i][j]-l*e[j]*o[i]
    for i in range(4,11):
        for j in range(11,16):
            w[i][j]=w[i][j]-l*e[j]*o[i]
    for i in range(11,16):
        for j in range(16,19):
            w[i][j]=w[i][j]-l*e[j]*o[i]
    #更新偏置
    for i in range(4,19):
        b[i] = b[i] - l*e[i]
    return E[0]+E[1]+E[2],o[16],o[17],o[18]

#随机初始化权重和偏置
def init():
    for i in range(n):
        for j in range(n):
            w[i][j]=random.uniform(-1,1)
    for i in range(n):
        b[i]=random.uniform(-1,1)

#从文件中初始化权重和偏置
def init_from_file(file_name):
    with open(file_name, 'r') as file:
        lines = file.readlines()
    for i in range(n-1):
        data = lines[i].split()
        for j in range(n-1):
            w[i][j] = float(data[j])
    data = lines[n-1].split()
    for i in range(n-1):    
        b[i] = float(data[n-1])

#将权重写回文件
def write_to_file(file_name):
    with open(file_name, 'w') as file:
        for i in range(n):
            for j in range(n):
                file.write(str(w[i][j])+" ")
            file.write("\n")
        for i in range(n):    
            file.write(str(b[i])+" ")
     
#读入数据
def read_data(file_name):
    data = []  # 存储特征和标签
    with open(file_name, 'r') as file:
        for line in file:
            # 拆分每一行的数据
            row = line.strip().split(',')
            features = [float(d) for d in row[:-1]]  # 前四个数据是特征
            # 判断标签
            label = row[-1]
            if label == 'Iris-setosa':
                one_hot_label = [1, 0, 0]
            elif label == 'Iris-versicolor':
                one_hot_label = [0, 1, 0]
            elif label == 'Iris-virginica':
                one_hot_label = [0, 0, 1]    
            # 将特征和标签组合成一行
            row_data = features + one_hot_label
            data.append(row_data)
    return data

#随机划分数据集和训练集
def split_matrix(matrix, train_percentage):#数据集,训练集占比
    num_rows = len(matrix)
    train_size = int(num_rows * train_percentage)
    random.shuffle(matrix)
    # 划分训练集和测试集
    train_set = matrix[:train_size]
    test_set = matrix[train_size:]
    return train_set, test_set

def Get_actual_value(matrix):#获取鸢尾花种类
    p = Max = 0
    for i in range(3):
        if matrix[i] > Max:
            Max = matrix[i]
            p = i
    return p + 1

#获取训练集和测试集
train,test = split_matrix(read_data("iris.data"),0.7)
#初始化权重
init()#随机初始化
#nit_from_file("weights.data")#从文件初始化

# 训练次数和对应的准确率
iterations1 = []
accuracies1 = []
# 训练次数和对应的误差
iterations2 = []
accuracies2 = []

#训练
t=1
while t<=10000:
    #print("第",t,"次......")
    # 对每个训练样本执行神经网络训练
    for i in range(len(train)):
        BPNN4(train[i],0)
    s=[]
    ok = 0
    for i in range(len(test)):
        #print("\n",test[i])
        s.append(BPNN4(test[i],1))
        #print("实际输出:",s[i][1]," ",s[i][2]," ",s[i][3])
        if Get_actual_value(test[i][4:]) == Get_actual_value(s[i][1:]):
            ok += 1
    #print("准确率: {:.2f}%".format(ok * 100 / len(test)))

    accuracy = ok / len(test)
    accuracies1.append(accuracy)
    accuracies2.append(s[i][0])
    iterations1.append(t)
    iterations2.append(t)

    t=t+1

write_to_file("weights.data")#将权重到文件中

#画图
matplotlib.rcParams['font.family'] = 'SimHei'

plt.plot(iterations1, accuracies1, label='准确率')
plt.plot(iterations2, accuracies2, label='误差')
plt.xlabel('训练次数')
plt.ylabel('准确率 or 误差')
plt.legend()
plt.show()
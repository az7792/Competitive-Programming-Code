# -*- coding: utf-8 -*-
import random
import math
import time
import matplotlib.pyplot as plt

# 定义神经网络训练函数
def BPNN4(a,b,train):
    for i in range(len(b)):
        exec(a[i]+"="+str(b[i]))#a[i]=b[i]
    o1,o2,o3,sc=train
    m=[] #权值列表

    # 初始化
    # ci,si,oi,ei 偏置，加权和，输出，误差
    for i in range(4,11):
        exec("e"+str(i)+"=0")#ei=0
        exec("o"+str(i)+"=0")#oi=0
        exec("s"+str(i)+"=0")#si=0

    # 前向传播
    for i in range(4,8):#1 到 2
        for j in range(1,4):
            exec("s"+str(i)+"="+"s"+str(i)+"+o"+str(j)+"*w"+str(j)+str(i))#si+=oj*wji
        exec("s"+str(i)+"="+"s"+str(i)+"+c"+str(i)+"")#si=si+ci
        exec("o"+str(i)+"=1/(1+math.exp(-s"+str(i)+"))")#oi=1/(1+math.exp(-si))

    for i in range(8,10):#2 到 3
        for j in range(4,8):
            exec("s"+str(i)+"="+"s"+str(i)+"+o"+str(j)+"*w"+str(j)+str(i))
        exec("s"+str(i)+"="+"s"+str(i)+"+c"+str(i)+"")
        exec("o"+str(i)+"=1/(1+math.exp(-s"+str(i)+"))")

    for i in range(10,11):#3 到 4
        for j in range(8,10):
            exec("s"+str(i)+"="+"s"+str(i)+"+o"+str(j)+"*w"+str(j)+str(i))
        exec("s"+str(i)+"="+"s"+str(i)+"+c"+str(i)+"")
        exec("o"+str(i)+"=1/(1+math.exp(-s"+str(i)+"))")
        exec("e"+str(i)+"=o"+str(i)+"*(1-o"+str(i)+")*("+"o"+str(i)+"-sc"+")")#ei=oi*(1-oi)*(oi-sc)
    # 反向传播
    # 计算误差
    for i in range(8,10):
        for j in range(10,11):
            exec("e"+str(i)+"+=w"+str(i)+str(j)+"*e"+str(j))#ei=wij*ej
        exec("e"+str(i)+"=e"+str(i)+"*o"+str(i)+"*(1-o"+str(i)+")")#ei=ei*oi*(1-oi)

    for i in range(4,8):
        for j in range(8,10):
            exec("e"+str(i)+"+=w"+str(i)+str(j)+"*e"+str(j))
        exec("e"+str(i)+"=e"+str(i)+"*o"+str(i)+"*(1-o"+str(i)+")")

     # 更新权值
    for i in range(1,4):
        for j in range(4,8):
            exec("w"+str(i)+str(j)+"=w"+str(i)+str(j)+"-l*e"+str(j)+"*o"+str(i))#wij=wij-l*ej*oi
            m.append(eval("w"+str(i)+str(j)))

    for i in range(4,8):
        for j in range(8,10):
            exec("w"+str(i)+str(j)+"=w"+str(i)+str(j)+"-l*e"+str(j)+"*o"+str(i))
            m.append(eval("w"+str(i)+str(j)))

    for i in range(8,10):
        for j in range(10,11):
            exec("w"+str(i)+str(j)+"=w"+str(i)+str(j)+"-l*e"+str(j)+"*o"+str(i))
            m.append(eval("w"+str(i)+str(j)))
    
    #更新偏置
    for i in range(4,11):
        exec("c"+str(i)+"=c"+str(i)+"+l*e"+str(i))#ci=ci-l*ei
        m.append(eval("c"+str(i)))
    return m,eval("e10"),eval("o10") # 返回权值、误差、输出

# 定义神经网络的权重和偏置的变量名
a=["w14","w15","w16","w17",
 "w24","w25","w26","w27",
 "w34","w35","w36","w37",
 "w48","w49",
 "w58","w59",
 "w68","w69",
 "w78","w79",
 "w810","w910",
 "c4","c5","c6","c7","c8","c9","c10"]
b=[]

# 初始化权重和偏置的随机值
for i in a:
    exec(i+"=random.uniform(-1,1)")
    b.append(eval(i))

e10=0
t=1 #次数记录
l=0.1 #学习率

# #训练样本
# train = [
#     [0, 0, -10.0, 0.000000],
#     [0, 0, -9.9, 0.005000],
#     [0, 0, -9.8, 0.010000],
#     [0, 0, -9.7, 0.015000],
#     [0, 0, -9.6, 0.020000],
#     [0, 0, -9.5, 0.025000],
#     [0, 0, -9.4, 0.030000],
#     [0, 0, -8.8, 0.060000],
#     [0, 0, -8.7, 0.065000],
#     [0, 0, -8.6, 0.070000],
#     [0, 0, -8.5, 0.075000],
#     [0, 0, -8.4, 0.080000],
#     [0, 0, -8.3, 0.085000],
#     [0, 0, -8.2, 0.090000],
#     [0, 0, -8.1, 0.095000],
#     [0, 0, -8.0, 0.100000],
#     [0, 0, -7.9, 0.105000],
#     [0, 0, -7.8, 0.110000],
#     [0, 0, -7.7, 0.115000],
#     [0, 0, -7.6, 0.120000],
#     [0, 0, -7.5, 0.125000],
#     [0, 0, -7.4, 0.130000],
#     [0, 0, -7.3, 0.135000],
#     [0, 0, -7.2, 0.140000],
#     [0, 0, -7.1, 0.145000],
#     [0, 0, -7.0, 0.150000],
#     [0, 0, -6.9, 0.155000],
#     [0, 0, -6.8, 0.160000],
#     [0, 0, -6.7, 0.165000],
#     [0, 0, -6.6, 0.170000],
#     [0, 0, -6.5, 0.175000],
#     [0, 0, -6.4, 0.180000],
#     [0, 0, -6.3, 0.185000],
#     [0, 0, -6.2, 0.190000],
#     [0, 0, -6.1, 0.195000],
#     [0, 0, -6.0, 0.200000],
#     [0, 0, -5.9, 0.205000],
#     [0, 0, -5.8, 0.210000],
#     [0, 0, -5.7, 0.215000],
#     [0, 0, -5.6, 0.220000],
#     [0, 0, -5.5, 0.225000],
#     [0, 0, -5.4, 0.230000],
#     [0, 0, -5.3, 0.235000],
#     [0, 0, -5.2, 0.240000],
#     [0, 0, -5.1, 0.245000],
#     [0, 0, -5.0, 0.250000],
#     [0, 0, -4.9, 0.255000],
#     [0, 0, -4.8, 0.260000],
#     [0, 0, -4.7, 0.265000],
#     [0, 0, -4.6, 0.270000],
#     [0, 0, -4.5, 0.275000],
#     [0, 0, -4.4, 0.280000],
#     [0, 0, -4.3, 0.285000],
#     [0, 0, -4.2, 0.290000],
#     [0, 0, -4.1, 0.295000],
#     [0, 0, -4.0, 0.300000],
#     [0, 0, -3.9, 0.305000],
#     [0, 0, -3.8, 0.310000],
#     [0, 0, -3.7, 0.315000],
#     [0, 0, -3.6, 0.320000],
#     [0, 0, -3.5, 0.325000],
#     [0, 0, -3.4, 0.330000],
#     [0, 0, -3.3, 0.335000],
#     [0, 0, -3.2, 0.340000],
#     [0, 0, -3.1, 0.345000],
#     [0, 0, -3.0, 0.350000],
#     [0, 0, -2.9, 0.355000],
#     [0, 0, -2.8, 0.360000],
#     [0, 0, -2.7, 0.365000],
#     [0, 0, -2.6, 0.370000],
#     [0, 0, -2.5, 0.375000],
#     [0, 0, -2.4, 0.380000],
#     [0, 0, -2.3, 0.385000],
#     [0, 0, -2.2, 0.390000],
#     [0, 0, -2.1, 0.395000],
#     [0, 0, -2.0, 0.400000],
#     [0, 0, -1.9, 0.405000],
#     [0, 0, -1.8, 0.410000],
#     [0, 0, -1.7, 0.415000],
#     [0, 0, -1.6, 0.420000],
#     [0, 0, -1.5, 0.425000],
#     [0, 0, -1.4, 0.430000],
#     [0, 0, -1.3, 0.435000],
#     [0, 0, -1.2, 0.440000],
#     [0, 0, -1.1, 0.445000],
#     [0, 0, -1.0, 0.450000],
#     [0, 0, -0.9, 0.455000],
#     [0, 0, -0.8, 0.460000],
#     [0, 0, -0.7, 0.465000],
#     [0, 0, -0.6, 0.470000],
#     [0, 0, -0.5, 0.475000],
#     [0, 0, -0.4, 0.480000],
#     [0, 0, -0.3, 0.485000],
#     [0, 0, -0.2, 0.490000],
#     [0, 0, -0.1, 0.495000],
#     [0, 0, -0.0, 0.500000],
#     [0, 0, 0.1, 0.505000],
#     [0, 0, 0.2, 0.510000],
#     [0, 0, 0.3, 0.515000],
#     [0, 0, 0.4, 0.520000],
#     [0, 0, 0.5, 0.525000],
#     [0, 0, 0.6, 0.530000],
#     [0, 0, 0.7, 0.535000],
#     [0, 0, 0.8, 0.540000],
#     [0, 0, 0.9, 0.545000],
#     [0, 0, 1.0, 0.550000],
#     [0, 0, 1.1, 0.555000],
#     [0, 0, 1.2, 0.560000],
#     [0, 0, 1.3, 0.565000],
#     [0, 0, 1.4, 0.570000],
#     [0, 0, 1.5, 0.575000],
#     [0, 0, 1.6, 0.580000],
#     [0, 0, 1.7, 0.585000],
#     [0, 0, 1.8, 0.590000],
#     [0, 0, 1.9, 0.595000],
#     [0, 0, 2.0, 0.600000],
#     [0, 0, 2.1, 0.605000],
#     [0, 0, 2.2, 0.610000],
#     [0, 0, 2.3, 0.615000],
#     [0, 0, 2.4, 0.620000],
#     [0, 0, 2.5, 0.625000],
#     [0, 0, 2.6, 0.630000],
#     [0, 0, 2.7, 0.635000],
#     [0, 0, 2.8, 0.640000],
#     [0, 0, 2.9, 0.645000],
#     [0, 0, 3.0, 0.650000],
#     [0, 0, 3.1, 0.655000],
#     [0, 0, 3.2, 0.660000],
#     [0, 0, 3.3, 0.665000],
#     [0, 0, 3.4, 0.670000],
#     [0, 0, 3.5, 0.675000],
#     [0, 0, 3.6, 0.680000],
#     [0, 0, 3.7, 0.685000],
#     [0, 0, 3.8, 0.690000],
#     [0, 0, 3.9, 0.695000],
#     [0, 0, 4.0, 0.700000],
#     [0, 0, 4.1, 0.705000],
#     [0, 0, 4.2, 0.710000],
#     [0, 0, 4.3, 0.715000],
#     [0, 0, 4.4, 0.720000],
#     [0, 0, 4.5, 0.725000],
#     [0, 0, 4.6, 0.730000],
#     [0, 0, 4.7, 0.735000],
#     [0, 0, 4.8, 0.740000],
#     [0, 0, 4.9, 0.745000],
#     [0, 0, 5.0, 0.750000],
#     [0, 0, 5.1, 0.755000],
#     [0, 0, 5.2, 0.760000],
#     [0, 0, 5.3, 0.765000],
#     [0, 0, 5.4, 0.770000],
#     [0, 0, 5.5, 0.775000],
#     [0, 0, 5.6, 0.780000],
#     [0, 0, 5.7, 0.785000],
#     [0, 0, 5.8, 0.790000],
#     [0, 0, 5.9, 0.795000],
#     [0, 0, 6.0, 0.800000],
#     [0, 0, 6.1, 0.805000],
#     [0, 0, 6.2, 0.810000],
#     [0, 0, 6.3, 0.815000],
#     [0, 0, 6.4, 0.820000],
#     [0, 0, 6.5, 0.825000],
#     [0, 0, 6.6, 0.830000],
#     [0, 0, 6.7, 0.835000],
#     [0, 0, 6.8, 0.840000],
#     [0, 0, 6.9, 0.845000],
#     [0, 0, 7.0, 0.850000],
#     [0, 0, 7.1, 0.855000],
#     [0, 0, 7.2, 0.860000],
#     [0, 0, 7.3, 0.865000],
#     [0, 0, 7.4, 0.870000],
#     [0, 0, 7.5, 0.875000],
#     [0, 0, 7.6, 0.880000],
#     [0, 0, 7.7, 0.885000],
#     [0, 0, 7.8, 0.890000],
#     [0, 0, 7.9, 0.895000],
#     [0, 0, 8.0, 0.900000],
#     [0, 0, 8.1, 0.905000],
#     [0, 0, 8.5, 0.925000],
#     [0, 0, 8.6, 0.930000],
#     [0, 0, 8.7, 0.935000],
#     [0, 0, 8.8, 0.940000],
#     [0, 0, 8.9, 0.945000],
#     [0, 0, 9.0, 0.950000],
#     [0, 0, 9.1, 0.955000],
#     [0, 0, 9.2, 0.960000],
#     [0, 0, 9.3, 0.965000],
#     [0, 0, 9.4, 0.970000],
#     [0, 0, 9.5, 0.975000],
#     [0, 0, 9.6, 0.980000],
#     [0, 0, 9.7, 0.985000],
#     [0, 0, 9.8, 0.990000],
#     [0, 0, 9.9, 0.995000],
#     [0, 0, 10.0, 1.000000]
# ]
# test = [
#     [0, 0, -9.3, 0.035000],
#     [0, 0, -9.2, 0.040000],
#     [0, 0, -9.1, 0.045000],
#     [0, 0, -9.0, 0.050000],
#     [0, 0, -8.9, 0.055000],
#     [0, 0, 8.2, 0.910000],
#     [0, 0, 8.3, 0.915000],
#     [0, 0, 8.4, 0.920000]
# ]

train=[[1,0,0,0],[0,0,1,0],[0,1,1,1],[1,1,0,1],[1,0,1,1],[0,1,0,0],[0,0,0,0],[1,1,1,1]] 
test=[[1,0,1,1],[0,0,1,0]] 
tu = []  # 训练样本每次迭代的输出列表
num = []  # 迭代次数记录

# 初始化训练样本输出列表
for i in range(len(train)):
    tu.append([])

file = open('D:\\Code\\t1.txt', 'w')

# 将初始值写入文件
file.write("初始值:")
for i in a:
    file.write(i+"="+str(eval(i))+"\n")

n1=time.time()

# 训练循环
#while abs(e10)>=0.0001 or t==1:
while t<=10:
    print("第",t,"次......")
    file.write("\n 第"+str(t)+"次\n")
    n=[]

    # 对每个训练样本执行神经网络训练
    for i in range(len(train)):
        n.append(BPNN4(a,b,train[i]))
        tu[i].append(n[i][2])

    # 将权值和误差写入文件
        for j in range(len(n[i][0])):
            file.write(a[j]+"="+str(n[i][0][j])+" ")
        file.write("\n e6="+str(n[i][1])+"\n")

    b=n[0][0]
    e10=n[0][1]
    o=n[0][2]

    # 选择具有最小误差的训练样本
    for i in range(len(train)-1):
        if abs(e10)<=abs(n[i+1][1]):
            b=n[i+1][0]
            e10=n[i+1][1]
            o=n[i+1][2]

    file.write("终选误差:"+str(e10)+"\n")
    file.write("终选权值:\n")

    # 将最终的权值写入文件
    for i in range(len(b)):
        file.write(a[i]+"="+str(b[i])+" ")
    file.write("\n")
    print("终选误差:",e10)
    num.append(t)
    t=t+1

n2=time.time()
n=n2-n1

print("迭代次数:",t-1)
file.write("迭代次数:"+str(t-1))
file.write(" 用时:"+str(n))
print("用时:",n)

# 绘制训练进度图
for i in range(len(train)):
    plt.plot(num,tu[i])

print("测试:")
s=[]

# 在测试数据上进行测试
for i in range(len(test)):
    print("\n",test[i])
    file.write(str(test[i])+"\n")
    s.append(BPNN4(a,b,test[i]))
    print("输出:",s[i][2])
    print("误差:",s[i][1])
    file.write("输出:"+str(s[i][2])+"\n 误差:"+str(s[i][1])+"\n")
    
file.close()
plt.show()
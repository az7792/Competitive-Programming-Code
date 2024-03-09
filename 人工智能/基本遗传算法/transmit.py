# encoding=utf-8
import numpy as np
import math
import matplotlib.pyplot as plt
import matplotlib

def getfit(gene):#获取适应度值
    sum_volume = np.sum(gene * np.array([vol[0] for vol in data]))  # 计算总体积
    # 如果超过背包容量
    if sum_volume > max_volume:
        return -10
    sum_value = np.sum(gene * np.array([val[1] for val in data]))  # 计算总价值        
    return sum_value

def knapsack_dp(max_volume):#DP
    n = len(data)
    dp = [[0] * (max_volume + 1) for _ in range(n + 1)]
    for i in range(n):
        for j in range(1, max_volume + 1):
            if j - int(data[i][0]) < 0:
                dp[i + 1][j] = dp[i][j]
            else:
                dp[i + 1][j] = max(dp[i][j], dp[i][j - int(data[i][0])] + int(data[i][1]))
    return dp[n][max_volume]

#读入数据
data = [] 
file_path = 'goods1.data'
with open(file_path, 'r') as file:
        for line in file:
            volume, value = map(float, line.strip().split())
            data.append((volume, value))
    
# 参数设置
population = 50  # 种群大小
cross_rate = 0.5  # 交叉率
mutation_rate = 0.1  # 变异率
genetic_num = len(data)  # 每个染色体的基因数量(物品个数)
max_volume = 1000 #背包容量
max_generation = 10000  # 最大迭代次数
max_value = knapsack_dp(max_volume)

# 初始化种群
cc = []
#for i in np.arange(0, max_population, 1): # 0<= i < max_population
    #cc.append(np.random.randint(0, 2, genetic_num))  # 随机初始化染色体基因值
for i in np.arange(0, population, 1):#每个个体随机选择一个物品
    genes = np.zeros(genetic_num, dtype=int)
    genes[np.random.randint(0, genetic_num)] = 1
    cc.append(genes)
#print("初始种群:", cc)
crosstag = np.zeros(population, dtype=int)  # 用于标记个体是否参与交叉
fit = np.zeros(population)  # 存储每个个体的适应值

# 计算初始适应值
totalfit = 0
bestindex = 0
bestfit = 0

for i in np.arange(0, population, 1):
    fit[i] = getfit(cc[i])  # 计算适应值

fit = fit + abs(np.min(fit)) + 1 #偏移适应值，确保totalfit>0

for i in np.arange(0, population, 1):
    totalfit += fit[i]
    if (bestfit <= fit[i]):
        bestindex = i
        bestfit = fit[i]

fit = fit / totalfit #归一化

# 训练次数和对应的适应度值
iterations1 = []
accuracies1 = [] 

# 主循环
generation = 0
while generation < max_generation:
    # 选择操作，产生新的种群，轮盘赌方式
    newcc = []
    for i in np.arange(0, population, 1):
        r = np.random.rand()
        tmp = 0
        for j in np.arange(0, population, 1):
            tmp += fit[j]
            if (tmp >= r):
                newcc.append(np.copy(cc[j])) #确保在内存中是独立的,防止基因交叉出现问题
                break
    # 确定哪些个体参加交配
    for i in np.arange(0, population, 1):
        r = np.random.rand()
        if (r < cross_rate):
            crosstag[i] = 1
        else:
            crosstag[i] = 0

    # 执行交配操作
    i = 0
    while i < population:
        if crosstag[i] > 0:
            j = i + 1
            while j < population:
                if crosstag[j] > 0:
                    # 凑齐一对，执行交叉操作
                    r = np.random.randint(0, genetic_num - 1) #[0,genetic_num - 2],确保至少有一个基于片段进行了交换
                    for k in np.arange(r + 1, genetic_num, 1):
                        tmpgen = newcc[i][k]
                        newcc[i][k] = newcc[j][k]
                        newcc[j][k] = tmpgen
                    i = j
                    break
                j += 1
            if i != j:
                break  # 没找到可交叉的另一个染色体，退出外循环
        i += 1
    # 执行变异操作
    for i in np.arange(0, population, 1):
        for k in np.arange(0, genetic_num, 1):
            r = np.random.rand()
            if r < mutation_rate:
                newcc[i][k] = np.random.randint(0, 2)

    # 保留上一代精英
    tmpindex = bestindex

    fit = np.zeros(population)
    # 计算适应值
    totalfit = 0
    bestindex = 0
    worstindex = 0
    bestfit = 0
    worstfit = 0

    for i in np.arange(0, population, 1):
        fit[i] = getfit(newcc[i])  # 计算适应值
        if (worstfit >= fit[i]): #选出当代最差的
            worstindex = i
            worstfit = fit[i]

    #newcc[worstindex] = np.copy(cc[tmpindex])
    #fit[worstindex] = getfit(newcc[worstindex])

    fit = fit + abs(np.min(fit)) + 1 #偏移适应值，确保totalfit>0

    for i in np.arange(0, population, 1):
        totalfit = totalfit + fit[i]
        if (bestfit <= fit[i]):#选出本代精英
            bestindex = i
            bestfit = fit[i]

    fit = fit / totalfit #归一化

    cc = newcc

    accuracies1.append(bestfit)
    iterations1.append(generation)

    generation += 1

#print("最终种群:", newcc)
print("最佳索引:", bestindex, "; 最佳适应度:", bestfit,"最大价值:", getfit(newcc[bestindex]))
print("最佳个体:", newcc[bestindex])
print("最大价值(DP):",max_value)

#绘图
matplotlib.rcParams['font.family'] = 'SimHei'

plt.plot(iterations1, accuracies1, label='价值')
plt.axhline(y=max_value, color='y', label='理论最大价值')
plt.xlabel('训练次数')
plt.ylabel('价值')
plt.legend()
plt.show()
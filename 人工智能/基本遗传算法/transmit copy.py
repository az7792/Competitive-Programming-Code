# encoding=utf-8
import numpy as np
import math

def getfit(gene):#获取适应度值
    sum_volume = np.sum(gene * np.array([vol[0] for vol in data]))  # 计算总体积
    # 如果超过背包容量,适应度值为负
    if sum_volume > max_volume:
        return -10
    sum_value = np.sum(gene * np.array([val[1] for val in data]))  # 计算总价值        
    return sum_value

def knapsack_dp(max_volume):
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
file_path = 'goods3.data'
with open(file_path, 'r') as file:
        for line in file:
            volume, value = map(float, line.strip().split())
            data.append((volume, value))
    
# 参数设置
population = 100  # 种群大小
cross_rate = 0.6 # 参与交叉的比例
mutation_rate = 0.1  # 变异率
genetic_num = len(data)  # 每个染色体的基因数量(物品个数)
max_volume = 200 #背包容量 1000 70 200
max_generation = 1000  # 最大迭代次数

# 初始化种群
cc = []
#for i in np.arange(0, max_population, 1): # 0<= i < max_population
    #cc.append(np.random.randint(0, 2, genetic_num))  # 随机初始化染色体基因值
for i in np.arange(0, population, 1):
    genes = np.zeros(genetic_num, dtype=int)
    genes[np.random.randint(0, genetic_num)] = 1
    cc.append(genes)
#print("初始种群:", cc)
fit = np.zeros(population)  # 存储每个个体的适应值

# 计算初始适应值
totalfit = 0
bestindex = 0
bestfit = 0
for i in np.arange(0, population, 1):
    fit[i] = getfit(cc[i])  # 计算适应值
    # 选择精英
    if (bestfit <= fit[i]):
        bestindex = i
        bestfit = fit[i]

# 主循环
generation = 0
while generation < max_generation:
    # 确定哪些个体参加交配
    crosstag = []  # 参与交叉的个体编号
    for i in np.arange(0, max(2,int(population*cross_rate)), 1):
        g1 = np.random.randint(0, population)
        g2 = np.random.randint(0, population)
        if(fit[g1]<=fit[g2]):
            crosstag.append(int(g2))
        else:
            crosstag.append(int(g1))
    newcc = [] #新一代

    # 交叉操作 随机选择两个进行交叉
    while(1):
        g1 = np.random.randint(0, len(crosstag))
        g2 = np.random.randint(0, len(crosstag))
        r = np.random.randint(0, genetic_num - 1) #[0,genetic_num - 2],确保至少有一个基于片段进行了交换
        kid1 = np.copy(cc[crosstag[g1]])
        kid2 = np.copy(cc[crosstag[g2]])
        for k in np.arange(r + 1, genetic_num, 1):
            tmpgen = kid1[k]
            kid1[k] = kid2[k]
            kid2[k] = tmpgen
        newcc.append(kid1)
        if(len(newcc)==population):
            break
        newcc.append(kid2)
        if(len(newcc)==population):
            break

    # 执行变异操作
    for i in np.arange(0, population, 1):
        for k in np.arange(0, genetic_num, 1):
            r = np.random.rand()
            if r < mutation_rate:
                newcc[i][k] = np.random.randint(0, 2)

    # 计算适应值
    newfit = np.zeros(population)  # 新一代的适应值
    newbestindex = 0
    newbestfit = 0
    for i in np.arange(0, population, 1):
        newfit[i] = getfit(newcc[i])  # 计算适应值
        #选择精英
        if (newbestfit <= newfit[i]):
            newbestindex = i
            newbestfit = newfit[i]

    newcc = cc + newcc
    newfit = np.concatenate((newfit, fit))

    cc = []

    if(newbestfit<=bestfit):
        cc.append(newcc[bestindex])
    else:
        cc.append(newcc[newbestindex])
        bestfit = newbestfit
    bestindex = 0
    
    for i in np.arange(0, population-1, 1):
        g1 = np.random.randint(0, len(newcc))
        g2 = np.random.randint(0, len(newcc))
        if(newfit[g1]<=newfit[g2]):
            cc.append(newcc[g2])
        else:
            cc.append(newcc[g1])
    generation += 1

#print("最终种群:", newcc)
print("最佳索引:", bestindex, "; 最佳适应度:", bestfit,"最大价值:", getfit(newcc[bestindex]))
print("最佳个体:", newcc[bestindex])
print("最大价值(DP):",knapsack_dp(max_volume))

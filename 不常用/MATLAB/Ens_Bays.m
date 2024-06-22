function accuracy = Ens_Bays(datafilename)
%dataset 最后一列是class,调用方式 accuracy = Ens_Bays('glass.csv')
dataset = csvread(datafilename);
Rratio = 0.7;
Cratio = 0.6;
[row,col] = size(dataset);
MAXLOOP = 20;
step = 4;
%try mapminmax
%discretization，离散化[1,step+1]
for j = 1: col-1
   dataset(:,j) =  1 + round((dataset(:,j)-min(dataset(:,j)))/(max(dataset(:,j))-min(dataset(:,j)))*step); %
end
 %disp(dataset);
% rand('seed',1);
%随机选训练样本
queue = randperm(row);
rowsample = queue(1:round(row*Rratio));
%剩下的是测试样本
rowleft = setdiff(1:row, rowsample);
testlabel = dataset(rowleft,end);
%记录预测结果
prediction = [];

for loop = 1 : MAXLOOP
% step1 随机选属性列colsample，占属性总列数的比例为Cratio。。。   
    queue = randperm(col-1);
    colsample = queue(1:round(col*Cratio));
%step2 用选中的行rowsample和选中的列colsample形成训练数据集trainset，同时记录对应的类别trainlabel
    trainset = dataset(rowsample,colsample);
    trainlabel = dataset(rowsample,end);
%step3 用测试样本的行rowleft和刚选中的列colsample形成测试样本集合 testset   
    testset = dataset(rowleft,colsample);
%step4 朴素贝叶斯分类器给出测试样本集合的预测结果
    testpred = myBays(trainset,trainlabel,testset,testlabel,step);  %需要补充该函数 
%step5 预测结果testpred记录到prediction中
    prediction = [prediction, testpred];  %按列存放:
end
%step6 将MAXLOOP次的预测结果按多数取胜方法进行集成
   pred_label = bagging(prediction);
%    disp(size(testpred));
%    disp(size(testlabel));
%计算预测精度
   accuracy = sum(testlabel==pred_label)/length(rowleft);

return

function testpred = myBays(trainset,trainlabel,testset,testlabel,step)
    %计算p1 - p6的概率并进行拉普拉斯平滑
    C = unique([trainlabel; testlabel]);
    p = zeros(size(C,1),1);
    for i = 1:size(p,1)
        p(i) = (sum(trainlabel==C(i))+1)/(size(trainlabel,1)+size(C,1));
    end
    %类别c下特征x取值为k的概率
    pcxk = zeros(size(C,1),size(trainset,2),step+1);
    for i = 1:size(C,1)
        for j = 1:size(trainset,2)
            for k = 1:step+1
                nc = sum(trainlabel == C(i));%类别为ci的样本数
                ncxk = sum(trainset(trainlabel == C(i), j) == k);%类别为ci且特征xj==k的个数
                % 计算概率并进行拉普拉斯平滑
                pcxk(i, j, k) = (ncxk+1)/(nc+step+1);
            end            
        end
    end
    
    %初始化预测结果
    testpred = zeros(size(testset,1),1);
    for i  = 1:size(testset,1)
        % 初始化每种类别的概率
        pc = zeros(size(C,1), 1);
        for c = 1:size(C,1)
            %pc(c) = p(y==c) * ∏P(xj==testset(i,j)|y==c)
            pc(c) = p(c);      
            for j = 1:size(testset,2)
                pc(c) = pc(c) * pcxk(c,j,testset(i,j));
            end
        end
        % 选择最大概率的类别作为结果
        [~, testpred(i)] = max(pc);
    end
return

function  pred_label =  bagging(prediction)
   %初始化
   pred_label = zeros(size(prediction, 1), 1);
   %选出预测结果中每一行的众数
   for i = 1:size(prediction, 1)
        pred_label(i) = mode(prediction(i, :));
   end
return

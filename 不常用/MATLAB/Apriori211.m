function Lk = Apriori211(filename,minsup)
%调用方式：Lk = Apriori211('testdata.txt',0.4)
global MAXITEM 
MAXITEM = 10;
data = getdatafromfile(filename);
Lk = large(data,minsup);

function Lk = large(data,minsup)

b = sum(data,1);  %按列求和 
L1 = find( b >= size(data,1)*minsup );
Lk = {L1'};  %!!!!加了转置运算

lenL1 = length(L1);

candi = [];
for i=1:lenL1
    for j=i+1:lenL1
        temp=[L1(i),L1(j)];
        candi = [candi;temp];
    end
end
%size(A,1)：获取矩阵A的行数；
count = zeros(size(candi,1),1); %计数用
for i=1:size(data,1)
    for j=  1:size(candi,1)
     if data(i,candi(j,1))==1 && data(i,candi(j,2))==1
         count(j) = count(j)+1;
     end
    end
end

L2index = count>= size(data,1)*minsup;
L2 = candi(L2index,1:2);
Lk(2) = {L2};

%3项集及以上
flag = 1;
Lindex = 3;

while flag
  pool = Lk{Lindex-1};
  candi = [];
  for i=1:size(pool,1)-1
    for j=i+1:size(pool,1)
        p1 = pool(i,1:Lindex-2);%第一个的开头
        p2 = pool(j,1:Lindex-2);%第二个的开头
        if p1==p2  %可以连接
            temp = [p1,pool(i,Lindex-1),pool(j,Lindex-1)];
            candi=[candi;temp];
        end
    end
  end
%   candi
  if isempty(candi)
      break;
  end
  
%剪枝 需要补充
 i=1;
  while i<=size(candi,1)
    tmp = candi(i,:);
    f=false;%是否剪去当前候选项集
    for j=1:size(tmp,2)
        temp = [tmp(1,1:j-1),tmp(1,j+1:size(tmp,2))];
        F = false;%temp是否属于Lk{Lindex-1}
        for k=1:size(Lk{Lindex-1},1)
            if temp == Lk{Lindex-1}(k,:)
                F = true;
                break;
            end          
        end
        if F == false
              f=true;
              break;
        end
    end
    if f==true
        candi(i,:)=[];
    else
        i = i+1;
    end
  end

  count = zeros(size(candi,1),1);
 %count，对剪枝剩下的候选项集进行支持度计数
 for j = 1:size(candi,1)
    for i = 1:size(data,1)
         if sum(data(i,candi(j,:)),2)==Lindex
             count(j) = count(j)+1;
         end
    end
 end

%   candi
 candi(count<size(data,1)*minsup,:) =[];
  if isempty(candi)
      flag=0;
  else
      Lk(Lindex) = {candi};
  end
  Lindex = Lindex+1;
end

return

function [data] = getdatafromfile(filename)
global MAXITEM
fid = fopen(filename);%打开
data = [];
i = 0;
while ~feof(fid)%循环读取每一行
i = i+1;
tline{i,1} = fgetl(fid);%按行读取
line = str2num(tline{i,1});%转数值矩阵
temp = zeros(1,MAXITEM);%建立全零矩阵
temp(line) = 1;%一个项目出现在这个元组中，则相应位置设为1，否则为0
data = [data;temp];
end
fclose(fid);
return



function Lk = Apriori211(filename,minsup)
%���÷�ʽ��Lk = Apriori211('testdata.txt',0.4)
global MAXITEM 
MAXITEM = 10;
data = getdatafromfile(filename);
Lk = large(data,minsup);

function Lk = large(data,minsup)

b = sum(data,1);  %������� 
L1 = find( b >= size(data,1)*minsup );
Lk = {L1'};  %!!!!����ת������

lenL1 = length(L1);

candi = [];
for i=1:lenL1
    for j=i+1:lenL1
        temp=[L1(i),L1(j)];
        candi = [candi;temp];
    end
end
%size(A,1)����ȡ����A��������
count = zeros(size(candi,1),1); %������
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

%3�������
flag = 1;
Lindex = 3;

while flag
  pool = Lk{Lindex-1};
  candi = [];
  for i=1:size(pool,1)-1
    for j=i+1:size(pool,1)
        p1 = pool(i,1:Lindex-2);%��һ���Ŀ�ͷ
        p2 = pool(j,1:Lindex-2);%�ڶ����Ŀ�ͷ
        if p1==p2  %��������
            temp = [p1,pool(i,Lindex-1),pool(j,Lindex-1)];
            candi=[candi;temp];
        end
    end
  end
%   candi
  if isempty(candi)
      break;
  end
  
%��֦ ��Ҫ����
 i=1;
  while i<=size(candi,1)
    tmp = candi(i,:);
    f=false;%�Ƿ��ȥ��ǰ��ѡ�
    for j=1:size(tmp,2)
        temp = [tmp(1,1:j-1),tmp(1,j+1:size(tmp,2))];
        F = false;%temp�Ƿ�����Lk{Lindex-1}
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
 %count���Լ�֦ʣ�µĺ�ѡ�����֧�ֶȼ���
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
fid = fopen(filename);%��
data = [];
i = 0;
while ~feof(fid)%ѭ����ȡÿһ��
i = i+1;
tline{i,1} = fgetl(fid);%���ж�ȡ
line = str2num(tline{i,1});%ת��ֵ����
temp = zeros(1,MAXITEM);%����ȫ�����
temp(line) = 1;%һ����Ŀ���������Ԫ���У�����Ӧλ����Ϊ1������Ϊ0
data = [data;temp];
end
fclose(fid);
return



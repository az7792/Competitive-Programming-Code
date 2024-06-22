function [dataset,clusters,RI] = myDBSCAN(filename,eps,Min_pts)
%���÷�ʽ�� [dataset,clusters,RI] = myDBSCAN('iris.csv',1.0, 43);  % ǰ50����ȷ���������
%  [dataset,clusters,RI]= myDBSCAN('test6.txt',1.0, 10);
%����ʽ��ȡ�����ļ�
expression1 = '.*.csv';
expression2 = '.*.txt';
if ~isempty(regexp(filename,expression1,'match'))
    dataset = csvread(filename);
end

if ~isempty(regexp(filename,expression2,'match'))
    dataset = load(filename);
end

[row,col] = size(dataset);
label = dataset(:,end);

%calculate the pair-wise distance
dis = zeros(row,row);
%��Ҫ���� ����֮�����ļ�����̣�ע�����һ���Ǳ�ǩ�����������
for i = 1:row
    for j = 1:row
        SUM=0;
        for k = 1:col-1
            SUM = SUM + (dataset(i,k)-dataset(j,k))*(dataset(i,k)-dataset(j,k));
        end
        dis(i,j) = sqrt(SUM);
    end    
end

%find the eps neighbours for each data point
%��Ҫ���䣬 ����ÿ�����eps ����
neighbor = cell(row,1);
for i = 1:row
    tmp = [];
    for j = 1:row
        if i~=j&&dis(i,j)<=eps
            tmp = [tmp,j];
        end
    end  
    neighbor{i}=tmp;
end


clusters = (1:row)';
processed = false(row,1); 

%��Ҫ����DBSCAN�ľ������
for i = 1:row
        if ~processed(i)
            [clusters, processed] = expand(i, neighbor, clusters, processed, Min_pts);
        end
end

finalcls = unique(clusters);
result = cell(length(finalcls),1);

%display the results
for i = 1:length(finalcls)
    result{i} = find(clusters == finalcls(i));
end

hold on
%��Ҫ����ÿ���ص���ʾ����
for i = 1:length(result)
    %ѡ��ָ������Ϊxy��
    col_1=1;col_2=2;
    scatter(dataset(result{i}, col_1), dataset(result{i}, col_2), 'filled');
    pause(1);
end
hold off


%calculate RI index

RI = cal_RI(label,clusters);


return

function [clusters,processed] = expand(i,neighbor,clusters,processed,Min_pts)
%�ݹ�ʵ���ܶȾ���
    seeds = neighbor{i};
    if(length(seeds)+1<Min_pts)
        if(~processed(i))
            clusters(i) = 0; %����Ϊ����
        end
    else
        processed(i)=true;%һ��Ϊ���ĵ�
        for j = 1:length(seeds)
            if(~processed(seeds(j)))
                clusters(seeds(j))=clusters(i);
                processed(seeds(j))=true;%һ����Ϊ������
                [clusters,processed] = expand(seeds(j),neighbor,clusters,processed,Min_pts);
            end
        end
    end
return
    
function RI = cal_RI(label,clusters)
% ����RI
    a=0;
    b=0;
    n = length(label);
    for i = 1:n
        for j = i+1:n
            if label(i) == label(j) && clusters(i) == clusters(j)
                a = a + 1;
            elseif label(i) ~= label(j) && clusters(i) ~= clusters(j)
                b = b + 1;
            end
        end
    end
    
    RI = (a + b) / (n*(n-1)/2);
return
    
         
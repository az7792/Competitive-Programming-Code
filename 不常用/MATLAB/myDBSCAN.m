function [dataset,clusters,RI] = myDBSCAN(filename,eps,Min_pts)
%调用方式： [dataset,clusters,RI] = myDBSCAN('iris.csv',1.0, 43);  % 前50个正确，后面混淆
%  [dataset,clusters,RI]= myDBSCAN('test6.txt',1.0, 10);
%按格式读取数据文件
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
%需要补充 两点之间距离的计算过程，注意最后一列是标签，不参与计算
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
%需要补充， 计算每个点的eps 邻域
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

%需要补充DBSCAN的聚类过程
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
%需要补充每个簇的显示过程
for i = 1:length(result)
    %选中指定列作为xy轴
    col_1=1;col_2=2;
    scatter(dataset(result{i}, col_1), dataset(result{i}, col_2), 'filled');
    pause(1);
end
hold off


%calculate RI index

RI = cal_RI(label,clusters);


return

function [clusters,processed] = expand(i,neighbor,clusters,processed,Min_pts)
%递归实现密度聚类
    seeds = neighbor{i};
    if(length(seeds)+1<Min_pts)
        if(~processed(i))
            clusters(i) = 0; %可能为噪声
        end
    else
        processed(i)=true;%一定为核心点
        for j = 1:length(seeds)
            if(~processed(seeds(j)))
                clusters(seeds(j))=clusters(i);
                processed(seeds(j))=true;%一定不为噪声点
                [clusters,processed] = expand(seeds(j),neighbor,clusters,processed,Min_pts);
            end
        end
    end
return
    
function RI = cal_RI(label,clusters)
% 计算RI
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
    
         
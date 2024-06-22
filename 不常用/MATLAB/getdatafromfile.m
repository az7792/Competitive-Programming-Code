function [data] = getdatafromfile(filename)
global MAXITEM;
%MAXITEM = 10;
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
function [data] = getdatafromfile(filename)
global MAXITEM;
%MAXITEM = 10;
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
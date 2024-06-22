function [data] = mygetdata(filename)
fid = fopen(filename);
data = {};
while ~feof(fid)
    data = [data;{str2num(fgetl(fid))}];
end
fclose(fid);
return


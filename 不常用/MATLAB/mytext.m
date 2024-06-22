% b = input('请输入一个数字: ', 's');
% a = str2double(b);
% if mod(a,2)==0
%     a = 1234;
% else
%     a = 5678;
% end
% fprintf('%d',a);
% a = 0;
% b=a;
% for i = 1:1:10
%     a = a + i;
%     b = b-i;
% end
% fprintf("%d %d\n",a,b);
% fprintf('%d %d',a,b);

% f = zeros(1,100);
% f(1)=1;
% f(2)=2;
% for j = 1:10
%     n_str = input("输入f[n]：","s");
%     n = str2double(n_str);
%     for i = 3:1:n
%         f(i) = f(i-1)+f(i-2);
%     end
%     fprintf("f[%d]=%d\n",n,f(n));
% end

% a = 1;
% b = 10;
% sum_result = myFunction(a, b);
% 
% % 显示结果
% fprintf('The sum of %d and %d is %d\n', a, b, sum_result);

% 准备数据
% x = linspace(0, 2 * pi, 100);  % 创建一个包含100个数据点的 x 向量
% y = sin(x);                   % 计算对应的 sin(x) 值
% 
% % 使用 plot 函数绘制线图
% plot(x, y)
% 
% % 自定义图形
% title('Sine Wave')            % 添加标题
% xlabel('x')                   % 添加 x 轴标签
% ylabel('sin(x)')              % 添加 y 轴标签
% grid on                       % 显示网格线

% A = [1 2 3;4 5 6;7 8 9];
% A = B * inv(A);

%data = mygetdata('a.txt')
%data = getdatafromfile('a.txt')
% data={};
% line = '1 4 8 2 9';
% line1 = '9 0 8 2 3 0';
% data = [data;{str2num(line)}];
% data = [data;{str2num(line1)}];
% data
data = {{[1,2,3]},{[3,4,5]}}

x=imread('flowers.tif');
figure(1);
imshow(x);
title('原图');

figure(2);
a=rgbtogray(x);
imshow(a);
title('灰度图');

figure(3);
b=graytobw(a);
imshow(b);
title('二值图');

figure(4);
rgbtohist(a);
title('直方图');

function gray=rgbtogray(rgb)
[m,n,t]=size(rgb);
    for i=1:m
      for j=1:n
            for k=1:t
            gray(i,j,k)=0.299*rgb(i,j,1)+0.587*rgb(i,j,2)+0.11400*rgb(i,j,3);
            end
        end
    end
end

function bw=graytobw(gray)
[m,n,t]=size(gray);
alpha=0.5; %阈值
    for i=1:m
      for j=1:n
          for k=1:t
                if gray(i,j,k)>alpha*255
                     bw(i,j,k)=255;
                 else bw(i,j,k)=0;
                end 
          end
      end
   end
end

function rgbtohist(I)
row=size(I,1);
column=size(I,2);%2→dimision
N=zeros(1,256);%zeros(256)生成256x256矩阵
for i=1:row
    for j=1:column
        k=I(i,j);
        N(k+1)=N(k+1)+1;%记录每个灰度值的像素数
    end
end
subplot(121);imshow(I);%subplot将窗口分为1x2两个窗口，现在在第一个小窗口绘图
subplot(1,2,2);bar(N);%subplot(122)=subplot(1,2,2)
%bar函数绘制直方图，为N中每一行的每一个元素绘制一个条
axis tight;%设置坐标轴
end
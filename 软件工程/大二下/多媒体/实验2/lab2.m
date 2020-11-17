a=imread('pout.tif');
figure(1);

subplot(2,6,1);
imshow(a);
title('原图像');

subplot(2,6,7);
imhist(a);
title('灰度直方图');

subplot(2,6,2);
a1=grayto1(a);
imshow(a1);
title('反色变换后');

subplot(2,6,8);
imhist(a1);
title('灰度直方图');

subplot(2,6,3);
a1=grayto2(a);
imshow(a1);
title('对数变换后');

subplot(2,6,9);
imhist(a1);
title('灰度直方图');

subplot(2,6,4);
a1=grayto3(a,0.8);
imshow(a1);
title('幂次变换后');

subplot(2,6,10);
imhist(a1);
title('灰度直方图');

subplot(2,6,5);
a1=grayto4(a,0.28*255,0.7*255,0*255,1*255);
imshow(a1);
title('对比度拉伸后');

subplot(2,6,11);
imhist(a1);
title('灰度直方图');

subplot(2,6,6);
a1=grayto5(a);
imshow(a);
title('直方图均衡化后');

subplot(2,6,12);
imhist(a1);
title('灰度直方图');

%反色
function negative=grayto1(gray)
[m,n,t]=size(gray);
    for i=1:m
      for j=1:n
          for k=1:t
              negative(i,j,k)=256-gray(i,j,k);                
          end
      end
   end
end

%对数变换
function  logarithm=grayto2(gray)
    temp=mat2gray(gray);
    temp1 = log(1 + 10 * temp)/log(1 + 10);                       
    logarithm = uint8(temp1*(255 - 0) + 0);
end

%幂次变换
function power=grayto3(gray,p)
    temp=mat2gray(gray);
    temp1 = temp.^p;                       
    power = uint8(temp1*(255 - 0) + 0);
end

%对比度拉伸
function extend = grayto4(gray,low1,low2,high1,high2)
    [height,width] = size(gray);
    extend = uint8(zeros(height,width));

    k1 = high1 / low1;
    k2 = (high2 - high1) / (low2 - low1);
    k3 = (255 - high2) / (255 - low2);

    gray = double(gray);
        for i = 1:height
           for j = 1 : width
                if gray(i, j) <= low1
                extend(i ,j) = k1 * gray(i, j);
                else
                    if gray(i, j) <= low2 && gray(i, j) > low1
                         extend(i, j) = k2 * (gray(i, j) - low1) + high1;
                    else
                     extend(i, j) = k3 * (gray(i, j) - low2) + high2;
                    end
                end
           end
        end
end

%均衡化
function gray=grayto5(gray)
    gray=im2double(gray);
    [m,n]=size(gray);
    [count,x]=imhist(gray);
    l=find(count~=0);
    min1=min(count(l));
    for j=1:length(l)
        CDF=sum(count(l(1:j)));
        P=find(gray==x(l(j)));
        gray(P)=(CDF-min1)/(m*n-min1);
    end
end
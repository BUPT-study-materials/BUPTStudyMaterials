a=imread('pout.tif');
figure(1);

subplot(2,6,1);
imshow(a);
title('ԭͼ��');

subplot(2,6,7);
imhist(a);
title('�Ҷ�ֱ��ͼ');

subplot(2,6,2);
a1=grayto1(a);
imshow(a1);
title('��ɫ�任��');

subplot(2,6,8);
imhist(a1);
title('�Ҷ�ֱ��ͼ');

subplot(2,6,3);
a1=grayto2(a);
imshow(a1);
title('�����任��');

subplot(2,6,9);
imhist(a1);
title('�Ҷ�ֱ��ͼ');

subplot(2,6,4);
a1=grayto3(a,0.8);
imshow(a1);
title('�ݴα任��');

subplot(2,6,10);
imhist(a1);
title('�Ҷ�ֱ��ͼ');

subplot(2,6,5);
a1=grayto4(a,0.28*255,0.7*255,0*255,1*255);
imshow(a1);
title('�Աȶ������');

subplot(2,6,11);
imhist(a1);
title('�Ҷ�ֱ��ͼ');

subplot(2,6,6);
a1=grayto5(a);
imshow(a);
title('ֱ��ͼ���⻯��');

subplot(2,6,12);
imhist(a1);
title('�Ҷ�ֱ��ͼ');

%��ɫ
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

%�����任
function  logarithm=grayto2(gray)
    temp=mat2gray(gray);
    temp1 = log(1 + 10 * temp)/log(1 + 10);                       
    logarithm = uint8(temp1*(255 - 0) + 0);
end

%�ݴα任
function power=grayto3(gray,p)
    temp=mat2gray(gray);
    temp1 = temp.^p;                       
    power = uint8(temp1*(255 - 0) + 0);
end

%�Աȶ�����
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

%���⻯
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
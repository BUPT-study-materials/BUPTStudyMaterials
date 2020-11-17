% I = imread('播音员（gray）.jpg','jpg');%原图
% 
% I_gray=I;%转换为灰度图
% 
% 
% subplot(121),imshow(I);
% 
% 
% 
% I_double=double(I_gray);%转换为double
% 
% [wid,len]=size(I_gray);%图像的大小
% 
% 
% 
% ColorLevelss=256;%灰度级
% 
% 直方图
% 
% hist=zeros(ColorLevelss,1);
% 
% 计算直方图
% 
% for i=1:wid
% 
%     for j=1:len
% 
%         m=I_gray(i,j)+1;%图像的灰度级m
% 
%         hist(m)=hist(m)+1;%灰度值为i的像素和
% 
%     end
% 
% end
% 
% 直方图归一化
% 
% hist=hist/(wid*len);%各灰度值概率 Pi
% 
% miuT=0;%定义总体均值
% 
% for m=1:ColorLevelss
% 
%     miuT=miuT+(m-1)*hist(m);  %总体均值
% 
% end
% 
% xigmaB2=0;%
% 
% for mindex=1:ColorLevelss
% 
%     threshold=mindex-1;%设定阈值
% 
%     omega1=0;%目标概率
% 
%     omega2=0;%背景概率
% 
%     for m=1:threshold-1
% 
%         omega1=omega1+hist(m);% 目标概率 W0
% 
%     end
% 
%     omega2=1-omega1; %背景的概率 W1
% 
%     M1=0;%目标的平均灰度值
% 
%     M2=0;%背景的平均灰度值
% 
%     for m=1:ColorLevelss
% 
%         if m<threshold
% 
%             M1=M1+(m-1)*hist(m);%目标 i*pi的累加值[1 threshold]
% 
%         else
% 
%             M2=M2+(m-1)*hist(m);%背景 i*pi的累加值[threshold m]
% 
%         end
% 
%     end
% 
%     M1=M1/omega1;%目标的平均灰度值
% 
%     M2=M2/omega2;%背景的平均灰度值
% 
%     xigmaB21=omega1*(M1-miuT)^2+omega2*(M2-miuT)^2;%最大方差
% 
%     xigma(mindex)=xigmaB21;%先设定一个值 再遍历所有灰度级
% 
%     找到xigmaB21的值最大
% 
%     if xigmaB21>xigmaB2
% 
%         finalT=threshold;%找到阈值 灰度级
% 
%         xigmaB2=xigmaB21;%方差为最大
% 
%     end
% 
% end
% 
% 阈值归一化
% 
% fT=finalT/255;
% 
% for i=1:wid
% 
%      for j=1:len
% 
%          if I_double(i,j)>finalT %大于所设定的均值 则为目标
% 
%              bin(i,j)=0;
% 
%          else
% 
%              bin(i,j)=1;
% 
%          end
% 
%      end
% 
% end
% 
% subplot(122),imshow(bin);


% img = imread('车牌图像.jpg','jpg');%原图
% 
%  I_gray=rgb2gray(img);%转换为灰度图
% 
%  
% 
% subplot(121),imshow(img);
% 
% 
% %转换为双精度
% 
% I_double=double(I_gray);
% 
% [wid,len]=size(I_gray);%图像的大小
% 
% %灰度级
% 
% ColorLevels=256;
% 
% %直方图
% 
% hist=zeros(ColorLevels,1);
% 
% %计算直方图
% 
% for i=1:wid
% 
%     for j=1:len
% 
%         m=I_gray(i,j)+1;%图像的灰度级m
% 
%         hist(m)=hist(m)+1;%灰度值为i的像素和
% 
%     end
% 
% end
% 
% %直方图归一化
% 
% hist=hist/(wid*len);%各灰度值概率 Pi
% 
% miuT=0;%定义总体均值
% 
% for m=1:ColorLevels
% 
%     miuT=miuT+(m-1)*hist(m);  %总体均值
% 
% end
% 
% xigmaB2=0;%
% 
% for mindex=1:ColorLevels
% 
%     threshold=mindex-1;%设定阈值
% 
%     omega1=0;%目标概率
% 
%     omega2=0;%背景概率
% 
%     for m=1:threshold-1
% 
%         omega1=omega1+hist(m);% 目标概率 W0
% 
%     end
% 
%     omega2=1-omega1; %背景的概率 W1
% 
%     M1=0;%目标的平均灰度值
% 
%     M2=0;%背景的平均灰度值
% 
%     for m=1:ColorLevels
% 
%         if m<threshold
% 
%             M1=M1+(m-1)*hist(m);%目标 i*pi的累加值[1 threshold]
% 
%         else
% 
%             M2=M2+(m-1)*hist(m);%背景 i*pi的累加值[threshold m]
% 
%         end
% 
%     end
% 
%     M1=M1/omega1;%目标的平均灰度值
% 
%     M2=M2/omega2;%背景的平均灰度值
% 
%     xigmaB21=omega1*(M1-miuT)^2+omega2*(M2-miuT)^2;%最大方差
% 
%     xigma(mindex)=xigmaB21;%先设定一个值 再遍历所有灰度级
% 
%     %找到xigmaB21的值最大
% 
%     if xigmaB21>xigmaB2
% 
%         finalT=threshold;%找到阈值 灰度级
% 
%         xigmaB2=xigmaB21;%方差为最大
% 
%     end
% 
% end
% 
% %阈值归一化
% 
% fT=finalT/255;
% 
% for i=1:wid
% 
%      for j=1:len
% 
%          if I_double(i,j)>finalT %大于所设定的均值 则为目标
% 
%              bin(i,j)=0;
% 
%          else
% 
%              bin(i,j)=1;
% 
%          end
% 
%      end
% 
% end
% 
% subplot(122),imshow(bin);



%  I=imread('图1.jpg');
% %I=imread('车牌图像.jpg')
% %I=imread('播音员（gray）.jpg')
% I=rgb2gray(I);
%   subplot(1,2,1);
%   imshow(I);
%   title('原始图像');
%   I=double(I);
%   H=[0 -1 0
%     -1 5 -1
%     0 -1 0];
%   J=conv2(I,H,'same');
%   subplot(1,2,2);
%   imshow(J,[]);
%   title('拉普拉斯算子增强图像');
  
% 
% I=imread('播音员（gray）.jpg');
% I=rgb2gray(I);
% [width,height]=size(I); 
% level=graythresh(I); 
% BW=imbinarize(I,level); 
% figure ;
% imshow(BW);


   I=imread('图1.jpg');
%    x=imread('播音员（gray）.jpg','jpg'); 
% [m,n]=size(x); 
% n=n/3;
% figure,imshow(x); 
% 
% x=double(x); 
% 
% b=zeros(m,n); 
% 
% c=zeros(m,n); 
% 
% for i=1:m-2 
% 
%     for j=1:n-2 
% 
%         b(i+1,j+1)=x(i,j)-x(i+1,j+1); 
% 
%         c(i+1,j+1)=x(i,j+1)-x(i+1,j); 
% 
%         b(i+1,j+1)=sqrt(b(i+1,j+1)^2+c(i+1,j+1)^2)+100; 
% 
%     end
% 
% end
% 
% figure;imshow(uint8(b))

   
% I=imread('车牌图像.jpg');
% I=rgb2gray(I);
% [H,W]=size(I);
% M=double(I);
% J=M;
%   for i=2:H-1
%        for j=2:W-1
%         J(i,j)=4*M(i,j)-[M(i+1,j)+M(i-1,j)+M(i,j+1)+M(i,j-1)];
%       end;
%   end;
% subplot(1,2,1);imshow(I);title('原图');
% subplot(1,2,2);imshow(uint8(J));title('锐化处理后的图');
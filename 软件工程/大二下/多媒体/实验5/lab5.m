% I = imread('����Ա��gray��.jpg','jpg');%ԭͼ
% 
% I_gray=I;%ת��Ϊ�Ҷ�ͼ
% 
% 
% subplot(121),imshow(I);
% 
% 
% 
% I_double=double(I_gray);%ת��Ϊdouble
% 
% [wid,len]=size(I_gray);%ͼ��Ĵ�С
% 
% 
% 
% ColorLevelss=256;%�Ҷȼ�
% 
% ֱ��ͼ
% 
% hist=zeros(ColorLevelss,1);
% 
% ����ֱ��ͼ
% 
% for i=1:wid
% 
%     for j=1:len
% 
%         m=I_gray(i,j)+1;%ͼ��ĻҶȼ�m
% 
%         hist(m)=hist(m)+1;%�Ҷ�ֵΪi�����غ�
% 
%     end
% 
% end
% 
% ֱ��ͼ��һ��
% 
% hist=hist/(wid*len);%���Ҷ�ֵ���� Pi
% 
% miuT=0;%���������ֵ
% 
% for m=1:ColorLevelss
% 
%     miuT=miuT+(m-1)*hist(m);  %�����ֵ
% 
% end
% 
% xigmaB2=0;%
% 
% for mindex=1:ColorLevelss
% 
%     threshold=mindex-1;%�趨��ֵ
% 
%     omega1=0;%Ŀ�����
% 
%     omega2=0;%��������
% 
%     for m=1:threshold-1
% 
%         omega1=omega1+hist(m);% Ŀ����� W0
% 
%     end
% 
%     omega2=1-omega1; %�����ĸ��� W1
% 
%     M1=0;%Ŀ���ƽ���Ҷ�ֵ
% 
%     M2=0;%������ƽ���Ҷ�ֵ
% 
%     for m=1:ColorLevelss
% 
%         if m<threshold
% 
%             M1=M1+(m-1)*hist(m);%Ŀ�� i*pi���ۼ�ֵ[1 threshold]
% 
%         else
% 
%             M2=M2+(m-1)*hist(m);%���� i*pi���ۼ�ֵ[threshold m]
% 
%         end
% 
%     end
% 
%     M1=M1/omega1;%Ŀ���ƽ���Ҷ�ֵ
% 
%     M2=M2/omega2;%������ƽ���Ҷ�ֵ
% 
%     xigmaB21=omega1*(M1-miuT)^2+omega2*(M2-miuT)^2;%��󷽲�
% 
%     xigma(mindex)=xigmaB21;%���趨һ��ֵ �ٱ������лҶȼ�
% 
%     �ҵ�xigmaB21��ֵ���
% 
%     if xigmaB21>xigmaB2
% 
%         finalT=threshold;%�ҵ���ֵ �Ҷȼ�
% 
%         xigmaB2=xigmaB21;%����Ϊ���
% 
%     end
% 
% end
% 
% ��ֵ��һ��
% 
% fT=finalT/255;
% 
% for i=1:wid
% 
%      for j=1:len
% 
%          if I_double(i,j)>finalT %�������趨�ľ�ֵ ��ΪĿ��
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


% img = imread('����ͼ��.jpg','jpg');%ԭͼ
% 
%  I_gray=rgb2gray(img);%ת��Ϊ�Ҷ�ͼ
% 
%  
% 
% subplot(121),imshow(img);
% 
% 
% %ת��Ϊ˫����
% 
% I_double=double(I_gray);
% 
% [wid,len]=size(I_gray);%ͼ��Ĵ�С
% 
% %�Ҷȼ�
% 
% ColorLevels=256;
% 
% %ֱ��ͼ
% 
% hist=zeros(ColorLevels,1);
% 
% %����ֱ��ͼ
% 
% for i=1:wid
% 
%     for j=1:len
% 
%         m=I_gray(i,j)+1;%ͼ��ĻҶȼ�m
% 
%         hist(m)=hist(m)+1;%�Ҷ�ֵΪi�����غ�
% 
%     end
% 
% end
% 
% %ֱ��ͼ��һ��
% 
% hist=hist/(wid*len);%���Ҷ�ֵ���� Pi
% 
% miuT=0;%���������ֵ
% 
% for m=1:ColorLevels
% 
%     miuT=miuT+(m-1)*hist(m);  %�����ֵ
% 
% end
% 
% xigmaB2=0;%
% 
% for mindex=1:ColorLevels
% 
%     threshold=mindex-1;%�趨��ֵ
% 
%     omega1=0;%Ŀ�����
% 
%     omega2=0;%��������
% 
%     for m=1:threshold-1
% 
%         omega1=omega1+hist(m);% Ŀ����� W0
% 
%     end
% 
%     omega2=1-omega1; %�����ĸ��� W1
% 
%     M1=0;%Ŀ���ƽ���Ҷ�ֵ
% 
%     M2=0;%������ƽ���Ҷ�ֵ
% 
%     for m=1:ColorLevels
% 
%         if m<threshold
% 
%             M1=M1+(m-1)*hist(m);%Ŀ�� i*pi���ۼ�ֵ[1 threshold]
% 
%         else
% 
%             M2=M2+(m-1)*hist(m);%���� i*pi���ۼ�ֵ[threshold m]
% 
%         end
% 
%     end
% 
%     M1=M1/omega1;%Ŀ���ƽ���Ҷ�ֵ
% 
%     M2=M2/omega2;%������ƽ���Ҷ�ֵ
% 
%     xigmaB21=omega1*(M1-miuT)^2+omega2*(M2-miuT)^2;%��󷽲�
% 
%     xigma(mindex)=xigmaB21;%���趨һ��ֵ �ٱ������лҶȼ�
% 
%     %�ҵ�xigmaB21��ֵ���
% 
%     if xigmaB21>xigmaB2
% 
%         finalT=threshold;%�ҵ���ֵ �Ҷȼ�
% 
%         xigmaB2=xigmaB21;%����Ϊ���
% 
%     end
% 
% end
% 
% %��ֵ��һ��
% 
% fT=finalT/255;
% 
% for i=1:wid
% 
%      for j=1:len
% 
%          if I_double(i,j)>finalT %�������趨�ľ�ֵ ��ΪĿ��
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



%  I=imread('ͼ1.jpg');
% %I=imread('����ͼ��.jpg')
% %I=imread('����Ա��gray��.jpg')
% I=rgb2gray(I);
%   subplot(1,2,1);
%   imshow(I);
%   title('ԭʼͼ��');
%   I=double(I);
%   H=[0 -1 0
%     -1 5 -1
%     0 -1 0];
%   J=conv2(I,H,'same');
%   subplot(1,2,2);
%   imshow(J,[]);
%   title('������˹������ǿͼ��');
  
% 
% I=imread('����Ա��gray��.jpg');
% I=rgb2gray(I);
% [width,height]=size(I); 
% level=graythresh(I); 
% BW=imbinarize(I,level); 
% figure ;
% imshow(BW);


   I=imread('ͼ1.jpg');
%    x=imread('����Ա��gray��.jpg','jpg'); 
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

   
% I=imread('����ͼ��.jpg');
% I=rgb2gray(I);
% [H,W]=size(I);
% M=double(I);
% J=M;
%   for i=2:H-1
%        for j=2:W-1
%         J(i,j)=4*M(i,j)-[M(i+1,j)+M(i-1,j)+M(i,j+1)+M(i,j-1)];
%       end;
%   end;
% subplot(1,2,1);imshow(I);title('ԭͼ');
% subplot(1,2,2);imshow(uint8(J));title('�񻯴�����ͼ');
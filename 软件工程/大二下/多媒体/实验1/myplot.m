x=imread('flowers.tif');
figure(1);
imshow(x);
title('ԭͼ');

figure(2);
a=rgbtogray(x);
imshow(a);
title('�Ҷ�ͼ');

figure(3);
b=graytobw(a);
imshow(b);
title('��ֵͼ');

figure(4);
rgbtohist(a);
title('ֱ��ͼ');

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
alpha=0.5; %��ֵ
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
column=size(I,2);%2��dimision
N=zeros(1,256);%zeros(256)����256x256����
for i=1:row
    for j=1:column
        k=I(i,j);
        N(k+1)=N(k+1)+1;%��¼ÿ���Ҷ�ֵ��������
    end
end
subplot(121);imshow(I);%subplot�����ڷ�Ϊ1x2�������ڣ������ڵ�һ��С���ڻ�ͼ
subplot(1,2,2);bar(N);%subplot(122)=subplot(1,2,2)
%bar��������ֱ��ͼ��ΪN��ÿһ�е�ÿһ��Ԫ�ػ���һ����
axis tight;%����������
end
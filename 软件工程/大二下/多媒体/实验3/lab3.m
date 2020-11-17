t=imread('lena_noise.bmp');
t1=imread('cat.jpg');

[hgram1,x]=imhist(t1);

%t3=histeq(t,hgram1);
t3=boxfilter(t,3);

subplot(2,1,1);
imshow(t);title('原图');
subplot(2,1,2);
imshow(t3);title('box滤波');



t3=fspecial1(t);

function imDst = boxfilter(imSrc, r)
[hei, wid] = size(imSrc);
imDst = zeros(size(imSrc));

%cumulative sum over Y axis
imCum = cumsum(imSrc, 1);%列向量主次向上求和，输出同大小的矩阵
%difference over Y axis
imDst(1:r+1, :) = imCum(1+r:2*r+1, :);
imDst(r+2:hei-r, :) = imCum(2*r+2:hei, :) - imCum(1:hei-2*r-1, :);
imDst(hei-r+1:hei, :) = repmat(imCum(hei, :), [r, 1]) - imCum(hei-2*r:hei-r-1, :);

%cumulative sum over X axis
imCum = cumsum(imDst, 2);
%difference over Y axis
imDst(:, 1:r+1) = imCum(:, 1+r:2*r+1);
imDst(:, r+2:wid-r) = imCum(:, 2*r+2:wid) - imCum(:, 1:wid-2*r-1);
imDst(:, wid-r+1:wid) = repmat(imCum(:, wid), [1, r]) - imCum(:, wid-2*r:wid-r-1);
end

function desimg=fspecial1(originimg)
[ori_row,ori_col]=size(originimg);
 
sigma = 1.6;      %sigma赋值
N = 7;            %大小是（2N+1）×（2N+1）
N_row = 2*N+1;
 
OriImage_noise = imnoise(originimg,'gaussian'); %加噪
 
gausFilter = fspecial('gaussian',[N_row N_row],sigma);      %matlab 自带高斯模板滤波
 
H = [];                                        %求高斯模板H
for i=1:N_row
    for j=1:N_row
        fenzi=double((i-N-1)^2+(j-N-1)^2);
        H(i,j)=exp(-fenzi/(2*sigma*sigma))/(2*pi*sigma);
    end
end
H=H/sum(H(:));              %归一化
 
desimg=zeros(ori_row,ori_col);            %滤波后图像
for i=1:ori_row                           
    for j=1:ori_col
        desimg(i,j)=OriImage_noise(i,j);
    end
end
 
temp=[];
for ai=N+1:ori_row-N-1
    for aj=N+1:ori_col-N-1
        temp=0;
        for bi=1:N_row
            for bj=1:N_row
                temp= temp+(desimg(ai+bi-N,aj+bj-N)*H(bi,bj));
            end
        end
        desimg(ai,aj)=temp;
    end
end
desimg=uint8(desimg);
 
 
subplot(2,1,1);imshow(originimg);title('原图');
subplot(2,1,2);imshow(desimg);title('高斯滤波');

end

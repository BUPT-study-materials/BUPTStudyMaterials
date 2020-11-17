#pragma once
#include<easyx.h>
#include<ctime>
#include<iostream>
using namespace std;


class MyBoard
{
public:
	MyBoard();
	~MyBoard();
	void startGame() {
		int sign = 1;
		int cheatSignOfMode = 0;
		int cheatSign = 0;
		int frogSign = 0;
		int frogx(0), frogy(0);
		MOUSEMSG msg;
		IMAGE background;
		loadimage(&background, _T("background.JPG"));
		IMAGE frog;
		loadimage(&frog, _T("frog.png"));
		setbkcolor(getpixel(0, 0));
		setbkmode(OPAQUE);//�������屳��ɫΪ����ɫ

		/*****************************************************************��Ϸѭ������***********************************************************************/

		while (sign) {
			cleardevice();//����
			int isCorrect = 0;
			double length = 1700 / (6 * size_ + 1);//���ݷ���������߳�
			srand(int(time(0)));
			/*��������Ĳ�һ���ķ���*/
			int correctX = rand() % size_;
			int correctY = rand() % size_;
			/*�����������ɫ*/
			int randR = rand() % (255 - 4 * (15 - size_)) + 2 * (15 - size_);
			int randG = rand() % (255 - 4 * (15 - size_)) + 2 * (15 - size_);
			int randB = rand() % (255 - 4 * (15 - size_)) + 2 * (15 - size_);
			leftTime_ = 10000;//����ʣ��ʱ��
			/**************************************��ӡ������***********************************/
			putimage(0, 0, 360, 640, &background, 0, 0);

			/**************************************��ӡ����*************************************/
			for (int x = 0; x < size_; x++)
				for (int y = 0; y < size_; y++) {
					if (x == correctX && y == correctY) {
						setfillcolor(RGB(randR + 2 * (15 - size_), randG + 2 * (15 - size_), randB + 2 * (15 - size_)));
						nowX = int(10 + length * x * 1.2 + length * 0.2) + int(10 + length * x * 1.2 + length * 1.2);
						nowX = nowX / 2;
						nowY = int(40 + length * y * 1.2 + length * 0.2) + int(40 + length * y * 1.2 + length * 1.2);
						nowY = nowY / 2;						
						}
					else {
						setfillcolor(RGB(randR, randG, randB));
					}
					solidroundrect(
						int(10 + length * x * 1.2 + length * 0.2),
						int(40 + length * y * 1.2 + length * 0.2),
						int(10 + length * x * 1.2 + length * 1.2),
						int(40 + length * y * 1.2 + length * 1.2),
						int(length * 0.2),
						int(length * 0.2)
					);
				}
			for (int i = 0; i < frogSign; i++) {
				frogx = 20 + rand() % 280;
				frogy = 390 + rand() % 150;
				putimage(frogx, frogy, &frog);
				}
			/*******************************��ӡ��ͣ��ť*********************************/
			//todo

			/******************************��ӡ�ؿ�����׼������ʱ********************************/
			LOGFONT f;//����			
			gettextstyle(&f);						// ��ȡ��ǰ��������
			f.lfHeight = 24;						// ��������߶�Ϊ 48
			_tcscpy_s(f.lfFaceName, _T("����"));
			f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
			f.lfPitchAndFamily = FIXED_PITCH;
			settextstyle(&f);
			TCHAR levelText[] = _T("Level:");
			outtextxy(30, 15, levelText);
			TCHAR levelNum[10];//�ؿ���
			TCHAR LeftTime[5000];//ʣ��ʱ��
			TCHAR totalScore[5000];//ʣ��ʱ��
			TCHAR s1[] = _T("�~");//����
			TCHAR s2[] = _T("cheat mode");
			TCHAR GameOver[] = _T("Game Over");
			TCHAR UCheat[] = _T("���㿪�˽���ָ");
			TCHAR YourScoreIs[] = _T("�����յ÷�Ϊ��");
			_stprintf_s(levelNum, _T("%d"), level_);
			_stprintf_s(totalScore, _T("%d"), totalScore_);
			outtextxy(100, 15, levelNum);

			/***********************************************************************/


			/********************************���ͨ��������***********************************/
			while (!isCorrect && leftTime_ > 0) {
				BeginBatchDraw();
				if (MouseHit()) {
					msg = GetMouseMsg();
					switch (msg.uMsg)
					{
					case WM_LBUTTONDOWN:
						if (msg.x >= 10 + length * 0.2 && msg.x <= 350 - length * 0.2
							&& msg.y >= 40 + length * 0.2 && msg.y <= 380 - length * 0.2) {
							if (msg.x >= 10 + length * correctX * 1.2 + length * 0.2 && msg.x <= 10 + length * correctX * 1.2 + length * 1.2
								&& msg.y >= 40 + length * correctY * 1.2 + length * 0.2 && msg.y <= 40 + length * correctY * 1.2 + length * 1.2)
								isCorrect = 1;
						}
						break;
					case WM_RBUTTONDOWN:
						cheatSignOfMode = 1;
						cheatSign = 1;
						break;
					case WM_RBUTTONDBLCLK:
						cheatSign = 0;
						/*************************************���´�ӡ*****************************/
						for (int x = 0; x < size_; x++)
							for (int y = 0; y < size_; y++) {
								if (x == correctX && y == correctY) {
									setfillcolor(RGB(randR + 2 * (15 - size_), randG + 2 * (15 - size_), randB + 2 * (15 - size_)));
									nowX = int(10 + length * x * 1.2 + length * 0.2) + int(10 + length * x * 1.2 + length * 1.2);
									nowX = nowX / 2;
									nowY = int(40 + length * y * 1.2 + length * 0.2) + int(40 + length * y * 1.2 + length * 1.2);
									nowY = nowY / 2;
								}
								else {
									setfillcolor(RGB(randR, randG, randB));
								}
								solidroundrect(
									int(10 + length * x * 1.2 + length * 0.2),
									int(40 + length * y * 1.2 + length * 0.2),
									int(10 + length * x * 1.2 + length * 1.2),
									int(40 + length * y * 1.2 + length * 1.2),
									int(length * 0.2),
									int(length * 0.2)
								);
							}

						/*************************************************************************/

						break;
					case WM_MOUSEWHEEL:
						leftTime_ += 5000;
						frogSign++;
						frogx = 20 + rand() % 280;
						frogy = 390 + rand() % 150;
						putimage(frogx,frogy, &frog);
						break;
					default:
						break;
					}
				}
				Sleep(5);
				leftTime_ = leftTime_ - 5;
				
				//��ӡ����ʱ
				putimage(180, 0,360,43, &background, 0, 0);//��ӡһ����ɫ����
				int move = 15;

				//��������
				gettextstyle(&f);						// ��ȡ��ǰ��������
				f.lfHeight = 20;						
				_tcscpy_s(f.lfFaceName, _T("����"));
				f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
				f.lfPitchAndFamily = FIXED_PITCH;
				settextstyle(&f);

				TCHAR TimeText[] = _T("Time:");
				outtextxy(200+move, 15, TimeText);
				_stprintf_s(LeftTime, _T("%d"), leftTime_%1000);
				outtextxy(285+move, 15, LeftTime);
				_stprintf_s(LeftTime, _T("%d"), leftTime_ / 1000);
				outtextxy(260+move, 15, LeftTime);
				TCHAR Point_[] = _T(".");
				outtextxy(275+move, 15, Point_);
				//����
				setbkmode(TRANSPARENT);
				if (cheatSign == 1) {
					outtextxy(nowX - 7, nowY - 18, s1);
				}
				if (cheatSignOfMode == 1) {
					//���������岢��ӡ
					gettextstyle(&f);
					f.lfHeight = 30;
					_tcscpy_s(f.lfFaceName, _T("MS PGothicW"));
					f.lfQuality = ANTIALIASED_QUALITY;
					f.lfPitchAndFamily = FIXED_PITCH;
					settextstyle(&f);
					outtextxy(102,30, s2);

					//�޸Ļ�ԭ������
					gettextstyle(&f);						
					f.lfHeight = 30;						
					_tcscpy_s(f.lfFaceName, _T("����"));
					f.lfQuality = ANTIALIASED_QUALITY;		
					f.lfPitchAndFamily = FIXED_PITCH;
					settextstyle(&f);
				}
				EndBatchDraw();
			}
			/*�ж��Ƿ�Game Over*/
			if (!isCorrect) {
				//game over
				sign = 0;
				
				//��ӡ��������
				putimage(0, 0, 360, 640, &background, 0, 0);
				//��������
				gettextstyle(&f);						// ��ȡ��ǰ��������
				f.lfHeight = 63;						// ��������߶�Ϊ 48
				_tcscpy_s(f.lfFaceName, _T("����"));
				f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
				f.lfPitchAndFamily = FIXED_PITCH;
				settextstyle(&f);
				outtextxy(40, 100, GameOver);

				gettextstyle(&f);						// ��ȡ��ǰ��������
				f.lfHeight = 30;						// ��������߶�Ϊ 48
				_tcscpy_s(f.lfFaceName, _T("����"));
				settextstyle(&f);
				outtextxy(70, 300, YourScoreIs);
				outtextxy(270, 300,totalScore);
				if (cheatSignOfMode == 1) {
				outtextxy(70, 330, UCheat);
				}
				cin.get();
			}
				
			/*��δGame Over����ı����*/
			else {
				totalScore_ = totalScore_ + level_ * leftTime_ / 1000;
				if (size_ < 10)
					size_++;
				level_++;
			}
		}

		/****************************************************************************************************************************************************/
	}
private:
	int size_ = 2;
	int leftTime_ = 10000;
	int level_ = 1;
	int totalScore_ = 0;
	int test = 1;
	int nowX = 0;
	int nowY = 0;
};

MyBoard::MyBoard()
{
}

MyBoard::~MyBoard()
{
}
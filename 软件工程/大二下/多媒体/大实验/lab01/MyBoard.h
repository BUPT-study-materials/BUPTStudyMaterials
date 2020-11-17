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
		setbkmode(OPAQUE);//设置字体背景色为背景色

		/*****************************************************************游戏循环流程***********************************************************************/

		while (sign) {
			cleardevice();//清屏
			int isCorrect = 0;
			double length = 1700 / (6 * size_ + 1);//根据方块数计算边长
			srand(int(time(0)));
			/*生成随机的不一样的方块*/
			int correctX = rand() % size_;
			int correctY = rand() % size_;
			/*生成随机的颜色*/
			int randR = rand() % (255 - 4 * (15 - size_)) + 2 * (15 - size_);
			int randG = rand() % (255 - 4 * (15 - size_)) + 2 * (15 - size_);
			int randB = rand() % (255 - 4 * (15 - size_)) + 2 * (15 - size_);
			leftTime_ = 10000;//重置剩余时间
			/**************************************打印背景板***********************************/
			putimage(0, 0, 360, 640, &background, 0, 0);

			/**************************************打印方块*************************************/
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
			/*******************************打印暂停按钮*********************************/
			//todo

			/******************************打印关卡数和准备倒计时********************************/
			LOGFONT f;//字体			
			gettextstyle(&f);						// 获取当前字体设置
			f.lfHeight = 24;						// 设置字体高度为 48
			_tcscpy_s(f.lfFaceName, _T("黑体"));
			f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
			f.lfPitchAndFamily = FIXED_PITCH;
			settextstyle(&f);
			TCHAR levelText[] = _T("Level:");
			outtextxy(30, 15, levelText);
			TCHAR levelNum[10];//关卡数
			TCHAR LeftTime[5000];//剩余时间
			TCHAR totalScore[5000];//剩余时间
			TCHAR s1[] = _T("▇");//作弊
			TCHAR s2[] = _T("cheat mode");
			TCHAR GameOver[] = _T("Game Over");
			TCHAR UCheat[] = _T("但你开了金手指");
			TCHAR YourScoreIs[] = _T("你最终得分为：");
			_stprintf_s(levelNum, _T("%d"), level_);
			_stprintf_s(totalScore, _T("%d"), totalScore_);
			outtextxy(100, 15, levelNum);

			/***********************************************************************/


			/********************************玩家通过鼠标操作***********************************/
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
						/*************************************重新打印*****************************/
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
				
				//打印倒计时
				putimage(180, 0,360,43, &background, 0, 0);//打印一个绿色背景
				int move = 15;

				//设置字体
				gettextstyle(&f);						// 获取当前字体设置
				f.lfHeight = 20;						
				_tcscpy_s(f.lfFaceName, _T("黑体"));
				f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
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
				//作弊
				setbkmode(TRANSPARENT);
				if (cheatSign == 1) {
					outtextxy(nowX - 7, nowY - 18, s1);
				}
				if (cheatSignOfMode == 1) {
					//设置新字体并打印
					gettextstyle(&f);
					f.lfHeight = 30;
					_tcscpy_s(f.lfFaceName, _T("MS PGothicW"));
					f.lfQuality = ANTIALIASED_QUALITY;
					f.lfPitchAndFamily = FIXED_PITCH;
					settextstyle(&f);
					outtextxy(102,30, s2);

					//修改回原来字体
					gettextstyle(&f);						
					f.lfHeight = 30;						
					_tcscpy_s(f.lfFaceName, _T("黑体"));
					f.lfQuality = ANTIALIASED_QUALITY;		
					f.lfPitchAndFamily = FIXED_PITCH;
					settextstyle(&f);
				}
				EndBatchDraw();
			}
			/*判断是否Game Over*/
			if (!isCorrect) {
				//game over
				sign = 0;
				
				//打印结束界面
				putimage(0, 0, 360, 640, &background, 0, 0);
				//设置字体
				gettextstyle(&f);						// 获取当前字体设置
				f.lfHeight = 63;						// 设置字体高度为 48
				_tcscpy_s(f.lfFaceName, _T("黑体"));
				f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
				f.lfPitchAndFamily = FIXED_PITCH;
				settextstyle(&f);
				outtextxy(40, 100, GameOver);

				gettextstyle(&f);						// 获取当前字体设置
				f.lfHeight = 30;						// 设置字体高度为 48
				_tcscpy_s(f.lfFaceName, _T("宋体"));
				settextstyle(&f);
				outtextxy(70, 300, YourScoreIs);
				outtextxy(270, 300,totalScore);
				if (cheatSignOfMode == 1) {
				outtextxy(70, 330, UCheat);
				}
				cin.get();
			}
				
			/*若未Game Over，则改变分数*/
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
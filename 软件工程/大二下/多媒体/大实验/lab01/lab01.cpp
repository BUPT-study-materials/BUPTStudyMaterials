// lab01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<Windows.h>
#include <iostream>
#include<easyx.h>
#include"MyBoard.h"
#include<fstream>
#include<windows.h>
#include<mmsystem.h>
#include<tchar.h>
#include<windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")

using namespace::std;
using namespace std;



int main()
{
	const int wight = 360;
	const int height = 640;

	initgraph(wight,height);
	IMAGE sceen,sceen1,sceen2,sceen3,sceen4,sceenNoMusic;
	IMAGE sceen1_1,sceen3_1,sceen4_1,share,seeU,frog;
	MOUSEMSG msg;
	int isMusic = 1;
	loadimage(&sceen, _T("sceen.JPG"));
	loadimage(&sceen1, _T("sceen1.JPG"));
	loadimage(&sceen2, _T("sceen2.JPG"));
	loadimage(&sceen3, _T("sceen3.JPG"));
	loadimage(&sceen4, _T("sceen4.JPG"));
	loadimage(&sceen1_1, _T("sceen1_1.JPG"));
	loadimage(&sceen3_1, _T("sceen3_1.JPG"));
	loadimage(&sceen4_1, _T("sceen4_1.JPG"));
	loadimage(&sceenNoMusic, _T("sceen_nomusic.JPG"));
	loadimage(&share, _T("share.JPG"));
	loadimage(&seeU, _T("seeU.JPG"));
	
	setbkcolor(getpixel(0,0));
	setbkmode(OPAQUE);//设置字体背景色为背景色

	//MCI_OPEN_PARMS OpenParms;//打开设备
	//OpenParms.lpstrDeviceType = NULL;// "mpegvideo";
	//OpenParms.lpstrElementName = _T("bgm.wav");
	//OpenParms.wDeviceID = NULL;
	////mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)& OpenParms);

	//MCI_PLAY_PARMS PlayParms;//播放文件
	//PlayParms.dwFrom = 0;
	
	putimage(0, 0, wight, height, &sceen,0,0);
	PlaySound(TEXT("bgm.wav"), NULL, SND_FILENAME | SND_ASYNC);
	//mciSendCommand(OpenParms.wDeviceID, MCI_PLAY, MCI_FROM, (DWORD)& PlayParms);

	while (true) {
		msg = GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			//开始
			if (msg.x >= 72 && msg.x <= 140 && msg.y >= 390 && msg.y <= 446) {
				MyBoard* board = new MyBoard();
				if (isMusic == 1) {
					putimage(0, 0, wight, height, &sceen1, 0, 0);
				}
				else {
					putimage(0, 0, wight, height, &sceen1_1, 0, 0);
				}
				Sleep(200);
				board->startGame();
				if (isMusic == 1) {
					putimage(0, 0, wight, height, &sceen, 0, 0);
				}
				else {
					putimage(0, 0, wight, height, &sceenNoMusic, 0, 0);
				}
			}
			//音乐
			else if (msg.x >= 216 && msg.x <= 277 && msg.y >= 390 && msg.y <= 446) {
				
				isMusic *= -1;
				if (isMusic == 1) {
					putimage(0, 0, wight, height, &sceen2, 0, 0);
					PlaySound(TEXT("bgm.wav"), NULL, SND_FILENAME | SND_ASYNC);
					//mciSendCommand(OpenParms.wDeviceID, MCI_RESUME, NULL, (DWORD)& PlayParms);
					Sleep(200);
					putimage(0, 0, wight, height, &sceen, 0, 0);
				}
				else {
					putimage(0, 0, wight, height, &sceen2, 0, 0);
					//mciSendCommand(OpenParms.wDeviceID, MCI_PAUSE, NULL, (DWORD)& PlayParms);
					PlaySound(TEXT("nobgm.wav"), NULL, SND_FILENAME | SND_ASYNC);
					Sleep(200);
					putimage(0, 0, wight, height, &sceenNoMusic, 0, 0);
				}
				
			}
			//分享
			else if (msg.x >= 72 && msg.x <= 140 && msg.y >= 490 && msg.y <= 560) {
				if (isMusic == 1) {
					putimage(0, 0, wight, height, &sceen3, 0, 0);
				}
				else {
					putimage(0, 0, wight, height, &sceen3_1, 0, 0);
				}
				Sleep(200);
				if (isMusic == 1) {
					putimage(0, 0, wight, height, &sceen, 0, 0);
				}
				else {
					putimage(0, 0, wight, height, &sceenNoMusic, 0, 0);
				}
					putimage(0, 0, wight, height, &share, 0, 0);
					cin.get();
					if (isMusic == 1) {
						putimage(0, 0, wight, height, &sceen, 0, 0);
					}
					else {
						putimage(0, 0, wight, height, &sceenNoMusic, 0, 0);
					}
			}
			//退出
			else if (msg.x >= 216 && msg.x <= 277 && msg.y >= 490 && msg.y <= 560) {
				if (isMusic == 1) {
					putimage(0, 0, wight, height, &sceen4, 0, 0);
				}
				else {
					putimage(0, 0, wight, height, &sceen4_1, 0, 0);
				}
				Sleep(200);
				if (isMusic == 1) {
					putimage(0, 0, wight, height, &sceen, 0, 0);
				}
				else {
					putimage(0, 0, wight, height, &sceenNoMusic, 0, 0);
				}
					putimage(0, 0, wight, height, &seeU, 0, 0);
				Sleep(1500);
				return 0;
			}
			else {
			}
			
			break;
		case WM_RBUTTONUP:
			return 0;	// 按鼠标右键退出程序
		default:
			break;
		}
	}
	closegraph();
}


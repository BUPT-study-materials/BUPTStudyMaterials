#include<fstream>
#include<iostream>
#include<windows.h>
#include<mmsystem.h>
#include<tchar.h>
#pragma comment(lib,"winmm.lib")
using namespace::std;
int main()
{
	MCI_OPEN_PARMS OpenParms;//打开设备
	OpenParms.lpstrDeviceType = NULL;// "mpegvideo";
	OpenParms.lpstrElementName = _T("bgm.wav");
	OpenParms.wDeviceID = NULL;
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT, (DWORD)& OpenParms);

	MCI_PLAY_PARMS PlayParms;//播放文件
	PlayParms.dwFrom = 0;
	while (1)
	{
		char ch = getchar();
		if (ch == 'p')//播放
		{
			mciSendCommand(OpenParms.wDeviceID, MCI_PLAY, MCI_FROM, (DWORD)& PlayParms);
		}
		if (ch == 'a')//暂停
		{
			mciSendCommand(OpenParms.wDeviceID, MCI_PAUSE, NULL, (DWORD)& PlayParms);
		}
		if (ch == 'r')//继续播放
		{
			mciSendCommand(OpenParms.wDeviceID, MCI_RESUME, NULL, (DWORD)& PlayParms);
		}
		if (ch == 's')//停止
		{
			mciSendCommand(OpenParms.wDeviceID, MCI_STOP, NULL, (DWORD)& PlayParms);
		}

	}

	getchar();

}
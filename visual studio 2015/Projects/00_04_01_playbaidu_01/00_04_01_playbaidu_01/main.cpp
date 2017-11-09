#define _CRI_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void openBaidu();
void closeBaidu();
void clickEvent();
void main() {

	openBaidu();
	Sleep(10000);
	clickEvent();
	Sleep(10000);
	closeBaidu();



	/*system("pause");*/

}

void clickEvent() {

	SetCursorPos(300, 420);
	Sleep(500);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);



}


void openBaidu() {

	ShellExecuteA(0, "open", "https://www.baidu.com/s?wd=java%E5%9F%B9%E8%AE%AD&rsv_spt=1&rsv_iqid=0x848648ff000e0566&issp=1&f=8&rsv_bp=0&rsv_idx=2&ie=utf-8&tn=78040160_35_pg&rsv_enter=1&rsv_sug3=7&rsv_sug1=5&rsv_sug7=101&rsv_sug2=0&inputT=3536&rsv_sug4=9319", 0, 0, 6);

}

void closeBaidu() {

	system("taskkill /f /im chrome.exe");

}



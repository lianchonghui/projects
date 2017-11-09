#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void main() {


	char cmd[30];
	int i;

	while (1) {

		for (i = 0;i <= 0xf;i++) {

		sprintf(cmd, "color %x%x", i, 0xf-i);
		system(cmd);
		Sleep(100);

		}
	}



}
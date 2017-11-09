#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

static int data;

int main2() {
	//1. char *指向的区域不允许改变
	//2. 如果同时出现两个scanf,当前一个scanf输入的是数字,后一个输入的是字符串,则第一次输入的回车符会被丢弃,
	//       后一个输入以后的字符串后的回车符会留在缓冲区.
	//   如果前一个scanf输入的是数字,后一个输入的是字符,子后一个字符无法输入,被前一个输入的回车符填充了
	//   所以,每次scanf都会留下一个回车符在缓冲区,如果下一个输入是字符,则被回车符填充,如果输入的是其他则回车符被丢弃   
	printf("%d\n", data);
	
	int num = 0;
	char  str[20];
	char c='a';
	printf("input a number\n");
	scanf("%d", &num);
	//getchar();
	printf("input a string\n");
	scanf("%s", str);

	printf("%d,%c", num, str[0]);

	getchar();
	getchar();
	return 0;
}


int main1() {

	int num = 0;
	printf("%d\n", num);  


	return 0;
}
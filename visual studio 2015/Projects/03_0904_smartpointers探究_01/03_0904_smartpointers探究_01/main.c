#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

static int data;

int main2() {
	//1. char *ָ�����������ı�
	//2. ���ͬʱ��������scanf,��ǰһ��scanf�����������,��һ����������ַ���,���һ������Ļس����ᱻ����,
	//       ��һ�������Ժ���ַ�����Ļس��������ڻ�����.
	//   ���ǰһ��scanf�����������,��һ����������ַ�,�Ӻ�һ���ַ��޷�����,��ǰһ������Ļس��������
	//   ����,ÿ��scanf��������һ���س����ڻ�����,�����һ���������ַ�,�򱻻س������,����������������س���������   
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
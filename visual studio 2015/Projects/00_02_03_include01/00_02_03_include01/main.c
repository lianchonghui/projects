#include<stdio.h>
#include"myHead.h"

int a = 10;
int b = 11;
void go();

void main() {
	
	//ȫ�ֱ�����ȫ�ֺ����������Ͷ���:
	//ȫ�ֱ�����ȫ�ֺ���������head�ļ�������(���Զ���,��һ�㲻��ͷ�ļ�����),ͨ��includeͷ�ļ����Ӵ�ȫ�ֱ����ͺ����Ŀɼ���
	//ȫ�ֱ���������:��go.c������main.c�е�ȫ�ֱ���,�����c,����ʡ��extern,�����c++�ͱ������extern,������벻ͨ��

	sayHello();

	printf("\n");

	go();

	getchar();
}
#include<stdio.h>
#include<stdlib.h>

void main() {

	printf("%d", sizeof('a'));//��ӡ1
	printf("\n%d", sizeof("a"));//��ӡ2,��ʾ�ַ�����β���Զ����Ͻ�����־'\0'

	putchar(104);
	putchar('\150');

	system("pause");
}
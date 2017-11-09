#include<stdio.h>
#include<stdlib.h>

void main() {

	printf("%d", sizeof('a'));//打印1
	printf("\n%d", sizeof("a"));//打印2,表示字符串结尾会自动加上结束标志'\0'

	putchar(104);
	putchar('\150');

	system("pause");
}
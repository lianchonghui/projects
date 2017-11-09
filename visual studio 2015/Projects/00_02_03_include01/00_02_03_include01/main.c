#include<stdio.h>
#include"myHead.h"

int a = 10;
int b = 11;
void go();

void main() {
	
	//全局变量和全局函数的声明和定义:
	//全局变量和全局函数可以在head文件中声明(可以定义,但一般不在头文件定义),通过include头文件来加大全局变量和函数的可见域
	//全局变量的声明:如go.c中引用main.c中的全局变量,如果是c,可以省略extern,如果是c++就必须加上extern,否则编译不通过

	sayHello();

	printf("\n");

	go();

	getchar();
}
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


int addA(int num, ...) {

	double last = 0.0;

	//创建一个va_list指针,并在内存中用va_start开辟首地址是va_list类型指针指向的包含num个大小的内存
	va_list args;

	va_start(args, num);

	//通过循环遍历所有参数,并通过va_arg()按指针和类型存储并返回参数值
	for (int i = 0;i < num;i++) {

		last+=va_arg(args, double);


	}
	//结束扫描参数
	va_end(args);

	return last;
}

int main() {
	//函数多参数问题

	//函数多参数的步骤
	//1.va_list指针定义内存地址
	//2.va_start开辟va_list指向的内存空间
	//3.循环扫描所有参数,通过va_arg遍历,按参数指定的类型写入内存,并返回其值
	//4.结束读取


	double res = addA(4, 12.0, 12.5, 13.0, 13.5);

	printf("%fl", res);

	getchar();
	return 0;
}
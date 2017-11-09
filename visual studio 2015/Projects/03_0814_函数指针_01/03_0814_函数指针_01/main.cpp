#include<iostream>
#include<stdlib.h>

using namespace std;
int jia(int a, int b);
int jian(int a, int b);
int change(int(*p)(int, int));
int(*changep(int(*p)(int, int)))(int, int);

int main() {

	//函数指针
	//int (* p)(int, int) = jia;//与下同等
	int(* p)(int, int)(jia);
	cout << p(1, 2) << endl;

	//函数指针作为参数
	change(jia);

	cout << "------------------" << endl;
	cout << p(1, 2) << endl;//3

	//changep改变了p(函数指针)的指向,并通过返回值赋给外部的p.(因为函数有副本机制,另外如果不用返回值,还可以通过参数是引用或者参数是二级指针的方式)
	p=changep(p);

	cout << p(1, 2) << endl;//-1

	system("pause");
	return 0;

}

int jia(int a, int b) {
	return a + b;
}

int jian(int a, int b) {
	return a - b;
}

//函数指针作为参数的情况
int change(int(*p)(int, int)) {
	
	cout << p(1, 2) << endl;

	//通过函数指针改变指针指向的函数，因为函数有副本机制，函数内部的函数指针p的改变对函数外的p没有影响
	p = jian;
	cout << p(1, 2) << endl;

	return 0;
}

//函数指针作为返回值的情况
//函数指针作为返回值的格式是：
//假如函数返回值是函数指针为:int(* )(int,int),这是一个匿名的函数指针.当其作为返回值的时候函数名和参数放在*号后面,
//如下是函数名为changep,参数是int(* p)(int,int)//注意,这个参数是一个函数指针,指针名为p

int(* changep(int(* p)(int,int)))(int, int) {
	p = jian;
	return p;
}
#include<iostream>
namespace my {
	namespace inmy {
	}
}
class myclass {
public:
	class inclass {
	};
	struct mystruct {
	};
	//namespace myns { }//类中应输入声明,namespace不是
};

int main() {

	myclass mc;
	myclass::inclass ic;
	myclass::mystruct ms;

	//对于数组,数组名其实是一个指针常量,不能修改其指向,
	//所以任何对数组赋值的方式是改变其指向的都会报错,左值不可修改

	int a1[3] = { 1,3,4 };
	//int a2[3] = a1;//错误,不能这样初始化
	//int a3[3];
	//a3 = a1;//错误,a3是不可以修改的左值

	int a4[3] = { 0 };
	//a4 = a1;//左值不可修改

	return 0;
}
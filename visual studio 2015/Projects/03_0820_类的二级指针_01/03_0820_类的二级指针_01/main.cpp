#include<iostream>

class mc {
private:
	int x;
	int y;
public:
	mc() {
		std::cout << "无参构造函数" << std::endl;
	}
	mc(int x, int y) 
	{
		std::cout << "有参构造" << std::endl;
		this->x = x;
		this->y = y;
	}
	~mc() {
		std::cout << "析构函数" << std::endl;
	}
	void printxy() {
		std::cout << x << "  " << y << std::endl;
	}
	void show(mc & mc1) {
		this->x = 11;
		mc1.printxy();
	}
};

	void operator +(int a,mc m) {
		
	}
	template<typename T> struct A {};
	template<template <typename> typename TT> struct B {};//这里的class不能换为typename
	int main()
	{
		B<A> j;
		return 0;
	}

int main3() {

	//mc *p(new mc);
	mc mc1(10, 9);
	mc1.show(mc1);


	std::cin.get();
	return 0;
}


int main2() {

	mc *p = (mc *)malloc(sizeof(mc));
	std::cout << p << std::endl;


	std::cin.get();
	return 0;
}



int main1() {

	mc *p(new mc(10, 8));
	p->printxy();
	mc mc1(20, 1);
	std::cout << "-------------------" << std::endl;
	mc **pp(&p);
	(*pp)->printxy();
	(**pp).printxy();


	std::cin.get();
	return 0;
}
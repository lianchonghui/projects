#include<iostream>


class mc {

public:
	mc() {
		std::cout << "构造函数" << std::endl;
	}
	~mc() {
		std::cout << "析构函数" << std::endl;
	}

};


void create1() {
	mc mc1;
}
void create2() {
	mc *mc2 = new mc();
}

int main() {

	create1();
	create2();

	int i = 10;
	std::cout << i << std::endl;
	//int *pi = const_cast<int *>&i;
	const int *pi = &i;
	//*pi = 1;
	int  *p = const_cast<int *>(pi);
	
	std::cout << &i << std::endl;
	*p = 11;
	std::cout << i << std::endl;

	std::cin.get();
	return 0;
}
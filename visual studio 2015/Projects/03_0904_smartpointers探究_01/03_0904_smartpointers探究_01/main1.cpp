#include<iostream>


class demo {

public:
	demo() {
		std::cout << "demo constructor" << std::endl;
	}
	int num;
	static void sayHello();

	//void sayHello();

	//sayHello();
	void saybye() {


		this->sayHello();
	}
private:
	int data;
};
void demo::sayHello() {
	std::cout << "hello" << std::endl;
}

class demoson:public demo {
public:
	demoson() {
		std::cout << "demoson constructor" << std::endl;
	}
	void say() {
		
		demo::num = 10;
		this->saybye();
		demo::saybye();

	}
};

//void demo::sayHello() {
//
//	std::cout << "no static" << std::endl;
//
//}

int main() {

	demoson *ds = new demoson();
	ds->say();

	demo::sayHello();
	demo *d = new demo;
	d->sayHello();
	d->saybye();
	getchar();
	return 0;
}
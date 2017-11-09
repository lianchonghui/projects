#include<iostream>
class A {
public:
    int num;
	char * p;
	A(){}


	void saybye() {
		static int data;
		std::cout << "hello bye" << data << std::endl;
	}
	static void sayHi() {
		std::cout << "hello static function" << std::endl;
		//saybye();
	}

};
template<typename T>
class demo {
public:
	demo(A *a) {

	}

};
void funfun() {
	std::cout << std::endl;
}


int main4() {
	//A::saybye();
	/*demo<A> dp(new A);
	A *a(new A);
	demo<A> *dp2(new demo<A>(new A));*/

	A *a = new A;
	printf("%d\n", a->num);
	printf("%p\n", a->p);
	a->sayHi();

	getchar();

	return 0;
}
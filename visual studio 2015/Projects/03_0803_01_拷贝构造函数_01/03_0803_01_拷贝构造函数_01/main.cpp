#include<iostream>

using namespace std;


class Demo {
public:
	char *s;
public:
	Demo() {
		cout << "demo" << endl;

	}
	Demo(const Demo &it) {
		s = new char[100];
		strcpy(s, it.s);
		cout << "copy demo" << endl;
	}
	~Demo() {
		cout << "~Demo" << endl;
	}



};


int main() {

	Demo d1;
	d1.s = "hello world";
	Demo d2;
	d2 = d1;

	return 0;
}
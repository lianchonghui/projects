#include <iostream>

using namespace std;


class abstractClass {

public:
	virtual void show() = 0 {
		cout << "pure virtual function" << endl;

	}
	virtual void run() = 0;

};

class son :public abstractClass {
public:
	void run() {
		cout << "son function" << endl;
	}
};

int main()
{


	abstractClass *ac(nullptr);
	ac->show();
	son *s = new son; 
	s->show();
	cout << "Hello World!" << endl;

	cin.get();
	return 0;
}


#include <iostream>  
using namespace std;
class C
{
	float x, y;
public:
	C() {
		cout << "调用构造函数" << endl;
	}
	~C() {
		cout << "调用析构函数" << endl;
	}
	void show()
	{
		cout << "x=" << x << '\t' << "y=" << y << '\n';
	}
	void *operator new (size_t s)
	{
		void *p = new char[s];
		cout << "调用函数new(size_t s),分配空间为:" << s << '\n';
		return p;
	}
	void operator delete (void *p)
	{
		delete (p);
		cout << "调用函数delete(void *p)\n";
	}
};
int main1(void)
{
	C *p1;
	p1 = new C;//这里给对象分配内存，且会调用构造函数
	p1->show();
	delete(p1);
	getchar();
	return 0;
}
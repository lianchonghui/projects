#include <iostream>  
using namespace std;
class C
{
	float x, y;
public:
	C() {
		cout << "���ù��캯��" << endl;
	}
	~C() {
		cout << "������������" << endl;
	}
	void show()
	{
		cout << "x=" << x << '\t' << "y=" << y << '\n';
	}
	void *operator new (size_t s)
	{
		void *p = new char[s];
		cout << "���ú���new(size_t s),����ռ�Ϊ:" << s << '\n';
		return p;
	}
	void operator delete (void *p)
	{
		delete (p);
		cout << "���ú���delete(void *p)\n";
	}
};
int main1(void)
{
	C *p1;
	p1 = new C;//�������������ڴ棬�һ���ù��캯��
	p1->show();
	delete(p1);
	getchar();
	return 0;
}
#include <iostream>

using namespace std;


class Demo2 {

public:
	int a = 1;
	int b = 2;
	Demo2(int c) {//ע�⹹�캯��������������Ҫpublic��
		cout << "Demo2" << c << endl;
	}
	~Demo2() {
		cout << "~Demo2" << endl;
	}
	Demo2(const Demo2& D) {
		b = D.b;
		cout << "Copy Demo2" << endl;
	}


	void set_b(int b) {
		Demo2::b = b;
	}
	void set_a(int a) {
		Demo2::a = a;
	}
};
class Demo1 {
public:
	int i=0;
	Demo2 *d1 = new Demo2(1);
	Demo2 dd(12);
	// Demo2 *d2=new Demo2(22);
	void set_d1(Demo2 d) {
		d.a = 123;
		d.b = 123;
	}
	Demo1(int c) {
		//d1.a=c;
		//d1.b=c;
		i = c;
		cout << "Demo1" << endl;
	}

	~Demo1() {
		cout << "~Demo1" << endl;
	}
};

int main()
{

	Demo1 d1(12);
	/*
	Demo2 d1(12);
	d1.b=11;
	Demo2 d2=d1;//���,�����ĵ�ַ��ͬ,ֻ��ʾ��һ��Demo2,��������ʼ�����õ��ǿ������캯��,���Ǹ�ֵ
	cout<<"d1:"<<&d1.b<<" "<<"d2="<<&d2.b<<endl;
	cout<<"d2.b="<<d2.b<<endl;
	d1.b=111;
	cout<<"d2.b="<<d2.b<<endl;

	//ָ�뷽ʽ��������
	Demo2 *i1=new Demo2(12);
	i1->b=12;
	Demo2 *i2=i1;//ǳ����,�����ĵ�ַ��ͬ,ֻ��ʾ��һ��Demo2,��������ʼ�����õ��ǹ��캯��,���Ǹ�ֵ
	cout<<"i1:"<<&i1->b<<" "<<"i2:"<<&i2->b<<endl;
	cout<<"i2.b="<<i2->b<<endl;
	i1->b=1212;
	cout<<"i2.b="<<i2->b<<endl;
	*/

	return 0;
}


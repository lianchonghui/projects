#include <iostream>
using namespace std;

//关于new操作符的探究
//1.new的作用是首先分配内存(底层应该是malloc),然后初始化(调用构造函数).这个是用全局new来实现的.
//2.每次使用new都会调用一次构造函数,且是在每次new的结束之际调.
//3.如果在类内部new重载函数没有调用全局new,这样就不会调用构造函数初始化,因为没有调用全局new,就没有分配内存,这样就调用不了构造函数
//4.同种对象的函数(包括构造函数)存放在代码区,是共用的,变量存在堆中,每个对象私有的.
//5.虽然构造函数共用,但是如果没有给对象分配内存,假如构造函数由前一个对象创造分配了内存,这个对象也是调用不了的.
//6.虽然一般会调用两次构造函数,但是创建对象时只分配了一次内存(全局new中malloc),所以创建的对象只有一个
//7.size_t的size就是结构体(类)的大小,会自动计算
//8.局部new和全局new的执行顺序是:局部new->全局new->全局new中的malloc->全局new调用构造函数->局部new调用构造函数

//关于delete操作符的探究
//1.delete的执行顺序是:调用析构函数->局部delete->全局delete->全局delete中的free
//2.delete调用析构函数只会调用一次,是在一开始调用delete之际先调用了析构函数

static int i = 1;
static int j = 1;
class mystr
{
private:
	int a;
public:

	mystr()
	{
		if (i == 1) {

			cout << "mystr1" << endl;
		}
		else
			cout << "mystr2" << endl;
		
	}
	~mystr()
	{
		cout << "~mystr" << endl;
	}
	void * operator new(size_t size)
	{

		if (j == 1) {
		cout << "对象被创建" << endl;
		cout << size << endl;
		mystr *my1 = ::new mystr;
		i++;//判断是全局new先调用构造函数还是局部new先调用构造函数
		j++;
		return my1;

		}
		else
		{
			cout << "2对象被创建" << endl;
			return 0;
		}
	}
};

void * operator new(size_t size) {

	if (size == 0) {
		return 0;
	}
	cout << "全局" << size << endl;
	void *p = malloc(size);
	return p;

}

int main()
{
	mystr *my1 = new mystr;
	mystr *my2 = new mystr;

	getchar();
	return 0;
}
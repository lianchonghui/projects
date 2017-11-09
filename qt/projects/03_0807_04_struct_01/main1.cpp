#include <iostream>

using namespace std;


class Demo2{

public:
    int a=1;
    int b=2;
    Demo2(int c){//注意构造函数很析构函数是要public的
        cout<<"Demo2"<<c<<endl;
    }
    ~Demo2(){
        cout<<"~Demo2"<<endl;
    }
    Demo2(const Demo2& D){
        b=D.b;
        cout<<"Copy Demo2"<<endl;
    }

};
class Demo1{
public:
    int i;
    Demo2 *d1=new Demo2(1);
    Demo2 *d2=d1;
    //Demo2 dd1(1);
    //Demo2 dd1(12);

    Demo1(int c){
       d1->b=c;
       d1->a=c;
       cout<<"Demo1"<<endl;
    }
    Demo1(const Demo1& D){
        d1->a=D.d1->a;
        cout<<"Copy Demo2"<<endl;
    }
    ~Demo1(){
        cout<<"~Demo1"<<endl;
    }
};

int main1()
{

    Demo1 d1(12);
    Demo1 d2=d1;
    /*
    Demo2 d1(12);
    d1.b=11;
    Demo2 d2=d1;//深拷贝,变量的地址不同,只显示了一次Demo2,这里对象初始化调用的是拷贝构造函数,而非赋值
    cout<<"d1:"<<&d1.b<<" "<<"d2="<<&d2.b<<endl;
    cout<<"d2.b="<<d2.b<<endl;
    d1.b=111;
    cout<<"d2.b="<<d2.b<<endl;

    //指针方式创建对象
    Demo2 *i1=new Demo2(12);
    i1->b=12;
    Demo2 *i2=i1;//浅拷贝,变量的地址相同,只显示了一次Demo2,这里对象初始化调用的是构造函数,而非赋值
    cout<<"i1:"<<&i1->b<<" "<<"i2:"<<&i2->b<<endl;
    cout<<"i2.b="<<i2->b<<endl;
    i1->b=1212;
    cout<<"i2.b="<<i2->b<<endl;
*/

    return 0;
}


#include <iostream>

using namespace std;

class Father1{
public:
    Father1(){
        cout<<"father1 constructor,no"<<endl;
    }

    Father1(int a){
        cout<<"father1 constructor,yes"<<endl;
    }

    void show(){
        cout<<"father1 show"<<endl;
    }

    int num=0;

};
class Father2{
public:
    Father2(){
        cout<<"father2 constructor,no"<<endl;
    }
    Father2(int a){
        cout<<"father2 constructor,yes"<<endl;
    }

    void show(){
        cout<<"father2 show"<<endl;
    }

};
class Son:public Father1,public Father2{
public:
     Son(){
        cout<<"son constructor,no"<<endl;
     }
     Son(int a):Father1(a){
         cout<<"son constructor,yes"<<endl;
     }
     // int num=1;
};

int main()
{

    Son *son=new Son();

    son->Father1::show();
    son->Father2::show();
    //son->Father1.show();//错误,不能这样调用show()
    cout<<son->num<<endl;
    Son son2;
   //son2.Father1.show();//错误,不能这样调用show()
    son2.Father2::show();

    cout << "Hello World!" << endl;
    return 0;
}


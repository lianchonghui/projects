#include <iostream>

using namespace std;

class demo{
public:
    //static int num=1;//不允许这样初始化
    const static int data=2;//允许
    static int num;
};
int demo::num=1;//不能再加static


int main()
{

    demo demo1;


    cout << "Hello World!" << endl;
    return 0;
}


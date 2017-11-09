#include <iostream>

using namespace std;


class abstractClass{

public:
    virtual void show()=0;//{
           // cout<<"pure virtual function"<<endl;

   // }

};

class son:public abstractClass{
public:
    void show(){
        cout<<"son show function"<<endl;
    }
};

int main()
{


    abstractClass *ac;
    //ac->show();
    son *s=new son;
    cout<<sizeof(abstractClass)<<endl;
    cout << "Hello World!" << endl;
    return 0;
}


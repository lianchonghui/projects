#include <iostream>
#include <string>
using namespace std;

class Account {
public:
 Account(string name, int money):owner(name), amount(money) { }
       //Account(string name, int money, double rate):owner(name), amount(money), interestRate(rate) { } // 是错误的
 ~Account() { }
 double applyint()
 {
  amount += amount * interestRate;
  return amount;
 }
//如果将applyint()声明为static double applyint()则错误，因为amount不是//静态成员
 static double rate()
 {
  return interestRate; // 注意返回值
 }
 static void rate(double);
 static double interestRate;//public，其他非成员可以访问
private:
 string owner;
 double amount;
 //static double interestRate;  // private, 成员和友元才可访问
 static double initRate();
};

double Account::interestRate = 2.0; //正确的静态成员初始化
//double Account::interestRate = Account::initRate();//用静态成员函数对静态成员进行初始化，正确，
//     因为private成员可以访问private成员（？有待讨论），以上两种初始化只能选其一
//Account::interestRate  = 3.0; //错误，不能通过编译，原因不明，按编译结果看，编译器将这个赋值语句
   //   当做对静态成员的初始化（因为编译器提醒少了类型:double）。但主函数中可以通过，见下
double Account::initRate()
{
 return 2.0;
}
//所有的静态成员在类体外定义时都不再写static
void Account::rate(double newRate)
{
 interestRate = newRate;
}

int main ()
{
 Account Yang("Yang", 10); //interestRate = 2.0
 cout << Yang.applyint() << endl;
         cout << Yang.applyint() << endl;//注意两个结果不一样，因为amount第一次调用之后就变了。
 Yang.rate(4.0);
 cout << Yang.applyint() << endl;//interestRate = 4.0
 cout << Account::interestRate << endl; //public静态成员
 Account::interestRate = 3.0; //对应上面的赋值语句
 cout << Yang.applyint() << endl;//interestRate = 3.0
 Account Ning("Ning", 200);//interestRate = 3.0
         cout << Ning.applyint() << endl;
         Yang.interestRate = 6.0; // 也可以，并且还改了类中的静态成员值
 Account Pei("Pei", 2);// interestRate=6.0
 cout << Pei.applyint() << endl;
}

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main1(){
    struct string{
        int length;
        char *p;
    };
    struct string str1;
    struct string str2;
    struct string *str3;
    struct string str4;
    str1.length=10;
    str1.p = (char *) malloc(sizeof(char)*10);
    str2.p = (char *) malloc(sizeof(char)*10);
    strcpy(str1.p,"hello");
    str2.length=str1.length;
    strcpy(str2.p,str1.p);
    str4=str1;
    
    cout<<&str2.length<<&str2.p<<endl;
    cout<<&str1.length<<&str1.p<<endl;
    cout<<&str4.length<<&str4.p<<endl;
    cout<<str1.p<<endl;
    cout<<&str2<<endl;
    cout<<sizeof(*str3)<<endl;

    cin.get();

    return 0;
}
int main(){

    char str[]="abcd";
    char str2[4]="abc";
    cout<<sizeof(str)<<endl;
    cout<<sizeof(str2)<<endl;
    cin.get();
    return 0;
}
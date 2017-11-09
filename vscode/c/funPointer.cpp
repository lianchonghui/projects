#include<stdio.h>
#include<stdlib.h>

int add(int a,int b){
    return a+b;
}

int main(){
  
    int (*addp)(int a,int b) = add;
    typedef int (*Faddp)(int a,int b);
    Faddp add2 = add;
    int d = addp(10,20);
    int c = add(10,10);
    printf("%d\n",c);
    printf("%d\n",d);
    printf("%d\n",add2(11,22));
    getchar();
    return 0;
}
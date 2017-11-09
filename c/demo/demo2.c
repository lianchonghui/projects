#include<stdio.h>

#define str(s) #s
#define f(x) f##x
#define P(x) printf("%s=%d\n",#x,x);
#define I(x) X##x
int main()
{
	printf("hello c\n");
	printf(str("hello"\n));//"hello"
	printf(str(hello\n));//hello
	int f1=10;
	int f2=20;
	printf("f1=%d",f(1));
	printf("f2=%d",f(2));
	printf("\n");
	int I(1) = 111;
	int I(2) = 222;
	int I(3) = 333;
	X2 = 2222;
	P(I(1));
	P(I(2));
	P(X2);

	getchar();
	return 0;
	
}

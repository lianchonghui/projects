#include<stdio.h>
#include<stdlib.h>



void printf1() {
	printf("1111");
}
void printf2() {
	printf("2222");
}


void a1(char name[], char type[]) {
	printf("%s,%s", name, type);
}

//定义一个创建函数的模板 type name(##type a){},
//注意,这里的##起到的是链接的作用,有无都行,但是不能使用#
#define A2(name,type) type name(##type a){printf("helloworld");return a;}
A2(a2,int)

int main4() {

//通过函数名和返回参数调用函数,这里#起到字符串化的作用,是a1和void当做字符串参数传入a1
#define A1(name,type)  name(#name,#type)

	A1(a1, void);
	
	printf("\n");
	a2(11);
	printf("\n");
	printf("%d", a2(11));
	getchar();
	return 0;
}

int main() {
	//##的作用:拼贴不想变字符串和想变字符串
	//这里宏替换的是宏名的x与宏的x


//P(1)等价于P1
#define P(x) Q##x

	int P(1) = 11;
	int P(2) = 22;
	printf("%d,%d\n", P(1), P(2));

	Q1 = 111;
	Q2 = 222;
	printf("%d,%d\n", Q1, Q2);

//PP(1)等价于printf1,PP(1)()等价于printf1();
#define PP(x) printf##x

	PP(1)();
	PP(2)();

	printf("\n");

	printf1();
	printf2();

	
	getchar();
	return 0;
}

int main2() {
	//define 宏替换注意,只是替换,不会先进行任何运算
	//

//#define LF(x) x*x*x//逻辑不严密,如下会造成:3+1*3+1*3+1结果为10,define是且只是替换而已
//这里是函数的替换
#define LF(x) (x)*(x)*(x)

	printf("%d", LF(3+1));

	getchar();


	return 0;
}




int main1() {
	//关于#的应用


	//printf("%s", A1(a1));

	//#起到字符串化的作用
#define printfn(x) printf(#x);
	printfn(hello world);

#define printfnn(x) printf("%s=%d",#x,x)

	int a1 = 10, a2 = 20;

	printfnn(a1);



	getchar();

	return 0;
}
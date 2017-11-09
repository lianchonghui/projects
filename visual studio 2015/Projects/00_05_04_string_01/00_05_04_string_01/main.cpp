#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>




int main4() {



	system("pause");
	return 0;
}

int main3() {

	//二维字符数组初始化

	char c1[5][64] = { {"calc"},{"mspaint"},{"ipconfig"},{"systeminfo"},{"tasklist" } };
	char c2[5][64] = { "calc","mspaint","ipconfig","systeminfo","tasklist" };

	char *c3[64] = { "calc","mspaint","ipconfig","systeminfo","tasklist" };
	//char *c5[64] =  ""calc","mspaint","ipconfig","systeminfo","tasklist"" ;//这样不行

	char (*c4)[64] = c1;

	printf("%s\n", c3[0]);
	
	
	printf("%p,%p\n", &c4[0], &c1[0]);
	c1[0][1] = 'b';
	printf("%s\n", c4[0]);//表名c4和c1都是同一个字符数组

	system("pause");
	return 0;
}


int main2() {

	char p[] = "hellop";
	char *q = "helloq";

	char *r = (char *)malloc(sizeof(char) * 6);
	
	p[0] = 'p';//p[0]在栈区,可以修改.//所以p是一个指针常量,不能修改其指向,但指向的数据可以修改
	q[0] = 'q';//不能修改,q[0]在常量区//所以q是一个常量指针,指向一个常量,q的指向可以修改,但指向的数据不能修改
	r[0] = 'r';//r指向的数据存储的堆区
	r[1] = '\0';

	printf("%s\n%s\n%s\n", p, q, r);


	system("pause");
	return 0;
}


int main() {

	//字符数组初始化和字符指针初始化
	
	char c1[100] = "helloworld,it is c1\n";
	printf("c1:%s", c1);

	char c2[100] = { "helloworld,it is c2\n" };
	printf("c2:%s", c2);

	/*char c3[100];
	c3 = "helloworld,it is c3\n";*///错误,c3是数组,是常量指针,这个指针不可子再重新指向其他地址(字符串)

	char *c4 = "helloworld,it is c4\n";
	printf("c4:%s", c4);//这里不能加*号
	printf("%d\n", sizeof(c4));
	printf("%c%c%c%c\n", c4[0],c4[1],c4[2],c4[3]);

	char *c5;
	c5 = "helloworld,it is c5\n";
	printf("c5:%s\n", c5);

	char *c6 = c1;
	printf("c6:%s\n", c6);

	printf("size:%d,%d,%d,%d\n", sizeof(c1), sizeof(c2),sizeof(c4),sizeof(c5));//100,100,4,4

	char *c7 = "hello\0world,it is c7";
	printf("c7:%s\n", c7);

	char c8[100] = "hello\0world,it is c8";
	printf("c8:%s\n", c8);


	//以上,


	//char *c9;
	//scanf("%s", c9);//出错,未初始化的局部变量


	//char *c10 = "hello";
	//scanf("%s", c10);//编译正常,运行出错.原因是c10指向的字符串在常量区,不能修改,详见main2
	//printf("c10:%s", c10);

	char *c11;
	char str[10];
	c11 = str;
	scanf("%s", c11);//这个正确,c11指向字符数组str

	int num = 4;
	int *i = &num;
	
	printf("i:%d\n", *i);
	printf("%d\n", i[0]);

	int a[3] = { 1,3,4 };
	printf("%d\n", a);//打印的不是a[0]
	printf("%d\n", a[0]);
	int *aa = &i[0];
	int *aaa = a;
	printf("%d%d%d\n", aaa[0], aaa[1], *(aaa + 2));


	


	system("pause");
	return 0;
}
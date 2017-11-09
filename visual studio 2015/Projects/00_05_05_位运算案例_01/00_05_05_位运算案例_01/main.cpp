#include<stdio.h>
#include<stdlib.h>


void main() {

	float fl;
	scanf_s("%f", &fl);
	unsigned char *p = (unsigned char *)&fl;//共享内存

	//windows下,低位在前,高位在后
	for (int i = 3;i >= 0;i--){
		unsigned char chs = p[i];

		for (int j = 7;j >= 0;j--) {

			printf("%c", chs&(1 << j) ? '1' : '0');

		}
	
	}

	system("pause");


}

void main6() {
	//不用加减乘除实现两数相加:使用左移和右移运算符


}



void main5() {
	//不借助中间变量实现两数交换


	int a = 10;
	int b = 21;

	printf("a=%d,b=%d\n", a, b);

	//方法一:
	a = a + b;
	b = a - b;
	a = a - b;

	printf("a=%d,b=%d\n", a, b);

	//方法二:
	a = a * b;
	b = a / b;
	a = a / b;
	printf("a=%d,b=%d\n", a, b);

	//方法三:
	a = a^b;
	b = b^a;
	a = a^b;
	printf("a=%d,b=%d\n", a, b);

	getchar();

}



void main4() {
	//案例1:位字段打印反码//失败!!!!!!!!

	typedef struct biteNum {
		unsigned char c1 : 1;
		unsigned char c2 : 1;
		unsigned char c3 : 1;
		unsigned char c4 : 1;
		unsigned char c5 : 1;
		unsigned char c6 : 1;
		unsigned char c7 : 1;
		unsigned char c8 : 1;

	}BNUM;

	printf("%d\n", sizeof(BNUM));//1Byte


								 //创建指针bnp
	BNUM *bnp;

	//分配内存
	int * nump = (int *)malloc(sizeof(BNUM) * 4);

	//指针bnp指向分配好的内存,与nump共用内存
	bnp = (BNUM *)nump;

	//对分配好的内存根据地址初始化
	scanf_s("%d", nump);

	//Windows下,高位在后,地位在前,在内存中存储
	printf("补码:"); 
		for (int i = 3;i >= 0;i--) {
			printf("%d%d%d%d%d%d%d%d ", bnp[i].c8, bnp[i].c7, bnp[i].c6, bnp[i].c5, bnp[i].c4, bnp[i].c3, bnp[i].c2, bnp[i].c1);

		}

	printf("\n");


	*nump--;

	printf("反码:");
	for (int i = 3;i >= 0;i--) {
		printf("%d%d%d%d%d%d%d%d ", bnp[i].c8, bnp[i].c7, bnp[i].c6, bnp[i].c5, bnp[i].c4, bnp[i].c3, bnp[i].c2, bnp[i].c1);

	}
	for (int i = 3;i >= 0;i--) {
		//printf("%d%d%d%d%d%d%d%d", bnp[i].c8, bnp[i].c7, bnp[i].c6, bnp[i].c5, bnp[i].c4, bnp[i].c3, bnp[i].c2, bnp[i].c1);
		bnp[i].c8 = ~bnp[i].c8;
		bnp[i].c7 = ~bnp[i].c7;
		bnp[i].c6 = ~bnp[i].c6;
		bnp[i].c5 = ~bnp[i].c5;
		bnp[i].c4 = ~bnp[i].c4;
		bnp[i].c3 = ~bnp[i].c3;
		bnp[i].c2 = ~bnp[i].c2;
		bnp[i].c1 = ~bnp[i].c1;
	}

	getchar();
	getchar();
}


void main3() {
	//案例2:位运算打印补码

	//a:  1000 0000 0000 0000 0000 0000 0000 0000
	//num:0000 0000 0000 0000 0000 0000 0000 1000

	int a = 1<<31;

	int num;
	scanf_s("%d", &num);

	for (int i = 1;i <= 32;i++) {
		
		printf("%c", num&a?'1':'0');//采用字符节约内存
		
		//a >>= 1;//为什么采用a的位移会发生错误??????
		num <<= 1;

		if (i % 4 == 0) {
			printf(" ");
		}
	}

	system("pause");



}


void main2() {
	//案例1:位字段打印补码

	typedef struct biteNum {
		unsigned char c1: 1;
		unsigned char c2: 1;
		unsigned char c3: 1;
		unsigned char c4: 1;
		unsigned char c5: 1;
		unsigned char c6: 1;
		unsigned char c7: 1;
		unsigned char c8: 1;

	}BNUM;

	printf("%d\n", sizeof(BNUM));//1Byte


	//创建指针bnp
	BNUM *bnp;

	//分配内存
	int * nump = (int *)malloc(sizeof(BNUM) * 4);

	//指针bnp指向分配好的内存,与nump共用内存
	bnp = (BNUM *)nump;

	//对分配好的内存根据地址初始化
	scanf_s("%d", nump);

	//Windows下,高位在后,地位在前,在内存中存储
	for (int i = 3;i >= 0;i--) {
		printf("%d%d%d%d%d%d%d%d", bnp[i].c8, bnp[i].c7, bnp[i].c6, bnp[i].c5, bnp[i].c4, bnp[i].c3, bnp[i].c2, bnp[i].c1);

	}

	getchar();
	getchar();
}



void main1() {
	//案例1:位运算打印补码  //失败,c语言数据类型最小单位为1字节

	typedef struct numc {
		char c1 : 1;
	}NUMC;




	NUMC *numcP;
	printf("%d\n", sizeof(NUMC));
	numcP = (NUMC *)malloc(sizeof(NUMC) * 8);

	char * charP;

	charP = (char *)numcP;

	*charP = 8;

	printf("%d\n", *charP);

	for (int i = 7;i >= 0;i--) {
		printf("%d", numcP[i]);
	}
	
	getchar();
}

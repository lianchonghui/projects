#include<stdio.h>
#include<stdlib.h>

struct demo1 {
	unsigned int day : 5;
	unsigned int month : 5;
	unsigned int year : 14;
	//unsigned long long : 14;
}b1;


struct demo2 {
	unsigned char c1 : 1;
	unsigned char c2 : 2;

};

struct demo3 {
	unsigned char c1 : 1;
	unsigned char c2 : 2;
	unsigned int num : 10;

};

void main3() {
	printf("%d", sizeof(struct demo3));
	//虽然demo2打印的是1,但是加上int以后,会字节对齐,打印8;
	//c1,c2两个占4个字节,num占4个字节
	getchar();
}


void main2() {
	printf("%d", sizeof(struct demo2));
	//打印1,如果两个字符相加小于8位,会填充为一个字节,通过位操作操作位字段

	getchar();
}

void main() {

	printf("%d,%d", sizeof(struct demo1),sizeof(long long));
	//在没有long long的时候打印4个字节,只有int,但三个相加没有达到int的大小,所以会自动补齐到int大小4byte
	//在有long long 的时候,会自动补齐到16个字节
	getchar();

}
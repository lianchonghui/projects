#include<stdio.h>
#include<stdlib.h>



//匿名共用题类型定义并定义变量及初始化
struct {

	int num;
	char c[10];

}d1{ 1,"jdf" }, d2{ 3,"sdfasdf" };


struct demo1{//14,13,10
	int num;//4 ,4,4
	float dou;//4 ,4,4
	char c;//1 ,1  ,1
	char ch[14];//14+3,13,10
	short sh;//2,2,2
	//9时,sizeof(demo1)=20
	//10时,sizeof(demo1)=24
	//13时, sizeof(demo1) = 24
	//14时, sizeof(demo1) = 28
	//结构体变量所占空间的大小是对齐参数的整数倍。这句话中的对齐参数有点复杂，
	//它是取结构体中所有变量的对齐参数的最大值和系统默认对齐参数#pragma pack(n)比较，
	//较小者作为对齐参数。
	//举个例子假如在结构体A中先后定义了两个变量int a;double b;对于变量a，
	//	它的自身对齐参数为4，而#pragma pack(n)值默认为8，则a的对齐参数为4；
	//	b的自身对齐参数为8，而#pragma pack(n)的默认值为8，则b的对齐参数为8。
	//	由于a的最终对齐参数为4，b的最终对齐参数为8，那么两者较大者是8，
	//	然后再拿8和#pragma pack(n)作比较，取较小者作为对齐参数，也就是8，
	//	即意味着结构体最终的大小必须能被8整除。

	//总之,计算一个变量的对齐参数的顺序为:
	//1.每个变量通过自身对齐参数(数组除外)与#pragma pack(n)比较,取小
	
	//2.步骤1的对齐参数(除数)要整除该变量与结构体起始地址的偏移量,否则补齐,得到补齐大小和对齐参数大小相加
	//3.每个变量大小相加再加上数组大小(如果有数组)得到结构体大小必须是对齐参数(最宽字符大小)的整数倍,否则数组要自动填充使结构体大小为对齐参数整数倍

	
}de1,de2{ 2,22,2,{1,2,3,4,5},2 };

struct sd1 {
	int a;
	int b;
	double c;
};//16
//1.a的自身对齐参数为4,默认参数是8,则取4,4能被偏移量0整除,则分配4byte
//2.b的自身对齐参数为4,默认参数是8,则取4,4能被偏移量4整除,则分配4byte
//3.c的自身对齐参数是8,默认参数是8,则取8,8能被偏移量8整除,则分配8byte
//结果是4+4+8=16
struct sd2 {
	int a;
	double c;
	int b;
};//24
  //1.a的自身对齐参数为4,默认参数是8,则取4,4能被偏移量0整除,则分配4byte
  //2.c的自身对齐参数为8,默认参数是8,则取8,8不能被偏移量4整除,则补齐4byte再分配8byte
  //3.b的自身对齐参数是4,默认参数是8,则取4,4能被偏移量16整除,则分配4byte
  //结果是4+4+8+4=20总大小不能被最宽字符8整除,则补齐到24.最终大小为24

int main() {

	printf("%d,%d\n", sizeof(struct sd1), sizeof(struct sd2));//16,24

	system("pause");
	return 0;
}



void main2() {
	printf("%d,%d\n", 0 % 1,0/1);

	//关于结构体字节对齐以及结构体中不正确使用格式符所导致的后果
	de1 = { 1,11,1,{ 1,2,3,4,5 },1 };//
	
	struct demo1 de3;
	de3.num = 3;
	de3.dou = 33;
	de3.c = 64;
	de3.ch[0] = 3;
	de3.sh = 3;
	struct demo1 de4 = { 4,41,4,{ 1,2,3,4,4 },4 };
	printf("%d,%d,%d,%d,%d\n", sizeof(de1),sizeof(de2),sizeof(de3),sizeof(de4),sizeof(struct demo1));

	printf("de1=%d,%d,%d,%d,%d\n", de1.num, de1.dou,de1.c,de1.ch[0],de1.sh);

	printf("de2=%d,%d,%d,%d,%d\n", de2.num, de2.dou, de2.c,de2.ch[1],de2.sh);

	printf("de3=%d,%d,%d,%d,%d\n", de3.num, de3.dou, de3.c,de3.ch[0],de3.sh);

	//结构体内对各种数据类型不正确的解析映射会导致后续数据类型的解析错误

	printf("de1=%d,%f,%d,%d,%d\n", de1.num, de1.dou,de1.c, de1.ch[0],de1.sh);

	printf("de2=%d,%f,%d,%d,%d\n", de2.num, de2.dou, de2.c,de2.ch[1],de2.sh);

	printf("de3=%d,%f,%d,%d,%d\n", de3.num, de3.dou, de3.c,de3.ch[0],de3.sh);

	getchar();

}






void main1() {

	printf("%d,%s,%d,%s\n",d1.num, d1.c, d2.num, d2.c);

	getchar();
}
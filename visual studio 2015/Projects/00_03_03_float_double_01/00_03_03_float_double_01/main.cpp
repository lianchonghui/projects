#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void main() {


	//float f1 = 1.5; 
	//printf("%d", sizeof(f1));
	//printf("%x", &f1);

	//system("pause");

	//通过int和double类型转换实现四舍五入

	//double db2 = 13.44;
	//int num = 13;
	//double newnum = num / 10;//1.000000
	//double newnum2 = num / 10.0;//1.30000
	//printf("newnum=%f,newnum2=%f",newnum,newnum2);
	////说明一个整数除以10以后成一个小数会自动取整然后赋值为double类型,但是除以10.0就会隐式转换为double

	//double db;
	//scanf("%lf", &db);

	//printf("当前db是%f \n", db);
	//
	//double newdb = (int)(db * 10 + 0.5) / 10;//注意这里要除以10.0,int强转的是db*10+0.5的部分,强转以后为int的整型,如果除以10,就还是整型会自动取整,除以10.0就转换为double再除就不会取整了

	//printf("四舍五入以后的db是%f \n", newdb);

	//printf("偷得的money是%f", db - newdb);

	//printf("%d", sizeof(long long));//8
	char str[6] = "hello";
	char str2[] = { 'h','e','l','l','o'};

	//printf("%s", str);
	//printf("\n%d", sizeof(str));
	//printf("\n%s", str2);
	////如果是str2[5]就会打印错误,末尾有乱码,因为%s是遇到'\0'才会结束读取
	////如果是str2[6],数组内的元素不便,也不会读取错误,最后一个元素是空字符,也可以手动添加'\0',
	////(新建数组并指定大小,没有初始化的会自动填充空字符)
	////而声明为字符串的时候如str,数组大小是要比字符个数大一个来自动添加'\0'结束标志
	//printf("\n%d", sizeof(str2));


	/*printf("%i,%i,%i\n", 15, 015, 0x15);*/
	
	int i1, i2, i3;
		scanf("%i %i %i", &i1,&i2,&i3);
		printf("%d,%d,%d\n", i1, i2, i3);

	int d1, d2, d3;
	scanf("%d %d %d", &d1, &d2, &d3);
	printf("%d,%d,%d\n", d1, d2, d3);
	system("pause");








}
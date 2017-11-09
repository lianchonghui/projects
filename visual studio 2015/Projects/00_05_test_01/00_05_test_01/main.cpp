#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdarg.h>
#include<string>
#include<Windows.h>

void args(int num, ...) {//num表示输入的参数个数
	//可变参数函数

	//引入stdarg.h头文件
	va_list argp;//定义指针,用于存储地址,这里不能加*号
	va_start(argp, num);//表示有num个参数

	for (int i=0;i<num;i++) {
		char str[50];//用于保存的字符串参数
		//按char*的方式读取argp存储到str中
		strcpy(str, va_arg(argp, char*));//string.h
		printf("%s\n", str);
	}
	va_end(argp);//结束调用

}

void ten2two(int num) {
	//十进制转化二进制函数

	if (num == 0) {
		return;
	}
	ten2two(num / 2);
	printf("%d", num % 2);

}

double tencent(int num) {
	//斐波那契数列求n的大小

	if (num == 1) {
		return 1.0;
	}
	else if (num == 2) {
		return 2.0;
	}
	else
	{
		return tencent(num - 1) + tencent(num - 2);
	}

}

void arrp(int* p,int num) {
	//指针作为参数对数组元素进行排序
	//这里用选择排序
	
	for (int i = 0;i < num-1;i++) {
		for (int j = i + 1;j < num;j++) {
			if (p[i] > p[j]) {
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}

	//for (int i = 0;i < num;i++) {
	//	for (int j = 0;j < num - i - 1;j++) {
	//		if (p[j] > p[j + 1]) {
	//			int temp = p[j];
	//			p[j] = p[j + 1];
	//			p[j + 1] = temp;
	//		}

	//	}

	//}

}





void main12() {
	//用指针作函数参数传递,数组是没有副本机制的
	int arr[6] = { 2,5,1,7,3,0 };
	int* p = arr;
	for (int i = 0;i < 6;i++) {
		printf("%4d", p[i]);
	}
	printf("\n");

	arrp(p, 6);
	
	for (int i = 0;i < 6;i++) {
		printf("%4d", arr[i]);
	}
	system("pause");
}



void main11() {
	//数组倒序

	//构建一个动态数组
	int num = 0;
	scanf_s("%d", &num);

	//构建随机数种子
	time_t ts;//time_t其实是long int类型,用来存储从1970年到现在的时间的数据类型
	srand((unsigned int)time(&ts));

	//创建一个指针,指向一个数组大小的空内存
	int* p = (int*)malloc(num*sizeof(int));

	for (int i = 0;i < num;i++) {

		p[i] = rand() % 100;
		printf("%4d", p[i]);
	}

	printf("\n");

	//收尾替换//注意i<num/2
	for (int i = 0;i < num/2;i++) {
		int temp = p[num-i-1];
		p[num - i - 1] = p[i];
		p[i] = temp;
	}

	for (int i = 0;i < num;i++) {
		printf("%4d", p[i]);
	}

	system("pause");




}



void main10() {
	//腾讯面试题:循环解决
	//有50个台阶,一次能上1台阶或两台阶,问有多少种可能的上法?
	while (1) {

	int num;
		scanf_s("%d", &num);

		double d[3] = { 1,2,3 };
		//double temp0;
		//double temp1;
		if (num == 1) {
			printf("%f\n", d[0]);
		}
		else if (num == 2) {
			printf("%f\n", d[1]);
		}
		else {
			for (int i = 2;i < num;i++) {
				//temp0 = d[1];
				//temp1 = d[2];
				d[2] = d[1] + d[0];
				d[0] = d[1];
				d[1] = d[2];
			}
			printf("%llf\n", d[2]);
		}

	}

}


void main9() {
	//腾讯面试题:递归解决
	//有50个台阶,一次能上1台阶或两台阶,问有多少种可能的上法?
	//分析:要想到达n台阶必定是从n-1或n-2的台阶上去的,所以到达n台阶的可能性有f(n-1)+f(n-2);
	//斐波那契数列
	while (1) {

		int num;
		scanf_s("%d", &num);
		double f = tencent(num);
		printf("%llf\n", f);
	
	}
	system("pause");


}

void main8() {
	//十进制转化为二进制
	while (1) {


		printf("\n请输入一个正整数:");
		int num;
		scanf_s("%d", &num);
		if (num == 0) {
			printf("0");
		}
		else
		{
			ten2two(num);
		}

	}
	system("pause");

}



void main7() {
		//验证是否为质数(素数)
	while (1) {

		printf("请输入一个大于2的整数:");
	
		int flag = 1;
		int num;
		scanf_s("%d", &num);

		if (num == 2 || num==3) {
			printf("%d是一个质数\n", num);
		}
		else {

			for (int i = 2;i < num;i++) {
				if (num%i==0) {
					flag = 0;
					printf("可以被%d整除\n", i);
					/*printf("%d不是一个质数\n", num);
					break;*/
				}
			}
		}

		if (flag) {
			printf("%d是一个质数\n", num);
		}
		else
		{
			printf("%d不是一个质数\n", num);
		}

	}
	system("pause");

}





void main6() {
	//求数字位数
	printf("请输入一正整数:");
	int num;
	int result = 0;
	scanf_s("%d", &num);
	
	if (num == 0) {
		printf("\n你输入的是一位数");
	}
	else {


		while (num) {

			num = num / 10;
			result++;
		}
		printf("\n你输入的是%d位数", result);
	
	}

	getchar();
	getchar();

}




void main5() {
	//验证一个数是否为水仙花数abc=a^3+b^3+c^3
	int num = 0;
	while (1) {

		printf("请输入一个三位数:");

		scanf_s("%d", &num);

		int a = num / 100 % 10;
		int b = num / 10 % 10;
		int c = num % 10;

		if (a*a*a + b*b*b+ c*c*c== num) {
			printf("\n%d是一个水仙花数.",num);
		}
		else
		{
			printf("\n%d不是一个水仙花数.", num);
		}


	}

}

void main4() {
	//函数可变参数

	args(4, "notepad", "pause", "ipconfig", "mspaint");

	
	//定时退出
	Sleep(10000);
	exit(0);
	


}





void main3() {
	//数组打印斐波那契数列

	int num = 0;
	scanf_s("%d", &num);

	//使用指针创建一个动态数组
	int* p = (int*)malloc(num*sizeof(int));

	p[0] = 0;
	p[1] = 1;
	printf("p[0]=%d\np[1]=%d\n", p[0], p[1]);
	for (int i = 2;i < num;i++) {
		p[i] = p[i - 1] + p[i - 2];
		printf("p[%d]=%d\n", i,p[i]);
	}

	system("pause");



}







void main2() {
	//二分查找法

	//创建一个随机数种子
	time_t	ts;
	srand((unsigned int)time(&ts));
	
	//输入数组元素个数
	int num=0;
	scanf_s("%d", &num);

	//创建一个动态数组
	int* arrp =(int*) malloc(num*sizeof(int));//这个指针的步长必须是整个数组的长度

	//给数组赋值
	for (int i = 0;i < num;i++) {

		arrp[i] = rand() % 100;
		printf("%4d", arrp[i]);

	}

	//给数组排序//这里用冒泡排序
	for (int i = 0;i < num;i++) {
		for (int j = 0;j < num - i - 1;j++) {
			if (arrp[j] > arrp[j + 1]) {
				int temp = arrp[j];
				arrp[j] = arrp[j + 1];
				arrp[j + 1] = temp;
			}

		}
		
	}

	printf("\n");
	//遍历数组
	for (int i = 0;i < num;i++) {
		printf("%4d", arrp[i]);
	}

	printf("\n请输入要查找的数:");
	int checkNum;
	scanf_s("%d", &checkNum);
	printf("\n");


	//二分查找法
	int min = 0;
	int max = num - 1;
	int mid = (min + max) / 2;
	int inum = 1;
	while (1) {
		printf("第%d次查询\n", inum++);

		if (checkNum == arrp[mid]) {
			printf("找到了,数字下标是%d", mid);
			break;
		}
		else if(checkNum<arrp[mid])
		{
			max = mid - 1;
			mid = (min + max) / 2;
			continue;
		}
		else if(checkNum>arrp[mid])
		{
			min = mid + 1;
			mid = (max + min) / 2;
			continue;
		}


	}



	system("pause");



}



void main1() {
	//二维数组的转置

	//创建一个列固定的动态二维数组

	time_t ts;
	unsigned int timeNum = time(&ts);
	srand(timeNum);

	int arr[3][4] = { 0 };
	//int x;
	//scanf_s("%d", &x);

	for (int i = 0;i < 3*4;i++) {
		int num = rand()%100;
		arr[i / 4][i % 4] = num;
	/*	carr[i / 3][i % 3] = num;*/
		printf("%4d", num);

		if (i % 4 == 3) {
			printf("\n");
		}
	}

	printf("----------------\n");

	//for (int i = 0;i < 4 * 3;i++) {
	//	carr[i / 3][i % 3] = arr[i % 4][i / 4];
	//	printf("%4d", carr[i / 3][i % 3]);

	//	if (i % 3 == 2) {
	//		printf("\n");
	//	}

	//}
	int carr[4][3] = { 0 };

	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 3;j++) {
			carr[i][j] = arr[j][i];
			printf("%4d", carr[i][j]);
		}
		printf("\n");

	}


	getchar();
	getchar();

}
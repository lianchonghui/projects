#define _CRT_SECURE_NO_WARNINGS
#define NDEBUG //当有定义NDEBUG的时候解除断言

#define DEBUG //开启myassert的断言

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#ifndef  DEBUG //当没有定义DEBUG的时候myassert(x)不执行任何动作,即不开启断言
#define myassert(x)
#else
#define myassert(x) \
if (!(x))\
{\
	printf("myassert(%s)宏开始检测...\n",#x);\
	printf("当前函数名为%s,文件名为%s,代码行号为%d",__FUNCTION__,__FILE__,__LINE__);\
	char str[50];\
	sprintf(str,"当前函数名为%s,文件名为%s,代码行号为%d",__FUNCTION__,__FILE__,__LINE__);\
	MessageBoxA(0, str, "error", 0);\
}

#endif // !




int main() {

	int num1, num2;
	scanf_s("%d%d", &num1, &num2);

	myassert(num2 != 0);//断言

	printf("%d", num1 / num2);
	

	system("pause");
	return 0;
}




int main1() {
	//assert.h头文件包含的断言


	int num1,num2;
	scanf_s("%d%d", &num1,&num2);

	assert(num2 != 0);//断言

	printf("%d", num1 / num2);

	system("pause");
	return 0;
}
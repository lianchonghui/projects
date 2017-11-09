#include"mystack.h"

int main() {

	//链式栈的基本演示

	LS *phead=NULL;
	phead = init(phead);//初始换链式栈

	phead = pushls(phead, 1);
	phead = pushls(phead, 2);
	phead = pushls(phead, 3);
	phead = pushls(phead, 4);
	phead = pushls(phead, 5);

	printfall(phead);

	//printf("出栈\n");
	//LS *pout = (LS*)malloc(sizeof(LS));
	//while (phead)
	//{
	//	
	//	phead = popls(phead, pout);
	//	printf("%d,%p,%p\n", pout->data, pout, pout->pnext);
	//}

	phead=freeall(phead);
	printf("释放以后\n");
	printfall(phead);

	system("pause");
	return 0;
}


int main2() {

	//利用栈的先进后出的特性,输出一个数二进制
	int num = 100;

	while (num)//根据求二进制的方法,每次除以2,直到完全除近,即刚好除以2得到0(不是%得到0),循环终止
	{
		push(num % 2);//压栈
		num /= 2;
	}

	while (!isempty())
	{
		printf("%d", pop());
	}
	system("pause");
	return 0;
}



int main1() {
	//栈的基本演示

	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0;i < 10;i++) {
		push(a[i]);//压入数据
	}

	while (isempty() != 1) {//1为空,0为有元素
		printf("%d\n", pop());
	}

	system("pause");
	return 0;
}
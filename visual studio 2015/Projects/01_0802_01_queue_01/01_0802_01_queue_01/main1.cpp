#include<stdio.h>
#include<stdlib.h>
#include"myqueue.h"
#include"linkedQueue.h"


int main() {

	LQ *lq = NULL;
	lq = init(lq);
	lq = enQueue(lq, 1, 1);
	printfall(lq);
	lq = enQueue(lq, 2, 1);
	printfall(lq);
	LQ *lqout = NULL;
	lq = deLinkedQueue(lq,lqout);
	printfall(lq);
	lq = deLinkedQueue(lq, lqout);
	printfall(lq);

	system("pause");
	return 0;
}


int main5() {

	//测试链表队列初始化\
		//增加节点
//打印所有节点

	LQ *lq = NULL;
	lq = init(lq);
	lq = enQueue(lq, 1, 1);
	printfall(lq);
	lq = enQueue(lq, 2, 1);
	printfall(lq);
	system("pause");
	return 0;
}


int main4() {

	/*hello();*/

	system("pause");
	return 0;
}

int main3() {

	MQ mq;
	initQueue(&mq);

	addNode(&mq, 12);
	
	
	datatype d = deQueue(&mq);
	printf("%d\n", d);
	d = deQueue(&mq);
	printf("%d\n", d);

	system("pause");
	return 0;
}


int main2() {

	//对列增加元素和打印对列多有元素
	MQ mq;
	initQueue(&mq);

	for (int i = 0;i < 100;i++) {
		addNode(&mq, i);
	}
	show(&mq);
	printf("\n");
	show2(mq);
	printf("\n");
	if (addNode(&mq, 100)) {
		printf("success");
	}
	else {
		printf("error");
	}
	printf("\n");
	initQueue(&mq);
	if (addNode(&mq, 100)) {
		printf("success");
	}
	else {
		printf("error");
	}
	printf("\n");
	show2(mq);
	system("pause");
	return 0;
}



int main1() {

	//队列的初始化和判断是否为空

	MQ mq;
	initQueue(&mq);
	if (isEmpty(&mq)) {
		printf("NULL\n");
	}
	else
	{
		printf("就打飞机啊");
	}

	system("pause");
	return 0;
}
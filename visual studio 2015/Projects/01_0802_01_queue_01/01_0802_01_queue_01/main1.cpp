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

	//����������г�ʼ��\
		//���ӽڵ�
//��ӡ���нڵ�

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

	//��������Ԫ�غʹ�ӡ���ж���Ԫ��
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

	//���еĳ�ʼ�����ж��Ƿ�Ϊ��

	MQ mq;
	initQueue(&mq);
	if (isEmpty(&mq)) {
		printf("NULL\n");
	}
	else
	{
		printf("�ʹ�ɻ���");
	}

	system("pause");
	return 0;
}
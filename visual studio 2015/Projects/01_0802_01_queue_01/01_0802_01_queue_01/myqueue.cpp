#include"myqueue.h"
#include<stdio.h>

void initQueue(MQ * mq) {
	mq->front = mq->rear = 0;
	mq->num[N] = { 0 };
}


int isEmpty(MQ *mq) {

	if (mq->front == mq->rear) {
		return 1;
	}
	else
	{
		return 0;
	}

}

void show(MQ *mq) {
	if (mq->front == mq->rear) {
		printf("queue is null\n");
	}
	else {
		
		for (int i = mq->front;i < mq->rear;i++) {//ע�����ﲻ�ܵ���mq.rear,mq.rear�ǻ�û�����Ԫ�ص�λ��,rearֻ�Ǳ�ʾ��ʾ����β�������λ��
			printf("%d ", mq->num[i]);
		}
	}
}
void show2(MQ mq) {
	if (mq.front == mq.rear) {
		printf("queue is null\n");
	}
	else {

		for (int i = mq.front;i < mq.rear;i++) {//ע�����ﲻ�ܵ���mq.rear,mq.rear�ǻ�û�����Ԫ�ص�λ��,rearֻ�Ǳ�ʾ��ʾ����β�������λ��
			printf("%d ", mq.num[i]);
		}
	}
}

int addNode(MQ *mq,int num) {
	if (mq->rear == N) {
		return 0;
	}
	else {

	mq->num[mq->rear] = num;
	mq->rear++;
	return 1;
	}
}

/*
MQ*  popNode(MQ *mq) {
	MQ* head;
	head = mq;
	if (mq->front < mq->rear) {
		mq->front++;
		return head;//rear�Ǵ洢�ڶ��нṹ���ڵ�,���headֻ��ָ���������,�����������ڲ���rear
	}
	else
	{
		return NULL;
	}
}
*/

datatype deQueue(MQ *mq) {
	if (mq->front == mq->rear) {
		return -1;
	}
	mq->front++;
	return mq->num[mq->front - 1];
}



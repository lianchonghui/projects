#include<stdio.h>
#include<stdlib.h>
#include"linkedQueue.h"

//������г�ʼ��
LQ *init(LQ *queue) {
	return NULL;
}

LQ * enQueue(LQ *queue,int num,int high) {
	if (queue == NULL) {
		LQ * newNode = (LQ *)malloc(sizeof(LQ));
		newNode->high = high;
		newNode->num = num;
		newNode->pNext = NULL;

		return newNode;
	}
	else
	{
		LQ * p = queue;
		while (p->pNext != NULL)
		{
			p = p->pNext;
		}

		LQ * newNode = (LQ *)malloc(sizeof(LQ));
		newNode->high = high;
		newNode->num = num;
		newNode->pNext = NULL;
		p->pNext = newNode;
		return queue;
	}
}

void printfall(LQ *queue) {
	if (queue == NULL) {
		//printf("�������Ϊ��\n");
		return;
	}
	else
	{
		
			printf("num:%d,high:%d,pNext:%p\n", queue->num, queue->high, queue->pNext);
			//p = p->pNext;
			printfall(queue->pNext);//�ݹ��ӡ���нڵ�
		
	}
}

LQ * deLinkedQueue(LQ *queue, LQ *pout) {
	if(queue==NULL){
		printf("�������Ϊ��\n");
		return NULL;
	}
	else
	{
		if (pout == NULL) {
			pout = (LQ *)malloc(sizeof(LQ));
		}
		pout->high = queue->high;
		pout->num = queue->num;
		pout->pNext = queue->pNext;
		
		queue = queue->pNext;
		

		return queue;

	}
}


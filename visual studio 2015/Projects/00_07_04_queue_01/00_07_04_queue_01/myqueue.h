#include<stdio.h>
#include<stdlib.h>

#define N 100
#define datatype char

//�ṹ�����
struct myqueue
{
	datatype data[N];
	int front;//��¼��ͷ
	int rear;//��¼��β
};

//���еĽӿ�
typedef struct myqueue MQ;

void initQueue(MQ *mq);
int isempty(MQ *mq);
datatype gehead(MQ *mq);
void enQueue(MQ *mq, datatype data);

datatype deQueue(MQ *mq);
void showQueue(MQ *mq);


int demo();



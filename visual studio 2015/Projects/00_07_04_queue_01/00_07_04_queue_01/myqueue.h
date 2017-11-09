#include<stdio.h>
#include<stdlib.h>

#define N 100
#define datatype char

//结构体队列
struct myqueue
{
	datatype data[N];
	int front;//记录对头
	int rear;//记录队尾
};

//对列的接口
typedef struct myqueue MQ;

void initQueue(MQ *mq);
int isempty(MQ *mq);
datatype gehead(MQ *mq);
void enQueue(MQ *mq, datatype data);

datatype deQueue(MQ *mq);
void showQueue(MQ *mq);


int demo();



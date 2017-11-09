#include"myqueue.h"

//对数组队列的理解
 //1.数组队列的元素固定,不管有没有弹出,总共可使用的的位置都随着插入而减少
 //2.数组队列的函数一般都使用指针作为参数,这是因为函数除数组参数外都有副本机制,如果想改变队列,必须传入指向该对列的指针
 //3.队列从的数据从数组头弹出,用front改变第一个元素位置,从尾部插入,rear++

//对链表队列的理解
 //1.链表队列元素数不固定,具有链表的特性,元素懂链表尾部插入,从head弹出,就此改版head的指向
 //2.所以链表队列的函数一般传入head指针,并返回head指针




void initQueue(MQ *mq) {//数组队列的函数一般都使用指针作为参数,这是因为函数除数组参数外都有副本机制,如果想改变队列,必须传入指向该对列的指针
	mq->front = mq->rear = 0;//实现队列的初始化,等价于
}

int isempty(MQ *mq) {
	if (mq->front == mq->rear) {
		return 1;//1表示为空
	}else
	{
		return 0;
	}
}


datatype gehead(MQ *mq) {
	if (mq->front == mq->rear) {
		return -1;//队列为空,返回-1

	}
	return mq->data[mq->front];//头部出,尾部进
}

void enQueue(MQ *mq, datatype data) {
	if (mq->rear == N) {//队尾在哪里,就在哪里插入,队尾为N-1就是最后一个元素,当rear==N的时候表示队列已满
		printf("队列已满");
		return;
	}
	mq->data[mq->rear]=data;
	mq->rear++;//队尾小标向前移动一个
}

datatype deQueue(MQ *mq) {
	if (mq->front == mq->rear) {
		return -1;//队列为空返回-1
	}
	mq->front++;//删除一个元素，向前移动一个
	return mq->data[mq->front - 1];//返回前一个即删除的元素
}

void showQueue(MQ *mq) {
	if (mq->front == mq->rear) {
		return;
	}
	else
	{
		printf("\n");
		for (int i = mq->front;i < mq->rear;i++) {
			printf("%c", mq->data[i]);
		}
	}
}
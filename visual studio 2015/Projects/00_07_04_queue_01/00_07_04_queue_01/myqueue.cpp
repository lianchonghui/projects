#include"myqueue.h"

//��������е����
 //1.������е�Ԫ�ع̶�,������û�е���,�ܹ���ʹ�õĵ�λ�ö����Ų��������
 //2.������еĺ���һ�㶼ʹ��ָ����Ϊ����,������Ϊ��������������ⶼ�и�������,�����ı����,���봫��ָ��ö��е�ָ��
 //3.���дӵ����ݴ�����ͷ����,��front�ı��һ��Ԫ��λ��,��β������,rear++

//��������е����
 //1.�������Ԫ�������̶�,�������������,Ԫ�ض�����β������,��head����,�ʹ˸İ�head��ָ��
 //2.����������еĺ���һ�㴫��headָ��,������headָ��




void initQueue(MQ *mq) {//������еĺ���һ�㶼ʹ��ָ����Ϊ����,������Ϊ��������������ⶼ�и�������,�����ı����,���봫��ָ��ö��е�ָ��
	mq->front = mq->rear = 0;//ʵ�ֶ��еĳ�ʼ��,�ȼ���
}

int isempty(MQ *mq) {
	if (mq->front == mq->rear) {
		return 1;//1��ʾΪ��
	}else
	{
		return 0;
	}
}


datatype gehead(MQ *mq) {
	if (mq->front == mq->rear) {
		return -1;//����Ϊ��,����-1

	}
	return mq->data[mq->front];//ͷ����,β����
}

void enQueue(MQ *mq, datatype data) {
	if (mq->rear == N) {//��β������,�����������,��βΪN-1�������һ��Ԫ��,��rear==N��ʱ���ʾ��������
		printf("��������");
		return;
	}
	mq->data[mq->rear]=data;
	mq->rear++;//��βС����ǰ�ƶ�һ��
}

datatype deQueue(MQ *mq) {
	if (mq->front == mq->rear) {
		return -1;//����Ϊ�շ���-1
	}
	mq->front++;//ɾ��һ��Ԫ�أ���ǰ�ƶ�һ��
	return mq->data[mq->front - 1];//����ǰһ����ɾ����Ԫ��
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
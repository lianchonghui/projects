
#include<stdio.h>
#include<stdlib.h>
#define N 100

struct mystack {
	int top;
	int data[N];
	
};
typedef struct mystack MS;

//����ջ�����
//1.ģ��ջ�Ľṹ������:(����ջ)
	//a.ջ��Ԫ���Ǵ洢�������е�,����Ĺ̶���С��,����ջ�Ĵ�СҲ�ǹ̶���.
	//b.����ĳ�ʼ�±���0,���Ե���һ��Ԫ�ص�ʱ��top����Ϊ0,��ջΪ�յ�ʱ��top=-1,�����Ϳ�����data[top]��ʾջ������
	//c.ջ���ٽ�������top+1==N-1,����-1��ʼ�㵽N-2,��N��Ԫ��
	//d.ջ��Ԫ�ظ���ͳ����top+1,��topΪ-1,��û��top+1=0
//2.��ʽջ�����
	//a.�޹��޹��Ƿ����ӡ,���Ƿ��ӡ�Ƚ��Ľڵ㻹�Ǻ���Ľڵ�,ջ�ı������ȵ������һ��Ԫ��
	//b.����ջ�������һ��Ԫ����������top,ջ����¼,��¼�������Ԫ��,
	//c.��ʽջ�������һ��Ԫ��,��������ÿ��ѭ��������ĩβ,�����һ���ڵ㵯��,��ջ�׳�ջ.ͬ��,����Ԫ��Ҳ�Ǵ�ջ�ײ���,��ʽջû��ջ����¼,���һ���ڵ�p->pnext=NULL,pΪ���һ���ڵ�.
//3.����ջ����ʽջ��ͬ�����
	//a.����ջ�൱��|_|,��ջ��;��ʽջ�൱��|~|,��ջ��,�������������Ƚ����

//��ʽջ
struct liststack {
	int data;
	struct liststack *pnext;
};
typedef struct liststack LS;





//����ջ
int isempty();
void setempty();
int push(int data);
int pop();

//��ʽջ
LS *init(LS* phead);
LS* pushls(LS *phead, int data);
LS * printfall(LS * phead);
LS * popls(LS *phead, LS* poutdata);
LS * freeall0(LS* phead);
LS * freeall(LS* phead);
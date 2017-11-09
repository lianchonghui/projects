#include"mystack.h"

//����ջ�Ķ���ͳ�ʼ��
MS mystack = { -1,{ 0 } };

//��ʽջ�ĺ���

//��ʽջ�Ķ���ͳ�ʼ��
LS *init(LS *phead) {
	return NULL;
}

LS* pushls(LS *phead, int data) {

	//�����ڵ�,�����ڴ�,����ʼ��
	LS * pnewnode = (LS*)malloc(sizeof(LS));
	pnewnode->data = data;
	pnewnode->pnext = NULL;//���ٽڵ㲢��ֵ


	//��ջΪ��ʱ,������Ϊ��
	if (phead == NULL) {
		phead = pnewnode;
	}
	else
	{
		LS *p = phead;
		while (p->pnext!=NULL)
		{
			p = p->pnext;//����ڵ㲻����ǰ,�������һ���ڵ�����ѭ��
		}
		//�����һ���ڵ����
		p->pnext = pnewnode;
	}
	return phead;



}


LS * printfall(LS * phead) {
	if (phead == NULL) {
		return NULL;
	}
	else
	{
		printfall(phead->pnext);//���õݹ�����,�����ӡ�����ڵĽڵ�����
		//�޹��޹��Ƿ����ӡ,���Ƿ��ӡ�Ƚ��Ľڵ㻹�Ǻ���Ľڵ�,ջ�ı������ȵ������һ��Ԫ��
		//����ջ�������һ��Ԫ����������top,ջ����¼,��¼�������Ԫ��,
		//��ʽջ�������һ��Ԫ��,��������ÿ��ѭ��������ĩβ,�����һ���ڵ㵯��,��ʽջû��ջ����¼,���һ���ڵ�p->pnext=NULL,pΪ���һ���ڵ�.
		printf("%d,%p,%p\n", phead->data, phead, phead->pnext);
	}
}

LS * popls(LS *phead, LS* poutdata) {//poutdata���յ�����Ԫ��,����û������ָ��,�����յ���������
	if (phead == NULL) {
		return NULL;
	}
	else if (phead->pnext == NULL) {
		if (poutdata != NULL) {

		poutdata->data = phead->data;//ֻ��һ���ڵ�
		}
		free(phead);//����Ψһ��Ԫ��,��ջ��ֵΪNULL,������
		phead = NULL;
		return phead;
	}
	else
	{
		LS *p = phead;
		while (p->pnext->pnext!=NULL)
		{
			p = p->pnext;//ѭ���������ڶ����ڵ�,��Ϊ���һ���ڵ�Ҫ������,���ͷ��ڴ�,���ѭ�������һ���ڵ�,��Ҫ����ָ���޸ĵ����ڶ����ڵ��pnext=NULL;
		}
		if (poutdata != NULL) {

			poutdata->data = phead->data;//ֻ��һ���ڵ�
		}
		free(p->pnext);
		p->pnext = NULL;


	}
	return phead;

}

//��ʽջ���ջ,�൱�ڲ��ϵ�ջ,ֱ��ΪNULL
LS * freeall0(LS* phead) {
	while (phead)
	{
		phead = popls(phead,NULL);//��ʽջ���ջ,�൱�ڲ��ϵ�ջ,ֱ��ΪNULL.������NULL���յ���������,������������

	}
	return phead;
}

LS* freeall(LS * phead) {
	if (phead == NULL) {
		return phead;
	}
	else
	{
		LS* ls1, *ls2;
		ls1 = ls2 = NULL;
		ls1 = phead;//��ls1ָ��head,ls1->pnext���ϵ���,freeһ��,����һ��ֱ��Ϊls1->pnext==NULL;����ls2����ָ����һ��
		while (ls1->pnext!=NULL)
		{
			//��ls2�洢ls1->pnext�Ľڵ�,ls2����ָ����һ��,��ls1->pnext����ָ��ls2
			ls2 = ls1->pnext;
			//��ls1->pnextָ��ls2����һ��,Ȼ���ͷ�ls2,
			ls1->pnext = ls2->pnext;
			free(ls2);
		}
		//����ͷ�head
		free(phead);
		phead = NULL;
		return phead;

	}
}




//����ջ�ĺ���
int isempty() {

	if (mystack.top == -1) {
		return 1;
	}
	else
	{
		return 0;//����0��ʾisempty
	}
	
}

void setempty() {
	mystack.top = -1;

}


int push(int data) {
	if (mystack.top + 1 <= N - 1) {//��0��ʼ������N-1��N��
		mystack.data[mystack.top + 1] = data;//top��ʼֵΪ-1,�������ʼ�±�Ϊ0
		mystack.top += 1;
		return 1;//�ɹ�����1;
	}
	else {
		return 0;//ջ���,ʧ��,����0;
	}
}

int pop() {

	//�ݴ����ж�,����Ϊ���˼�����������
	if (isempty() == 0) {//1����ջΪ��,0����Ϊ��
		mystack.top -= 1;//ÿ����һ��,ջ��Ԫ�ؼ�1
		return mystack.data[mystack.top + 1];//����ջ������
	}
	else
	{
		return -1;//ջΪ�շ���-1
	}


}



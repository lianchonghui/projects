#include"mystack.h"

//数组栈的定义和初始化
MS mystack = { -1,{ 0 } };

//链式栈的函数

//链式栈的定义和初始化
LS *init(LS *phead) {
	return NULL;
}

LS* pushls(LS *phead, int data) {

	//创建节点,分配内存,并初始化
	LS * pnewnode = (LS*)malloc(sizeof(LS));
	pnewnode->data = data;
	pnewnode->pnext = NULL;//开辟节点并赋值


	//当栈为空时,即链表为空
	if (phead == NULL) {
		phead = pnewnode;
	}
	else
	{
		LS *p = phead;
		while (p->pnext!=NULL)
		{
			p = p->pnext;//链表节点不断向前,当到最后一个节点跳出循环
		}
		//在最后一个节点插入
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
		printfall(phead->pnext);//利用递归特性,倒序打印链表内的节点数据
		//无关无关是否倒序打印,即是否打印先进的节点还是后进的节点,栈的本质是先弹出最后一个元素
		//数组栈弹出最后一个元素依靠的是top,栈顶记录,记录最后插进的元素,
		//链式栈弹出最后一个元素,依靠的是每次循环到链表末尾,将最后一个节点弹出,链式栈没有栈顶记录,最后一个节点p->pnext=NULL,p为最后一个节点.
		printf("%d,%p,%p\n", phead->data, phead, phead->pnext);
	}
}

LS * popls(LS *phead, LS* poutdata) {//poutdata接收弹出的元素,如果用户传入空指针,不接收弹出的数据
	if (phead == NULL) {
		return NULL;
	}
	else if (phead->pnext == NULL) {
		if (poutdata != NULL) {

		poutdata->data = phead->data;//只有一个节点
		}
		free(phead);//弹出唯一的元素,对栈赋值为NULL,并返回
		phead = NULL;
		return phead;
	}
	else
	{
		LS *p = phead;
		while (p->pnext->pnext!=NULL)
		{
			p = p->pnext;//循环到倒数第二个节点,因为最后一个节点要被弹出,并释放内存,如果循环到最后一个节点,需要辅助指针修改倒数第二个节点的pnext=NULL;
		}
		if (poutdata != NULL) {

			poutdata->data = phead->data;//只有一个节点
		}
		free(p->pnext);
		p->pnext = NULL;


	}
	return phead;

}

//链式栈清空栈,相当于不断弹栈,直到为NULL
LS * freeall0(LS* phead) {
	while (phead)
	{
		phead = popls(phead,NULL);//链式栈清空栈,相当于不断弹栈,直到为NULL.这里用NULL接收弹出的数据,即不接收数据

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
		ls1 = phead;//令ls1指向head,ls1->pnext不断递增,free一个,递增一个直到为ls1->pnext==NULL;利用ls2不断指向下一个
		while (ls1->pnext!=NULL)
		{
			//用ls2存储ls1->pnext的节点,ls2不断指向下一个,而ls1->pnext不断指向ls2
			ls2 = ls1->pnext;
			//令ls1->pnext指向ls2的下一个,然后释放ls2,
			ls1->pnext = ls2->pnext;
			free(ls2);
		}
		//最后释放head
		free(phead);
		phead = NULL;
		return phead;

	}
}




//数组栈的函数
int isempty() {

	if (mystack.top == -1) {
		return 1;
	}
	else
	{
		return 0;//返回0表示isempty
	}
	
}

void setempty() {
	mystack.top = -1;

}


int push(int data) {
	if (mystack.top + 1 <= N - 1) {//从0开始计数到N-1共N个
		mystack.data[mystack.top + 1] = data;//top初始值为-1,而数组初始下标为0
		mystack.top += 1;
		return 1;//成功返回1;
	}
	else {
		return 0;//栈溢出,失败,返回0;
	}
}

int pop() {

	//容错性判断,避免为空了继续弹出数据
	if (isempty() == 0) {//1代表栈为空,0代表不为空
		mystack.top -= 1;//每弹出一个,栈内元素减1
		return mystack.data[mystack.top + 1];//弹出栈顶数据
	}
	else
	{
		return -1;//栈为空返回-1
	}


}




#include<stdio.h>
#include<stdlib.h>
#define N 100

struct mystack {
	int top;
	int data[N];
	
};
typedef struct mystack MS;

//关于栈的理解
//1.模拟栈的结构体的理解:(数组栈)
	//a.栈的元素是存储在数组中的,数组的固定大小的,所以栈的大小也是固定的.
	//b.数组的初始下标是0,所以当有一个元素的时候top设置为0,当栈为空的时候top=-1,这样就可以用data[top]表示栈内数据
	//c.栈的临界条件是top+1==N-1,即从-1开始算到N-2,共N个元素
	//d.栈的元素个数统计是top+1,当top为-1,就没有top+1=0
//2.链式栈的理解
	//a.无关无关是否倒序打印,即是否打印先进的节点还是后进的节点,栈的本质是先弹出最后一个元素
	//b.数组栈弹出最后一个元素依靠的是top,栈顶记录,记录最后插进的元素,
	//c.链式栈弹出最后一个元素,依靠的是每次循环到链表末尾,将最后一个节点弹出,即栈底出栈.同样,插入元素也是从栈底插入,链式栈没有栈顶记录,最后一个节点p->pnext=NULL,p为最后一个节点.
//3.数组栈和链式栈异同的理解
	//a.数组栈相当于|_|,有栈顶;链式栈相当于|~|,有栈底,不管怎样都是先进后出

//链式栈
struct liststack {
	int data;
	struct liststack *pnext;
};
typedef struct liststack LS;





//数组栈
int isempty();
void setempty();
int push(int data);
int pop();

//链式栈
LS *init(LS* phead);
LS* pushls(LS *phead, int data);
LS * printfall(LS * phead);
LS * popls(LS *phead, LS* poutdata);
LS * freeall0(LS* phead);
LS * freeall(LS* phead);
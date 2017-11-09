
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

struct list {
	int num;
	struct list * pnext;
};

typedef struct list SL;


int main() {

	//数组排序：冒泡排序，选择排序重温
	int arr1[10];
	srand((unsigned int)time(0));
	for (int i = 0;i < 10; i++) {
		arr1[i] = rand() % 100;
		printf("%d,",arr1[i]);
	}
	putchar('\n');

	int size = sizeof(arr1);
	printf("%d", size/sizeof(int));

	putchar('\n');

	int arr2[10] = { 0 };
	for (int i = 0;i < 10;i++) {
		arr2[i] = arr1[i];
		printf("%d,", arr2[i]);
	}

	putchar('\n');
	arrbsort(arr1,10);
	
	arrssort(arr2, 10);

	for (int i = 0;i < 10;i++) {
		printf("%d,", arr1[i]);
	}
	putchar('\n');
	for (int i = 0;i < 10;i++) {
		printf("%d,", arr2[i]);
	}
	
	//int *parr = arr1;
	//printf("%d\n", sizeof(parr));
	////int *[10] parr2 = &arr1;
	//int(*parr2)[10] = &arr1;
	system("pause");
	return 0;
}


int main12() {

	//关于time()和time_t类型,srand(),rand()随机数的产生

	//time_t time(time_t *t);
	//time_t其实是long int,用来存储当前时间的数据类型.
	//此函数会返回从公元1970年1月1日的UTC时间从0时0分0秒算起到现在所经过的秒数。如果t 并非空指针的话，此函数也会将返回值存到t指针所指的内存。
	//返回值:成功则返回秒数，失败则返回((time_t)-1)值，错误原因存于errno中。
	//可以根据需要选择。当参数t为空指针(NULL)时，只返回值。
	//而NULL的定义是(void *) 0， 所以time(0)也就是time(NULL)的另一种写法，表示只通过返回值获取时间值。
	
	
	//srand(unsigned int),接收一个unsigned int数为种子,通常采用time()函数获取当前时间作为种子,
	//注意time(time_t *t),可以传入一个time_t类型指针,也可以传入NULL或者0表示空指针,也就值能通过返回值回去时间值,不能通过t指针获取时间值

	//随机数产生:
	//1.传入种子srand((unsigned int)time(0));
	//2.rand()获取随机数

	int num=0;
	//time_t(num);

	printf("%d\n", (int)time_t(num));

	time_t timeNum;
	time_t t=time(&timeNum);
	printf("%d\n", timeNum / 365 / 24 / 60 / 60);
	printf("%d\n", t/365/24/60/60);
	//t==timeNum;


	long int timeNumi=0;
	time_t tt = (time_t)timeNumi;
	time(&tt);
	timeNumi = (long int)tt;
	printf("%d\n", timeNumi / 365 / 24 / 60 / 60);
	printf("%d\n", tt / 365 / 24 / 60 / 60);




	//srand((unsigned int)time(&timeNum));
	srand((unsigned int)time(0));
	for (int i = 0;i < 100;i++) {
		int num=rand() % 100;
		printf("%d\n", num);
	}

	system("pause");
	return 0;
}





int main11() {

	//链表节点数的统计
	SLD * ps1, *ps2, *ps3, *ps4, *ps5;
	ps1 = (SLD *)malloc(sizeof(SLD));
	ps2 = (SLD *)malloc(sizeof(SLD));
	ps3 = (SLD *)malloc(sizeof(SLD));
	ps4 = (SLD *)malloc(sizeof(SLD));
	ps5 = (SLD *)malloc(sizeof(SLD));

	ps1->num = 1;
	ps1->pnext = ps2;
	ps2->num = 2;
	ps2->pnext = ps3;
	ps3->num = 3;
	ps3->pnext = ps4;
	ps4->num = 4;
	ps4->pnext = ps5;
	ps5->num = 5;
	ps5->pnext = NULL;

	SLD * head = ps1;
	printf("节点总数为:%d\n", sum(head));

	ps5->pnext = ps1;
	show(head);
	printf("节点总数为:%d\n", sum(head));

	system("pause");
	return 0;
}


int main10() {

	//链表的排序
	SLD* head = NULL;
	add(&head, 11);
	add(&head, 2);
	add(&head, 32);
	add(&head, 12);
	add(&head, 41);

	show(head);

	printf("节点个数为:%d\n", sum(head));
	bsort2(head);

	show(head);


	system("pause");

	return 0;
}


int main9() {
	
	//链表逆序
	SLD *head = NULL;
	
	add(&head, 11);
	add(&head, 22);
	add(&head, 33);
	add(&head, 44);
	add(&head, 55);

	show(head);
	head = reverse(head);
	show(head);

	system("pause");
	return 0;
}


int main8() {

	//节点前插入和节点后插入
	SLD* head = NULL;
	head = frontInsert(head, 11,11);
	show(head);
	add(&head, 11);
	add(&head, 22);
	add(&head, 33);
	add(&head, 44);
	show(head);

	head = frontInsert(head, 11, 0);
	show(head);
	head = frontInsert(head, 33, 333);
	show(head);
	head = frontInsert(head, 123, 321);
	show(head);
	printf("---------\n");
	head = backInsert(head, 22, 222);
	show(head);
	head = backInsert(head, 123, 321);
	show(head);

	system("pause");
	return 0;
}


int main7() {

	//链表头部插入和尾部插入
	SLD* head = NULL;
	//head=headInsert(head, 11);
	//show(head);
	//head = headInsert(head, 22);
	//head = headInsert(head, 33);
	//head = headInsert(head, 44);
	//show(head);

	//尾部插入

	head = lastInsert(head, 11);
	show(head);
	head = lastInsert(head, 22);
	head = lastInsert(head, 33);
	head = lastInsert(head, 44);
	head = lastInsert(head, 55);

	show(head);
	system("pause");
	return 0;
}


int main6() {

	//链表节点的增加

	SLD* head = NULL;
	show(head);

	//通过函数返回值赋值给head改变head指向的链表
	//head = myAdd(head, 11);
	//show(head);
	//head = myAdd(head, 22);
	//head = myAdd(head, 33);
	//show(head);

	//通过二级指针改变head
	add(&head, 11);
	show(head);
	add(&head, 22);
	add(&head, 33);
	show(head);

	system("pause");
	return 0;
}


int main5() {

	//删除链表所有节点
	//两种方式:
	//方式1:创建两个辅助指针p1,p2,p1=head;p2=p1-pnext;p1->pnext=p2->pnext;free(p2),不断递增p1->pnext直到为NULL时停止,最后释放head
	//方式2:创建一个辅助指针p;p=head->pnext;head=head->pnext;free(p),即头部不断向前,把之前头部释放,最后释放head,就是释放最后一个节点

	SLD * ps1, *ps2, *ps3, *ps4, *ps5;
	ps1 = (SLD *)malloc(sizeof(SLD));
	ps2 = (SLD *)malloc(sizeof(SLD));
	ps3 = (SLD *)malloc(sizeof(SLD));
	ps4 = (SLD *)malloc(sizeof(SLD));
	ps5 = (SLD *)malloc(sizeof(SLD));

	ps1->num = 1;
	ps1->pnext = ps2;
	ps2->num = 2;
	ps2->pnext = ps3;
	ps3->num = 3;
	ps3->pnext = ps4;
	ps4->num = 4;
	ps4->pnext = ps5;
	ps5->num = 5;
	ps5->pnext = NULL;


	SLD * head = NULL;
	head = ps1;

	show(head);

	//head = deleteNode(head,4);
	head=deleteAll3(head);
	show(head);
	system("pause");
	return 0;
}



int main4() {

	//链表的遍历show()和链表节点的删除
	//引出的问题:free()函数的使用问题:只试用与动态模式链表;链表的表示问题:通过一个指针head指向头部地址

	//对于一个链表,要先创建一个head的链表指针指向这个链表的头部,这个head指针的作用相当于链表的首地址,就像数组一样,不过数组的首地址不可变,而一个链表的首地址(头部)可以改变
	//而链表首地址的改变就就是head指针变量值得改变.
	//因为链表的首地址是可变的,所以当头部改变(头部删除,头部插入等)以后重新遍历链表的时候就要从新的头部开始遍历,head指针就是存储首地址的作用
	//另外,当用函数改变链表的时候,因为传入的指针有副本机制,虽然通过指针可以改变其真实值.但是当改变头部的时候,我们传入的不是链表头部的首地址
	//而是传入一个指向链表的head指针,因为传入的指针有副本机制,即head的一个副本,有两种方式改变head指针:二级指针和函数返回值进行重新赋值
	//当然采用void返回值,同样改变链表生效,前提是在不改变头部的情况下,且可以传入链表的头部地址,而不用传入head指针.前提是在不改变头部的情况下

	//关于使用free函数报错:free函数只适用于释放malloc/calloc/realloc内存
	//下面这里对非malloc内存进行释放就会报错,即我们一般使用链表动态模式
	//与malloc()函数配对使用，释放malloc函数申请的动态内存。（另：对于free(p)这句语句，如果p 是NULL 指针，那么free 对p 无论操作多少次都不会出问题。如果p 不是NULL 指针，那么free 对p连续操作两次就会导致程序运行错误。）
	
	SLD l1, l2, l3, l4, l5;
	l1.num = 1;
	l1.pnext = &l2;
	l2.num = 2;
	l2.pnext = &l3;
	l3.num = 3;
	l3.pnext = &l4;
	l4.num = 4;
	l4.pnext = &l5;
	l5.num = 5;
	l5.pnext = NULL;

	SLD* head = NULL;
	head = &l1;
	show(head);


	//head = &l1;
	//head=deleteNode(head, 3);
	deleteNode1(head, 2);
	//head = &l1;
	show(head); 
	show(&l1);
	system("pause");
	return 0;
}


int main3() {

	SL l1, l2, l3, l4, l5;
	l1.num = 1;
	l1.pnext = &l2;
	l2.num = 2;
	l2.pnext = &l3;
	l3.num = 3;
	l3.pnext = &l4;
	l4.num = 4;
	l4.pnext = &l5;
	l5.num = 5;
	l5.pnext = NULL;

	//对于遍历链表,读取的时候就像一个游标不断向前移动,就像数组,数组的读取就是通过下标或指针递增遍历,而链表根据其结构(存储了下一个元素的地址)可以通过指针遍历

	SL * psl = &l1;
	while (psl!= NULL) {//指针不断向前移动,
		printf("%d,%p\n", psl->num, psl->pnext);
		psl = psl->pnext;//指针不断向前移动,直到最后一个链表元素的pnext赋值为NULL
	}
	

	
	system("pause");
	return 0;
}

int main2() {

	//链表动态模式
	SL *pl1, *pl2;
	pl1 = (SL*)malloc(sizeof(SL));
	pl2 = (SL*)malloc(sizeof(SL));


	//方式1
	//pl1->num = 1;
	//pl1->pnext = pl2;
	//pl2->num = 2;
	//pl2->pnext = NULL;

	//方式2
	(*pl1).num = 1;
	(*pl1).pnext = pl2;
	(*pl2).num = 2;
	(*pl2).pnext = NULL;


	printf("%d,%p\n", pl1->num, pl1->pnext);


	system("pause");
	return 0;
}



int main1() {

	//链表静态模式

	SL l1, l2;
	l1.num = 1;
	l1.pnext = &l2;
	l2.num = 2;
	l2.pnext = NULL;

	printf("%d,%p\n", l1.num, l1.pnext);


	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"



void arrssort(int arr[], int num) {
	int tempnum;
	for (int out = 0;out < num - 1;out++) {
		for (int in = out + 1;in < num;in++) {
			if (arr[out] > arr[in]) {
				tempnum = arr[out];
				arr[out] = arr[in];
				arr[in] = tempnum;
			}
		}
	}
}

void arrbsort(int arr[],int num) {
	//数组冒泡排序

	//c语言中，定义数组后可以用sizeof命令获得数组的长度（可容纳元素个数）
	//	如：
	//{
	//	int data[4];
	//int length;
	//length = sizeof(data) / sizeof(data[0]);  //数组占内存总空间，除以单个元素占内存空间大小
	//printf("length of data[4]=%d", length); //输出length of data[4]=4
	//}
	//	但，通过传递数组名参数到子函数中，以获得数组长度是不可行的。如：
	//	int getLength(int[] a) {
	//	int length;
	//	length = sizeof(a) / sizeof(a[0]); //这样是错误的，得到的结果永远是1
	//	return length;
	//}
	//因为，a是函数参数，到了本函数中，a只是一个指针（地址，系统在本函数运行时，是不知道a所表示的地址有多大的数据存储空间，这里只是告诉函数：一个数据存储空间首地址），所以，sizoef(a)的结果是指针变量a占内存的大小，一般在32位机上是4个字节。a[0]是int类型，sizeof(a[0])也是4个字节，所以，结果永远是1。
	//因此，获得数组长度，只能在数组定义所在的代码区中，采用以上方法，才可以达到效果。

	
	int tempnum;
	for (int out = 0;out < num - 1;out++) {
		for (int in = 0;in < num - out - 1;in++) {
			if (arr[in] > arr[in + 1]) {
				tempnum = arr[in];
				arr[in] = arr[in + 1];
				arr[in + 1] = tempnum;
			}
		}
	}


}
void arrbsort1(int arr[]) {
	//数组冒泡排序

	//c语言中，定义数组后可以用sizeof命令获得数组的长度（可容纳元素个数）
	//	如：
	//{
	//	int data[4];
	//int length;
	//length = sizeof(data) / sizeof(data[0]);  //数组占内存总空间，除以单个元素占内存空间大小
	//printf("length of data[4]=%d", length); //输出length of data[4]=4
	//}
	//	但，通过传递数组名参数到子函数中，以获得数组长度是不可行的。如：
	//	int getLength(int[] a) {
	//	int length;
	//	length = sizeof(a) / sizeof(a[0]); //这样是错误的，得到的结果永远是1
	//	return length;
	//}
	//因为，a是函数参数，到了本函数中，a只是一个指针（地址，系统在本函数运行时，是不知道a所表示的地址有多大的数据存储空间，这里只是告诉函数：一个数据存储空间首地址），所以，sizoef(a)的结果是指针变量a占内存的大小，一般在32位机上是4个字节。a[0]是int类型，sizeof(a[0])也是4个字节，所以，结果永远是1。
	//因此，获得数组长度，只能在数组定义所在的代码区中，采用以上方法，才可以达到效果。

	int num = sizeof(arr) / sizeof(int);
	printf("%d", sizeof(arr));
	int tempnum;
	for (int out = 0;out < num - 1;out++) {
		for (int in = 0;in < num - out - 1;in++) {
			if (arr[in] > arr[in + 1]) {
				tempnum = arr[in];
				arr[in] = arr[in + 1];
				arr[in + 1] = tempnum;
			}
		}
	}


}

void bsort2(SLD* head) {
	//利用节点数控制循环次数,采用冒泡排序对链表排序


	//获取节点数
	int total = sum(head);
	SLD tempsld;

	for (int i = 0;i < total;i++) {
		/*for (SLD* pi = head, int j = 0;j < total - 1 - i;j++, pi = pi->pnext) {//for循环内不允许初始化多个变量
			if (pi->num > pi->pnext->num) {

				tempsld.num = pi->num;
				pi->num = pi->pnext->num;
				pi->pnext->num = tempsld.num;

			}

		}*/

		{
			SLD* pi = head;
			int j = 0;
			for (;j < total - 1 - i;j++, pi = pi->pnext) {
				if (pi->num > pi->pnext->num) {

				tempsld.num = pi->num;
				pi->num = pi->pnext->num;
				pi->pnext->num = tempsld.num;

				}

			}
		}

		/*SLD* pi = head;
		int j = 0;
		while (j<total-i-1)
		{
			if (pi->num > pi->pnext->num) {

				tempsld.num = pi->num;
				pi->num = pi->pnext->num;
				pi->pnext->num = tempsld.num;

			}
			j++;
			pi = pi->pnext;
		}*/

	}

}

int sum(SLD* head) {
	//统计节点数
	int total = 0;
	SLD* p = NULL;
	p = head;
	while (p!=NULL)
	{
		total++;
		p = p->pnext;
		if (p == head) {
			//total--;
			break;
		}
	}
	return total;
}

void bsort(SLD* head) {
	//冒泡排序排序链表,由于链表的局限性,所以每次冒泡排序都要从头比较到尾部;


	//SLD* lastNode = NULL;
	SLD tempsld;
	if (head == NULL) {
		return;
	}
	for (SLD* po = head;po->pnext != NULL;po = po->pnext) {//冒泡轮回的次数,就是借点数N-1次

		for (SLD* pi = head;pi->pnext != NULL;pi = pi->pnext) {
			if (pi->num > pi->pnext->num) {
				tempsld.num = pi->num;
				pi->num = pi->pnext->num;
				pi->pnext->num = tempsld.num;
			}
		}

	}

}

void sort(SLD* head) {
	
	//一般链表的排序,采用的是数值交换,而不是改变pnext的地址,这样就适合用选择排序
	//int tempnum;
	SLD tempsld;//一般使用结构体,便于对结构体内多个元素的使用

	for (SLD* po = head;po->pnext != NULL;po = po->pnext) {
		for (SLD* pi = po->pnext;pi != NULL;pi=pi->pnext) {
			if (po->num > pi->num) {
				tempsld.num = po->num;
				po->num = pi->num;
				pi->num = tempsld.num;
			}
		}
	}




}

SLD* reverse2(SLD* head) {
	
	SLD *pb, *pc, *pf;
	pb = pc = pf = NULL;

	//如果只有一个节点或者链表为空
	if (head == NULL || head->pnext == NULL) {
		return head;
	}

	//从第二个节点开始
	pb = head;
	pc = head->pnext;

	while (pc != NULL) {
		//这里采用一个临时指针存储当前指针指向的下一个节点,当前指针递增遍历

		//第三个指针指向当前节点的下一个节点
		pf = pc->pnext;
		
		//当前节点的pnext指向前一个节点
		pc->pnext = pb;

		//p1,p2向前递增
		pb = pc;
		pc = pf;

	}


}


SLD* reverse(SLD* head) {
	//链表逆序
	//注意循环的终点条件,
	//这里采用的是下一个指针递增遍历,注意最后指针为NULL的情况


	SLD *pf, *pc, *pb;
	pf = pc = pb = NULL;

	pc = head;
	pf = head->pnext;
	while (pc != NULL) {

		//pc = pc->pnext;
		pc->pnext = pb;
		pb = pc;
		pc = pf;
		if (pc != NULL) {
			pf = pf->pnext;
		}



	}
	return pb;

}



SLD* backInsert(SLD* head, int num, int newnum) {
	//节点后插入

	//如果链表为null
	if (head == NULL) {
		printf("head为NULL,不存在数值为%d的节点\n", num);
		return NULL;
	}

	SLD* pf = NULL, *pc = NULL;
	pc = head;
	//循环遍历链表找到数值为num的节点
	while (pc != NULL)
	{
		if (pc->num == num) {
			if (head == pc) {
				//刚好是头节点的情况
				SLD* newnode = (SLD*)malloc(sizeof(SLD));

				newnode->num = newnum;
				newnode->pnext = NULL;

				pc->pnext = newnode;
				return head;
			}
			else
			{
				SLD* newnode = (SLD*)malloc(sizeof(SLD));
				newnode->num = newnum;
				//将newnode插入到pc前
				newnode->pnext = pc->pnext;

				pc->pnext = newnode;

				return head;
			}
		}
		else {
			//pf = pc;
			pc = pc->pnext;
		}
	}

	printf("没有找到数值为%d的节点,插入失败\n", num);
	return head;

}


SLD* frontInsert2(SLD* head, int num, int newnum) {
	//节点前插入代码2

	//如果链表为null
	if (head == NULL) {
		printf("head为NULL,不存在数值为%d的节点\n", num);
		return NULL;
	}

	SLD* pf = NULL, *pc = NULL;
	pc = head;
	//循环遍历链表找到数值为num的节点
	while (pc != NULL)
	{
		if (pc->num == num) {
			if (head == pc) {
				//刚好是头节点的情况
				SLD* newnode = (SLD*)malloc(sizeof(SLD));

				newnode->num = newnum;
				newnode->pnext = head;

				head = newnode;
				return head;
			}
			else
			{
				SLD* newnode = (SLD*)malloc(sizeof(SLD));
				newnode->num = newnum;
				//将newnode插入到pc前
				newnode->pnext = pc;

				pf->pnext = newnode;

				return head;
			}
		}
		else {
			pf = pc;
			pc = pc->pnext;
		}
	}
	
	printf("没有找到数值为%d的节点,插入失败\n", num);
	return head;

}

SLD* frontInsert(SLD* head, int num, int newnum) {
	//节点前插入

	//如果链表为null
	if(head==NULL){
		printf("head为NULL,不存在数值为%d的节点\n",num);
		return NULL;
	}
	//刚好是第一个节点前插入的情况
	if (head->num == num) {
		//创建新节点并初始化
		SLD* newnode = (SLD*)malloc(sizeof(SLD));

		newnode->num = newnum;
		newnode->pnext = head;

		head = newnode;
		return head;
	}
	else
	{
		SLD* pf = NULL, *pc = NULL;

		pc = head;
		while (pc->pnext != NULL) {
			pf = pc;
			pc = pc->pnext;//头节点已经考虑过了,直接从第二个节点开始,不断向前移动
			if (pc->num == num) {
				SLD* newnode = (SLD*)malloc(sizeof(SLD));
				newnode->num = newnum;
				//将newnode插入到pc前
				newnode->pnext = pc;

				pf->pnext = newnode;

				return head;

			}
		}

		printf("没有找到值为%d的节点,无法插入新节点.\n", num);
		return head;

	}


}



SLD* lastInsert(SLD* head,int num) {
	//当头部就是尾部的时候,即head=NULL;
	if (head == NULL) {
		//创建新节点,并初始化
		SLD* newnode = (SLD*)malloc(sizeof(SLD));
		if (newnode==NULL) {
			printf("内存分配失败.\n");
			return NULL;
		}
		newnode->num = num;
		newnode->pnext = NULL;

		head = newnode;
		return head;

	}
	else
	{
		//循环到链表尾部
		SLD* p = head;
		while (p->pnext != NULL)
		{
			p = p->pnext;
		}

		//创建新节点
		SLD* newnode = (SLD*)malloc(sizeof(SLD));
		if (newnode == NULL) {
			printf("内存分配失败\n");
			return head;
		}
		newnode->num = num;
		newnode->pnext = NULL;

		//将新节点连接上链表
		p->pnext = newnode;

	}


	return head;
}



SLD* headInsert(SLD* head, int num) {

	//创建一个新节点并分配内存,初始化
	SLD* newnode = NULL;
	newnode = (SLD*)malloc(sizeof(SLD));
	if (newnode == NULL) {
		printf("分配内存失败\n");
		return head;//如果没有成功创建新节点,返回原来的头节点
	}

	//新节点的下一个节点是之前的头节点
	newnode->num = num;
	newnode->pnext = head;
	
	//新节点取代之前头节点
	head = newnode;


	return head;
}



void add(SLD** head, int num) {
	//通过二级指针改变指向链表的指针


	//判断head是否为null
	if (*head == NULL) {

		SLD *newnode = (SLD*)malloc(sizeof(SLD));

		if (newnode == NULL) {
			printf("内存分配失败.\n");
			return;
		}

		newnode->num = num;
		newnode->pnext = NULL;

		//使head指向newnode
		*head = newnode;

	}
	else
	{
		//如果head不为NULL,则尾部插入

		SLD* p = *head;//不要改变头节点
		while (p->pnext != NULL) {
			p = p->pnext;//不但循环向前,直到p->pnext=null,即最后一个节点
		}

		SLD* newnode = (SLD*)malloc(sizeof(SLD));
		if (newnode == NULL) {
			printf("内存分配失败.\n");
			return;
		}

		newnode->num = num;
		newnode->pnext = NULL;

		//将newnode连接上链表
		p->pnext = newnode;
		
				
	}

}



SLD* myAdd(SLD* head, int num) {
	//通过返回值返回head改变外部的head指针指向的链表


	//先判断head是否为空
	if (head == NULL) {

		//开辟内存
		SLD* ps = (SLD*)malloc(sizeof(SLD));
		if (ps == NULL) {
			printf("add失败.\n");
			return NULL;
		}
		ps->num = num;
		ps->pnext = NULL;
		head = ps;

	}
	else
	{
		SLD* p = head;
		while (p->pnext != NULL) {


			p = p->pnext;
		}
		SLD* pnext = (SLD*)malloc(sizeof(SLD));
		if (pnext == NULL) {
			printf("add失败.\n");
			return head;

		}
		pnext->num = num;
		pnext->pnext = NULL;
		//将新节点pnext连接上
		p->pnext = pnext;

	}


	return head;
}



SLD * deleteAll3(SLD* head) {

	SLD* p1 = NULL,*p2=NULL;

	p1= head;
	while (p1->pnext!=NULL)
	{
		/*p2 = p1->pnext;
		if (p2 ->pnext!= NULL) {
			
			p1->pnext = p2->pnext;
			p1 = p1->pnext;
			free(p2);
			p2 = NULL;

		}*/

		p2 = p1->pnext;
		p1->pnext = p2->pnext;
		free(p2);

	}
	free(head);
	head = NULL;


	return head;
}

SLD* deleteAll2(SLD* head) {
	SLD* p = NULL;

	while (head != NULL) {

		p = head;
		head = head->pnext;

		free(p);
		p = NULL;

	}
	free(head);//删除最后一个
	head = NULL;
	return head;

}


void deleteAll1(SLD* head) {
	SLD* p = NULL;

	while (head != NULL) {

		p = head;
		head = head->pnext;

		free(p);
		p = NULL;

	}
	free(head);//删除最后一个
	head = NULL;//需要返回head,否则外部head会指向一个没有权限的内存

}



SLD * deleteNode(SLD * head,int num) {

	SLD *p1, *p2;//p1指向当前链表的前一个链表,p2指向当前链表的下一个
	p1 = p2	= NULL;
	p1 = head;
	while (p1!=NULL)
	{
		if (p1->num == num) {
			//printf("%d\n", num);
			break;//跳出循环
		}
		else
		{
			p2 = p1;
			p1 = p1->pnext;
		}
	}

	if (p1 == head) {
		head = p1->pnext;
		free(p1);
		p1 = NULL;
	}
	else
	{
		p2->pnext = p1->pnext;
		//printf("%d\n", p2->num);
		 free(p1);//为什么free()报错,对非molloc/..分配内存操作报错
		 p1 = NULL;
	}

	return head;

}

void deleteNode3(SLD *head, int num) {

	SLD *p1 = NULL,*p2=head;
	p1 = head;//防止刚好head的时候就找到num
	while (head != NULL) {
	
		if (head->num == num) {
			if (head == p2) {
				head = head->pnext;
				break;
			}
			p1->pnext = head->pnext;


		}

		p1 = head;
		head = head->pnext;//指针不断向前移动,直到head->pnext为NULL赋值给head
	
	}
	
	head = p2;
	while (head != NULL) {

		printf("deleteInner:%d,%p\n", head->num, head->pnext);
		head = head->pnext;
	}
	
}

void deleteNode2(SLD *head, int num) {
	SLD *p = NULL;
	while (head != NULL) {
		if (head ->num == num) {
			p->pnext = head->pnext;
			
			break;
			//free(p2);
			//temppnext = NULL;
		}
		p = head;
		head = head->pnext;//指针不断向前移动,直到head->pnext为NULL赋值给head
	}

	//num=1时以上错误
}

void deleteNode1(SLD * head, int num) {
	while (head != NULL) {
		if (head ->pnext->num == num) {
			head->pnext = head->pnext->pnext;
			
			break;
			//free(p2);
			//temppnext = NULL;
		}
	
		head = head->pnext;//指针不断向前移动,直到head->pnext为NULL赋值给head
	}

	
}

void show(SLD * head) {
	SLD *p = head;
	if (p == NULL) {
		printf("该链表为空\n");
	}
	while (p != NULL) {

		printf("SLD->num:%d,SLD:%p,SLD->pnext:%p\n", p->num, p,p->pnext);
		p = p->pnext;

		if (p == head) {
			printf("该链表为循环链表.\n");
			break;
		}
	}
}
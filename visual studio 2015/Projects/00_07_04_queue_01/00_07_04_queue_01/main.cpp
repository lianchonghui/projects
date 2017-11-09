#include"myqueue.h"

//int main() {
//
//	printf("%d", demo(1));
//
//	return 0;
//}


int main3() {

	//关于野指针:一个指针free()以后

	//野指针主要是因为这些疏忽而出现的：
	//1.指针变量未初始化
	//	任何指针变量刚被创建时不会自动成为NULL指针，它的缺省值是随机的，它会乱指一气。所以，指针变量在创建的同时应当被初始化，要么将指针设置为NULL，要么让它指向合法的内存。
	//2.指针释放后之后未置空
	//	有时指针在free或delete后未赋值 NULL，便会使人以为是合法的。别看free和delete的名字（尤其是delete），它们只是把指针所指的内存给释放掉，但并没有把指针本身干掉。此时指针指向的就是“垃圾”内存。释放后的指针应立即将指针置为NULL，防止产生“野指针”。
	//3.指针操作超越变量作用域
	//	不要返回指向栈内存的指针或引用，因为栈内存在函数结束时会被释放。

	//free()
	//free可以多次对NULL指针使用,如果不是NULL指针只能使用一次
	//delete只能使用一次
	//free()以后内存被回收利用,但指针依然指向该区域,并有权访问,修改数据.
	//delete这是告诉系统，此地址可以再次分配，并没有销毁指针，所以，建议delete后，加一句p = NULL,delete以后是仍然指向该区域,但没权访问该内存区域.
	
	//-------------------------------------
	//free,delete不能对栈内存操作

	int num = 12;
	int *pnum = &num;
	
	//delete()用于释放new出来的内存,跟free()的差不多
	//printf("pnum:%p\n", pnum);
	//delete(pnum);//
	//printf("pnum:%p\n", pnum);


	//free()只能释放手动分配的内存
	//free(pnum);报错


	//-------------------------------------
	//free,delete对堆内存作用

	int *pnum2 = (int *)malloc(sizeof(int));
	//pnum2 = &num;//这样只是改变了pnum2指针的指向,使其指向num,free()是不能释放的
	*pnum2 = 22;
	printf("%p\n", pnum2);
	printf("%d\n", *pnum2);

	//====================================
	//演示free和delete的作用,并比较异同

	//测试free/delete以后,指针的指向:指针仍然指向哪个内存地址
	free(pnum2);
	//delete(pnum2);
	//这里free以后没有对pnum2指针置空,该指针还是指向原来的内存,但这片内存已经回收了(或者马上被其他程序占用),pnum2成为野指针

	printf("%p\n", pnum2);

	//测试free/delete以后指针是否自动置为空:free/delete皆不会对指针置为NULL
	if (pnum2 == NULL) {
		printf("it is NULL");
	}
	printf("%p\n", pnum2);

	//测试free/delete以后,指针是否对该内存还有访问权限:free以后有访问权限,delete以后没有访问权限
	printf("%d\n", *pnum2);//对于free()以后,读取的是垃圾数据;而delete以后,这个指针不再有权限访问这块内存.

	*pnum2 = 13;
	printf("%d\n", *pnum2);

	//以上printf()打印的pnum2的指针都是指向同一个地址


	//=====================================
	
	//对指针free/delete以后置为NULL以后指针的指向
	pnum2 = NULL;
	if (pnum2 == NULL) {
		printf("it is NULL\n");
	}
	printf("%p\n", pnum2);


	system("pause");
	return 0;
}

int main2() {

	MQ mq;
	initQueue(&mq);

	char *str = "abcdefg";
	char *p = str;
	while (*p != '\0') {
		enQueue(&mq, *p);
		showQueue(&mq);
		p++;
	}
	while (isempty(&mq) != 1) {
		printf("\n出队的字符%c", deQueue(&mq));
		showQueue(&mq);
	}


	system("pause");
	return 0;
}

int main1() {


	MQ mq;
	initQueue(&mq);

	datatype d = gehead(&mq);

	printf("%d", d);

	enQueue(&mq,12);

	printf("%d,%d,%d,%d", d,mq.data[mq.rear-1],mq.front,mq.rear);
	system("pause");
	return 0;
}
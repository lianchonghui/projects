
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

	//��������ð������ѡ����������
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

	//����time()��time_t����,srand(),rand()������Ĳ���

	//time_t time(time_t *t);
	//time_t��ʵ��long int,�����洢��ǰʱ�����������.
	//�˺����᷵�شӹ�Ԫ1970��1��1�յ�UTCʱ���0ʱ0��0���������������������������t ���ǿ�ָ��Ļ����˺���Ҳ�Ὣ����ֵ�浽tָ����ָ���ڴ档
	//����ֵ:�ɹ��򷵻�������ʧ���򷵻�((time_t)-1)ֵ������ԭ�����errno�С�
	//���Ը�����Ҫѡ�񡣵�����tΪ��ָ��(NULL)ʱ��ֻ����ֵ��
	//��NULL�Ķ�����(void *) 0�� ����time(0)Ҳ����time(NULL)����һ��д������ʾֻͨ������ֵ��ȡʱ��ֵ��
	
	
	//srand(unsigned int),����һ��unsigned int��Ϊ����,ͨ������time()������ȡ��ǰʱ����Ϊ����,
	//ע��time(time_t *t),���Դ���һ��time_t����ָ��,Ҳ���Դ���NULL����0��ʾ��ָ��,Ҳ��ֵ��ͨ������ֵ��ȥʱ��ֵ,����ͨ��tָ���ȡʱ��ֵ

	//���������:
	//1.��������srand((unsigned int)time(0));
	//2.rand()��ȡ�����

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

	//����ڵ�����ͳ��
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
	printf("�ڵ�����Ϊ:%d\n", sum(head));

	ps5->pnext = ps1;
	show(head);
	printf("�ڵ�����Ϊ:%d\n", sum(head));

	system("pause");
	return 0;
}


int main10() {

	//���������
	SLD* head = NULL;
	add(&head, 11);
	add(&head, 2);
	add(&head, 32);
	add(&head, 12);
	add(&head, 41);

	show(head);

	printf("�ڵ����Ϊ:%d\n", sum(head));
	bsort2(head);

	show(head);


	system("pause");

	return 0;
}


int main9() {
	
	//��������
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

	//�ڵ�ǰ����ͽڵ�����
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

	//����ͷ�������β������
	SLD* head = NULL;
	//head=headInsert(head, 11);
	//show(head);
	//head = headInsert(head, 22);
	//head = headInsert(head, 33);
	//head = headInsert(head, 44);
	//show(head);

	//β������

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

	//����ڵ������

	SLD* head = NULL;
	show(head);

	//ͨ����������ֵ��ֵ��head�ı�headָ�������
	//head = myAdd(head, 11);
	//show(head);
	//head = myAdd(head, 22);
	//head = myAdd(head, 33);
	//show(head);

	//ͨ������ָ��ı�head
	add(&head, 11);
	show(head);
	add(&head, 22);
	add(&head, 33);
	show(head);

	system("pause");
	return 0;
}


int main5() {

	//ɾ���������нڵ�
	//���ַ�ʽ:
	//��ʽ1:������������ָ��p1,p2,p1=head;p2=p1-pnext;p1->pnext=p2->pnext;free(p2),���ϵ���p1->pnextֱ��ΪNULLʱֹͣ,����ͷ�head
	//��ʽ2:����һ������ָ��p;p=head->pnext;head=head->pnext;free(p),��ͷ��������ǰ,��֮ǰͷ���ͷ�,����ͷ�head,�����ͷ����һ���ڵ�

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

	//����ı���show()������ڵ��ɾ��
	//����������:free()������ʹ������:ֻ�����붯̬ģʽ����;����ı�ʾ����:ͨ��һ��ָ��headָ��ͷ����ַ

	//����һ������,Ҫ�ȴ���һ��head������ָ��ָ����������ͷ��,���headָ��������൱��������׵�ַ,��������һ��,����������׵�ַ���ɱ�,��һ��������׵�ַ(ͷ��)���Ըı�
	//�������׵�ַ�ĸı�;���headָ�����ֵ�øı�.
	//��Ϊ������׵�ַ�ǿɱ��,���Ե�ͷ���ı�(ͷ��ɾ��,ͷ�������)�Ժ����±��������ʱ���Ҫ���µ�ͷ����ʼ����,headָ����Ǵ洢�׵�ַ������
	//����,���ú����ı������ʱ��,��Ϊ�����ָ���и�������,��Ȼͨ��ָ����Ըı�����ʵֵ.���ǵ��ı�ͷ����ʱ��,���Ǵ���Ĳ�������ͷ�����׵�ַ
	//���Ǵ���һ��ָ�������headָ��,��Ϊ�����ָ���и�������,��head��һ������,�����ַ�ʽ�ı�headָ��:����ָ��ͺ�������ֵ�������¸�ֵ
	//��Ȼ����void����ֵ,ͬ���ı�������Ч,ǰ�����ڲ��ı�ͷ���������,�ҿ��Դ��������ͷ����ַ,�����ô���headָ��.ǰ�����ڲ��ı�ͷ���������

	//����ʹ��free��������:free����ֻ�������ͷ�malloc/calloc/realloc�ڴ�
	//��������Է�malloc�ڴ�����ͷžͻᱨ��,������һ��ʹ������̬ģʽ
	//��malloc()�������ʹ�ã��ͷ�malloc��������Ķ�̬�ڴ档��������free(p)�����䣬���p ��NULL ָ�룬��ôfree ��p ���۲������ٴζ���������⡣���p ����NULL ָ�룬��ôfree ��p�����������ξͻᵼ�³������д��󡣣�
	
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

	//���ڱ�������,��ȡ��ʱ�����һ���α겻����ǰ�ƶ�,��������,����Ķ�ȡ����ͨ���±��ָ���������,�����������ṹ(�洢����һ��Ԫ�صĵ�ַ)����ͨ��ָ�����

	SL * psl = &l1;
	while (psl!= NULL) {//ָ�벻����ǰ�ƶ�,
		printf("%d,%p\n", psl->num, psl->pnext);
		psl = psl->pnext;//ָ�벻����ǰ�ƶ�,ֱ�����һ������Ԫ�ص�pnext��ֵΪNULL
	}
	

	
	system("pause");
	return 0;
}

int main2() {

	//����̬ģʽ
	SL *pl1, *pl2;
	pl1 = (SL*)malloc(sizeof(SL));
	pl2 = (SL*)malloc(sizeof(SL));


	//��ʽ1
	//pl1->num = 1;
	//pl1->pnext = pl2;
	//pl2->num = 2;
	//pl2->pnext = NULL;

	//��ʽ2
	(*pl1).num = 1;
	(*pl1).pnext = pl2;
	(*pl2).num = 2;
	(*pl2).pnext = NULL;


	printf("%d,%p\n", pl1->num, pl1->pnext);


	system("pause");
	return 0;
}



int main1() {

	//����̬ģʽ

	SL l1, l2;
	l1.num = 1;
	l1.pnext = &l2;
	l2.num = 2;
	l2.pnext = NULL;

	printf("%d,%p\n", l1.num, l1.pnext);


	system("pause");
	return 0;
}
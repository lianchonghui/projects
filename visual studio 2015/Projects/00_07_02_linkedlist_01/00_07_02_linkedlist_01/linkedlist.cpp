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
	//����ð������

	//c�����У���������������sizeof����������ĳ��ȣ�������Ԫ�ظ�����
	//	�磺
	//{
	//	int data[4];
	//int length;
	//length = sizeof(data) / sizeof(data[0]);  //����ռ�ڴ��ܿռ䣬���Ե���Ԫ��ռ�ڴ�ռ��С
	//printf("length of data[4]=%d", length); //���length of data[4]=4
	//}
	//	����ͨ�������������������Ӻ����У��Ի�����鳤���ǲ����еġ��磺
	//	int getLength(int[] a) {
	//	int length;
	//	length = sizeof(a) / sizeof(a[0]); //�����Ǵ���ģ��õ��Ľ����Զ��1
	//	return length;
	//}
	//��Ϊ��a�Ǻ������������˱������У�aֻ��һ��ָ�루��ַ��ϵͳ�ڱ���������ʱ���ǲ�֪��a����ʾ�ĵ�ַ�ж������ݴ洢�ռ䣬����ֻ�Ǹ��ߺ�����һ�����ݴ洢�ռ��׵�ַ�������ԣ�sizoef(a)�Ľ����ָ�����aռ�ڴ�Ĵ�С��һ����32λ������4���ֽڡ�a[0]��int���ͣ�sizeof(a[0])Ҳ��4���ֽڣ����ԣ������Զ��1��
	//��ˣ�������鳤�ȣ�ֻ�������鶨�����ڵĴ������У��������Ϸ������ſ��ԴﵽЧ����

	
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
	//����ð������

	//c�����У���������������sizeof����������ĳ��ȣ�������Ԫ�ظ�����
	//	�磺
	//{
	//	int data[4];
	//int length;
	//length = sizeof(data) / sizeof(data[0]);  //����ռ�ڴ��ܿռ䣬���Ե���Ԫ��ռ�ڴ�ռ��С
	//printf("length of data[4]=%d", length); //���length of data[4]=4
	//}
	//	����ͨ�������������������Ӻ����У��Ի�����鳤���ǲ����еġ��磺
	//	int getLength(int[] a) {
	//	int length;
	//	length = sizeof(a) / sizeof(a[0]); //�����Ǵ���ģ��õ��Ľ����Զ��1
	//	return length;
	//}
	//��Ϊ��a�Ǻ������������˱������У�aֻ��һ��ָ�루��ַ��ϵͳ�ڱ���������ʱ���ǲ�֪��a����ʾ�ĵ�ַ�ж������ݴ洢�ռ䣬����ֻ�Ǹ��ߺ�����һ�����ݴ洢�ռ��׵�ַ�������ԣ�sizoef(a)�Ľ����ָ�����aռ�ڴ�Ĵ�С��һ����32λ������4���ֽڡ�a[0]��int���ͣ�sizeof(a[0])Ҳ��4���ֽڣ����ԣ������Զ��1��
	//��ˣ�������鳤�ȣ�ֻ�������鶨�����ڵĴ������У��������Ϸ������ſ��ԴﵽЧ����

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
	//���ýڵ�������ѭ������,����ð���������������


	//��ȡ�ڵ���
	int total = sum(head);
	SLD tempsld;

	for (int i = 0;i < total;i++) {
		/*for (SLD* pi = head, int j = 0;j < total - 1 - i;j++, pi = pi->pnext) {//forѭ���ڲ������ʼ���������
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
	//ͳ�ƽڵ���
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
	//ð��������������,��������ľ�����,����ÿ��ð������Ҫ��ͷ�Ƚϵ�β��;


	//SLD* lastNode = NULL;
	SLD tempsld;
	if (head == NULL) {
		return;
	}
	for (SLD* po = head;po->pnext != NULL;po = po->pnext) {//ð���ֻصĴ���,���ǽ����N-1��

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
	
	//һ�����������,���õ�����ֵ����,�����Ǹı�pnext�ĵ�ַ,�������ʺ���ѡ������
	//int tempnum;
	SLD tempsld;//һ��ʹ�ýṹ��,���ڶԽṹ���ڶ��Ԫ�ص�ʹ��

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

	//���ֻ��һ���ڵ��������Ϊ��
	if (head == NULL || head->pnext == NULL) {
		return head;
	}

	//�ӵڶ����ڵ㿪ʼ
	pb = head;
	pc = head->pnext;

	while (pc != NULL) {
		//�������һ����ʱָ��洢��ǰָ��ָ�����һ���ڵ�,��ǰָ���������

		//������ָ��ָ��ǰ�ڵ����һ���ڵ�
		pf = pc->pnext;
		
		//��ǰ�ڵ��pnextָ��ǰһ���ڵ�
		pc->pnext = pb;

		//p1,p2��ǰ����
		pb = pc;
		pc = pf;

	}


}


SLD* reverse(SLD* head) {
	//��������
	//ע��ѭ�����յ�����,
	//������õ�����һ��ָ���������,ע�����ָ��ΪNULL�����


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
	//�ڵ�����

	//�������Ϊnull
	if (head == NULL) {
		printf("headΪNULL,��������ֵΪ%d�Ľڵ�\n", num);
		return NULL;
	}

	SLD* pf = NULL, *pc = NULL;
	pc = head;
	//ѭ�����������ҵ���ֵΪnum�Ľڵ�
	while (pc != NULL)
	{
		if (pc->num == num) {
			if (head == pc) {
				//�պ���ͷ�ڵ�����
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
				//��newnode���뵽pcǰ
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

	printf("û���ҵ���ֵΪ%d�Ľڵ�,����ʧ��\n", num);
	return head;

}


SLD* frontInsert2(SLD* head, int num, int newnum) {
	//�ڵ�ǰ�������2

	//�������Ϊnull
	if (head == NULL) {
		printf("headΪNULL,��������ֵΪ%d�Ľڵ�\n", num);
		return NULL;
	}

	SLD* pf = NULL, *pc = NULL;
	pc = head;
	//ѭ�����������ҵ���ֵΪnum�Ľڵ�
	while (pc != NULL)
	{
		if (pc->num == num) {
			if (head == pc) {
				//�պ���ͷ�ڵ�����
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
				//��newnode���뵽pcǰ
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
	
	printf("û���ҵ���ֵΪ%d�Ľڵ�,����ʧ��\n", num);
	return head;

}

SLD* frontInsert(SLD* head, int num, int newnum) {
	//�ڵ�ǰ����

	//�������Ϊnull
	if(head==NULL){
		printf("headΪNULL,��������ֵΪ%d�Ľڵ�\n",num);
		return NULL;
	}
	//�պ��ǵ�һ���ڵ�ǰ��������
	if (head->num == num) {
		//�����½ڵ㲢��ʼ��
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
			pc = pc->pnext;//ͷ�ڵ��Ѿ����ǹ���,ֱ�Ӵӵڶ����ڵ㿪ʼ,������ǰ�ƶ�
			if (pc->num == num) {
				SLD* newnode = (SLD*)malloc(sizeof(SLD));
				newnode->num = newnum;
				//��newnode���뵽pcǰ
				newnode->pnext = pc;

				pf->pnext = newnode;

				return head;

			}
		}

		printf("û���ҵ�ֵΪ%d�Ľڵ�,�޷������½ڵ�.\n", num);
		return head;

	}


}



SLD* lastInsert(SLD* head,int num) {
	//��ͷ������β����ʱ��,��head=NULL;
	if (head == NULL) {
		//�����½ڵ�,����ʼ��
		SLD* newnode = (SLD*)malloc(sizeof(SLD));
		if (newnode==NULL) {
			printf("�ڴ����ʧ��.\n");
			return NULL;
		}
		newnode->num = num;
		newnode->pnext = NULL;

		head = newnode;
		return head;

	}
	else
	{
		//ѭ��������β��
		SLD* p = head;
		while (p->pnext != NULL)
		{
			p = p->pnext;
		}

		//�����½ڵ�
		SLD* newnode = (SLD*)malloc(sizeof(SLD));
		if (newnode == NULL) {
			printf("�ڴ����ʧ��\n");
			return head;
		}
		newnode->num = num;
		newnode->pnext = NULL;

		//���½ڵ�����������
		p->pnext = newnode;

	}


	return head;
}



SLD* headInsert(SLD* head, int num) {

	//����һ���½ڵ㲢�����ڴ�,��ʼ��
	SLD* newnode = NULL;
	newnode = (SLD*)malloc(sizeof(SLD));
	if (newnode == NULL) {
		printf("�����ڴ�ʧ��\n");
		return head;//���û�гɹ������½ڵ�,����ԭ����ͷ�ڵ�
	}

	//�½ڵ����һ���ڵ���֮ǰ��ͷ�ڵ�
	newnode->num = num;
	newnode->pnext = head;
	
	//�½ڵ�ȡ��֮ǰͷ�ڵ�
	head = newnode;


	return head;
}



void add(SLD** head, int num) {
	//ͨ������ָ��ı�ָ�������ָ��


	//�ж�head�Ƿ�Ϊnull
	if (*head == NULL) {

		SLD *newnode = (SLD*)malloc(sizeof(SLD));

		if (newnode == NULL) {
			printf("�ڴ����ʧ��.\n");
			return;
		}

		newnode->num = num;
		newnode->pnext = NULL;

		//ʹheadָ��newnode
		*head = newnode;

	}
	else
	{
		//���head��ΪNULL,��β������

		SLD* p = *head;//��Ҫ�ı�ͷ�ڵ�
		while (p->pnext != NULL) {
			p = p->pnext;//����ѭ����ǰ,ֱ��p->pnext=null,�����һ���ڵ�
		}

		SLD* newnode = (SLD*)malloc(sizeof(SLD));
		if (newnode == NULL) {
			printf("�ڴ����ʧ��.\n");
			return;
		}

		newnode->num = num;
		newnode->pnext = NULL;

		//��newnode����������
		p->pnext = newnode;
		
				
	}

}



SLD* myAdd(SLD* head, int num) {
	//ͨ������ֵ����head�ı��ⲿ��headָ��ָ�������


	//���ж�head�Ƿ�Ϊ��
	if (head == NULL) {

		//�����ڴ�
		SLD* ps = (SLD*)malloc(sizeof(SLD));
		if (ps == NULL) {
			printf("addʧ��.\n");
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
			printf("addʧ��.\n");
			return head;

		}
		pnext->num = num;
		pnext->pnext = NULL;
		//���½ڵ�pnext������
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
	free(head);//ɾ�����һ��
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
	free(head);//ɾ�����һ��
	head = NULL;//��Ҫ����head,�����ⲿhead��ָ��һ��û��Ȩ�޵��ڴ�

}



SLD * deleteNode(SLD * head,int num) {

	SLD *p1, *p2;//p1ָ��ǰ�����ǰһ������,p2ָ��ǰ�������һ��
	p1 = p2	= NULL;
	p1 = head;
	while (p1!=NULL)
	{
		if (p1->num == num) {
			//printf("%d\n", num);
			break;//����ѭ��
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
		 free(p1);//Ϊʲôfree()����,�Է�molloc/..�����ڴ��������
		 p1 = NULL;
	}

	return head;

}

void deleteNode3(SLD *head, int num) {

	SLD *p1 = NULL,*p2=head;
	p1 = head;//��ֹ�պ�head��ʱ����ҵ�num
	while (head != NULL) {
	
		if (head->num == num) {
			if (head == p2) {
				head = head->pnext;
				break;
			}
			p1->pnext = head->pnext;


		}

		p1 = head;
		head = head->pnext;//ָ�벻����ǰ�ƶ�,ֱ��head->pnextΪNULL��ֵ��head
	
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
		head = head->pnext;//ָ�벻����ǰ�ƶ�,ֱ��head->pnextΪNULL��ֵ��head
	}

	//num=1ʱ���ϴ���
}

void deleteNode1(SLD * head, int num) {
	while (head != NULL) {
		if (head ->pnext->num == num) {
			head->pnext = head->pnext->pnext;
			
			break;
			//free(p2);
			//temppnext = NULL;
		}
	
		head = head->pnext;//ָ�벻����ǰ�ƶ�,ֱ��head->pnextΪNULL��ֵ��head
	}

	
}

void show(SLD * head) {
	SLD *p = head;
	if (p == NULL) {
		printf("������Ϊ��\n");
	}
	while (p != NULL) {

		printf("SLD->num:%d,SLD:%p,SLD->pnext:%p\n", p->num, p,p->pnext);
		p = p->pnext;

		if (p == head) {
			printf("������Ϊѭ������.\n");
			break;
		}
	}
}
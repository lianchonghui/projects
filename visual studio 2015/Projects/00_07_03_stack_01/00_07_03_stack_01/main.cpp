#include"mystack.h"

int main() {

	//��ʽջ�Ļ�����ʾ

	LS *phead=NULL;
	phead = init(phead);//��ʼ����ʽջ

	phead = pushls(phead, 1);
	phead = pushls(phead, 2);
	phead = pushls(phead, 3);
	phead = pushls(phead, 4);
	phead = pushls(phead, 5);

	printfall(phead);

	//printf("��ջ\n");
	//LS *pout = (LS*)malloc(sizeof(LS));
	//while (phead)
	//{
	//	
	//	phead = popls(phead, pout);
	//	printf("%d,%p,%p\n", pout->data, pout, pout->pnext);
	//}

	phead=freeall(phead);
	printf("�ͷ��Ժ�\n");
	printfall(phead);

	system("pause");
	return 0;
}


int main2() {

	//����ջ���Ƚ����������,���һ����������
	int num = 100;

	while (num)//����������Ƶķ���,ÿ�γ���2,ֱ����ȫ����,���պó���2�õ�0(����%�õ�0),ѭ����ֹ
	{
		push(num % 2);//ѹջ
		num /= 2;
	}

	while (!isempty())
	{
		printf("%d", pop());
	}
	system("pause");
	return 0;
}



int main1() {
	//ջ�Ļ�����ʾ

	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0;i < 10;i++) {
		push(a[i]);//ѹ������
	}

	while (isempty() != 1) {//1Ϊ��,0Ϊ��Ԫ��
		printf("%d\n", pop());
	}

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdarg.h>
#include<string>
#include<Windows.h>

void args(int num, ...) {//num��ʾ����Ĳ�������
	//�ɱ��������

	//����stdarg.hͷ�ļ�
	va_list argp;//����ָ��,���ڴ洢��ַ,���ﲻ�ܼ�*��
	va_start(argp, num);//��ʾ��num������

	for (int i=0;i<num;i++) {
		char str[50];//���ڱ�����ַ�������
		//��char*�ķ�ʽ��ȡargp�洢��str��
		strcpy(str, va_arg(argp, char*));//string.h
		printf("%s\n", str);
	}
	va_end(argp);//��������

}

void ten2two(int num) {
	//ʮ����ת�������ƺ���

	if (num == 0) {
		return;
	}
	ten2two(num / 2);
	printf("%d", num % 2);

}

double tencent(int num) {
	//쳲�����������n�Ĵ�С

	if (num == 1) {
		return 1.0;
	}
	else if (num == 2) {
		return 2.0;
	}
	else
	{
		return tencent(num - 1) + tencent(num - 2);
	}

}

void arrp(int* p,int num) {
	//ָ����Ϊ����������Ԫ�ؽ�������
	//������ѡ������
	
	for (int i = 0;i < num-1;i++) {
		for (int j = i + 1;j < num;j++) {
			if (p[i] > p[j]) {
				int temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}

	//for (int i = 0;i < num;i++) {
	//	for (int j = 0;j < num - i - 1;j++) {
	//		if (p[j] > p[j + 1]) {
	//			int temp = p[j];
	//			p[j] = p[j + 1];
	//			p[j + 1] = temp;
	//		}

	//	}

	//}

}





void main12() {
	//��ָ����������������,������û�и������Ƶ�
	int arr[6] = { 2,5,1,7,3,0 };
	int* p = arr;
	for (int i = 0;i < 6;i++) {
		printf("%4d", p[i]);
	}
	printf("\n");

	arrp(p, 6);
	
	for (int i = 0;i < 6;i++) {
		printf("%4d", arr[i]);
	}
	system("pause");
}



void main11() {
	//���鵹��

	//����һ����̬����
	int num = 0;
	scanf_s("%d", &num);

	//�������������
	time_t ts;//time_t��ʵ��long int����,�����洢��1970�굽���ڵ�ʱ�����������
	srand((unsigned int)time(&ts));

	//����һ��ָ��,ָ��һ�������С�Ŀ��ڴ�
	int* p = (int*)malloc(num*sizeof(int));

	for (int i = 0;i < num;i++) {

		p[i] = rand() % 100;
		printf("%4d", p[i]);
	}

	printf("\n");

	//��β�滻//ע��i<num/2
	for (int i = 0;i < num/2;i++) {
		int temp = p[num-i-1];
		p[num - i - 1] = p[i];
		p[i] = temp;
	}

	for (int i = 0;i < num;i++) {
		printf("%4d", p[i]);
	}

	system("pause");




}



void main10() {
	//��Ѷ������:ѭ�����
	//��50��̨��,һ������1̨�׻���̨��,���ж����ֿ��ܵ��Ϸ�?
	while (1) {

	int num;
		scanf_s("%d", &num);

		double d[3] = { 1,2,3 };
		//double temp0;
		//double temp1;
		if (num == 1) {
			printf("%f\n", d[0]);
		}
		else if (num == 2) {
			printf("%f\n", d[1]);
		}
		else {
			for (int i = 2;i < num;i++) {
				//temp0 = d[1];
				//temp1 = d[2];
				d[2] = d[1] + d[0];
				d[0] = d[1];
				d[1] = d[2];
			}
			printf("%llf\n", d[2]);
		}

	}

}


void main9() {
	//��Ѷ������:�ݹ���
	//��50��̨��,һ������1̨�׻���̨��,���ж����ֿ��ܵ��Ϸ�?
	//����:Ҫ�뵽��n̨�ױض��Ǵ�n-1��n-2��̨����ȥ��,���Ե���n̨�׵Ŀ�������f(n-1)+f(n-2);
	//쳲���������
	while (1) {

		int num;
		scanf_s("%d", &num);
		double f = tencent(num);
		printf("%llf\n", f);
	
	}
	system("pause");


}

void main8() {
	//ʮ����ת��Ϊ������
	while (1) {


		printf("\n������һ��������:");
		int num;
		scanf_s("%d", &num);
		if (num == 0) {
			printf("0");
		}
		else
		{
			ten2two(num);
		}

	}
	system("pause");

}



void main7() {
		//��֤�Ƿ�Ϊ����(����)
	while (1) {

		printf("������һ������2������:");
	
		int flag = 1;
		int num;
		scanf_s("%d", &num);

		if (num == 2 || num==3) {
			printf("%d��һ������\n", num);
		}
		else {

			for (int i = 2;i < num;i++) {
				if (num%i==0) {
					flag = 0;
					printf("���Ա�%d����\n", i);
					/*printf("%d����һ������\n", num);
					break;*/
				}
			}
		}

		if (flag) {
			printf("%d��һ������\n", num);
		}
		else
		{
			printf("%d����һ������\n", num);
		}

	}
	system("pause");

}





void main6() {
	//������λ��
	printf("������һ������:");
	int num;
	int result = 0;
	scanf_s("%d", &num);
	
	if (num == 0) {
		printf("\n���������һλ��");
	}
	else {


		while (num) {

			num = num / 10;
			result++;
		}
		printf("\n���������%dλ��", result);
	
	}

	getchar();
	getchar();

}




void main5() {
	//��֤һ�����Ƿ�Ϊˮ�ɻ���abc=a^3+b^3+c^3
	int num = 0;
	while (1) {

		printf("������һ����λ��:");

		scanf_s("%d", &num);

		int a = num / 100 % 10;
		int b = num / 10 % 10;
		int c = num % 10;

		if (a*a*a + b*b*b+ c*c*c== num) {
			printf("\n%d��һ��ˮ�ɻ���.",num);
		}
		else
		{
			printf("\n%d����һ��ˮ�ɻ���.", num);
		}


	}

}

void main4() {
	//�����ɱ����

	args(4, "notepad", "pause", "ipconfig", "mspaint");

	
	//��ʱ�˳�
	Sleep(10000);
	exit(0);
	


}





void main3() {
	//�����ӡ쳲���������

	int num = 0;
	scanf_s("%d", &num);

	//ʹ��ָ�봴��һ����̬����
	int* p = (int*)malloc(num*sizeof(int));

	p[0] = 0;
	p[1] = 1;
	printf("p[0]=%d\np[1]=%d\n", p[0], p[1]);
	for (int i = 2;i < num;i++) {
		p[i] = p[i - 1] + p[i - 2];
		printf("p[%d]=%d\n", i,p[i]);
	}

	system("pause");



}







void main2() {
	//���ֲ��ҷ�

	//����һ�����������
	time_t	ts;
	srand((unsigned int)time(&ts));
	
	//��������Ԫ�ظ���
	int num=0;
	scanf_s("%d", &num);

	//����һ����̬����
	int* arrp =(int*) malloc(num*sizeof(int));//���ָ��Ĳ�����������������ĳ���

	//�����鸳ֵ
	for (int i = 0;i < num;i++) {

		arrp[i] = rand() % 100;
		printf("%4d", arrp[i]);

	}

	//����������//������ð������
	for (int i = 0;i < num;i++) {
		for (int j = 0;j < num - i - 1;j++) {
			if (arrp[j] > arrp[j + 1]) {
				int temp = arrp[j];
				arrp[j] = arrp[j + 1];
				arrp[j + 1] = temp;
			}

		}
		
	}

	printf("\n");
	//��������
	for (int i = 0;i < num;i++) {
		printf("%4d", arrp[i]);
	}

	printf("\n������Ҫ���ҵ���:");
	int checkNum;
	scanf_s("%d", &checkNum);
	printf("\n");


	//���ֲ��ҷ�
	int min = 0;
	int max = num - 1;
	int mid = (min + max) / 2;
	int inum = 1;
	while (1) {
		printf("��%d�β�ѯ\n", inum++);

		if (checkNum == arrp[mid]) {
			printf("�ҵ���,�����±���%d", mid);
			break;
		}
		else if(checkNum<arrp[mid])
		{
			max = mid - 1;
			mid = (min + max) / 2;
			continue;
		}
		else if(checkNum>arrp[mid])
		{
			min = mid + 1;
			mid = (max + min) / 2;
			continue;
		}


	}



	system("pause");



}



void main1() {
	//��ά�����ת��

	//����һ���й̶��Ķ�̬��ά����

	time_t ts;
	unsigned int timeNum = time(&ts);
	srand(timeNum);

	int arr[3][4] = { 0 };
	//int x;
	//scanf_s("%d", &x);

	for (int i = 0;i < 3*4;i++) {
		int num = rand()%100;
		arr[i / 4][i % 4] = num;
	/*	carr[i / 3][i % 3] = num;*/
		printf("%4d", num);

		if (i % 4 == 3) {
			printf("\n");
		}
	}

	printf("----------------\n");

	//for (int i = 0;i < 4 * 3;i++) {
	//	carr[i / 3][i % 3] = arr[i % 4][i / 4];
	//	printf("%4d", carr[i / 3][i % 3]);

	//	if (i % 3 == 2) {
	//		printf("\n");
	//	}

	//}
	int carr[4][3] = { 0 };

	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 3;j++) {
			carr[i][j] = arr[j][i];
			printf("%4d", carr[i][j]);
		}
		printf("\n");

	}


	getchar();
	getchar();

}
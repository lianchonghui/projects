#include<stdio.h>
#include<stdlib.h>


void main() {

	float fl;
	scanf_s("%f", &fl);
	unsigned char *p = (unsigned char *)&fl;//�����ڴ�

	//windows��,��λ��ǰ,��λ�ں�
	for (int i = 3;i >= 0;i--){
		unsigned char chs = p[i];

		for (int j = 7;j >= 0;j--) {

			printf("%c", chs&(1 << j) ? '1' : '0');

		}
	
	}

	system("pause");


}

void main6() {
	//���üӼ��˳�ʵ���������:ʹ�����ƺ����������


}



void main5() {
	//�������м����ʵ����������


	int a = 10;
	int b = 21;

	printf("a=%d,b=%d\n", a, b);

	//����һ:
	a = a + b;
	b = a - b;
	a = a - b;

	printf("a=%d,b=%d\n", a, b);

	//������:
	a = a * b;
	b = a / b;
	a = a / b;
	printf("a=%d,b=%d\n", a, b);

	//������:
	a = a^b;
	b = b^a;
	a = a^b;
	printf("a=%d,b=%d\n", a, b);

	getchar();

}



void main4() {
	//����1:λ�ֶδ�ӡ����//ʧ��!!!!!!!!

	typedef struct biteNum {
		unsigned char c1 : 1;
		unsigned char c2 : 1;
		unsigned char c3 : 1;
		unsigned char c4 : 1;
		unsigned char c5 : 1;
		unsigned char c6 : 1;
		unsigned char c7 : 1;
		unsigned char c8 : 1;

	}BNUM;

	printf("%d\n", sizeof(BNUM));//1Byte


								 //����ָ��bnp
	BNUM *bnp;

	//�����ڴ�
	int * nump = (int *)malloc(sizeof(BNUM) * 4);

	//ָ��bnpָ�����õ��ڴ�,��nump�����ڴ�
	bnp = (BNUM *)nump;

	//�Է���õ��ڴ���ݵ�ַ��ʼ��
	scanf_s("%d", nump);

	//Windows��,��λ�ں�,��λ��ǰ,���ڴ��д洢
	printf("����:"); 
		for (int i = 3;i >= 0;i--) {
			printf("%d%d%d%d%d%d%d%d ", bnp[i].c8, bnp[i].c7, bnp[i].c6, bnp[i].c5, bnp[i].c4, bnp[i].c3, bnp[i].c2, bnp[i].c1);

		}

	printf("\n");


	*nump--;

	printf("����:");
	for (int i = 3;i >= 0;i--) {
		printf("%d%d%d%d%d%d%d%d ", bnp[i].c8, bnp[i].c7, bnp[i].c6, bnp[i].c5, bnp[i].c4, bnp[i].c3, bnp[i].c2, bnp[i].c1);

	}
	for (int i = 3;i >= 0;i--) {
		//printf("%d%d%d%d%d%d%d%d", bnp[i].c8, bnp[i].c7, bnp[i].c6, bnp[i].c5, bnp[i].c4, bnp[i].c3, bnp[i].c2, bnp[i].c1);
		bnp[i].c8 = ~bnp[i].c8;
		bnp[i].c7 = ~bnp[i].c7;
		bnp[i].c6 = ~bnp[i].c6;
		bnp[i].c5 = ~bnp[i].c5;
		bnp[i].c4 = ~bnp[i].c4;
		bnp[i].c3 = ~bnp[i].c3;
		bnp[i].c2 = ~bnp[i].c2;
		bnp[i].c1 = ~bnp[i].c1;
	}

	getchar();
	getchar();
}


void main3() {
	//����2:λ�����ӡ����

	//a:  1000 0000 0000 0000 0000 0000 0000 0000
	//num:0000 0000 0000 0000 0000 0000 0000 1000

	int a = 1<<31;

	int num;
	scanf_s("%d", &num);

	for (int i = 1;i <= 32;i++) {
		
		printf("%c", num&a?'1':'0');//�����ַ���Լ�ڴ�
		
		//a >>= 1;//Ϊʲô����a��λ�ƻᷢ������??????
		num <<= 1;

		if (i % 4 == 0) {
			printf(" ");
		}
	}

	system("pause");



}


void main2() {
	//����1:λ�ֶδ�ӡ����

	typedef struct biteNum {
		unsigned char c1: 1;
		unsigned char c2: 1;
		unsigned char c3: 1;
		unsigned char c4: 1;
		unsigned char c5: 1;
		unsigned char c6: 1;
		unsigned char c7: 1;
		unsigned char c8: 1;

	}BNUM;

	printf("%d\n", sizeof(BNUM));//1Byte


	//����ָ��bnp
	BNUM *bnp;

	//�����ڴ�
	int * nump = (int *)malloc(sizeof(BNUM) * 4);

	//ָ��bnpָ�����õ��ڴ�,��nump�����ڴ�
	bnp = (BNUM *)nump;

	//�Է���õ��ڴ���ݵ�ַ��ʼ��
	scanf_s("%d", nump);

	//Windows��,��λ�ں�,��λ��ǰ,���ڴ��д洢
	for (int i = 3;i >= 0;i--) {
		printf("%d%d%d%d%d%d%d%d", bnp[i].c8, bnp[i].c7, bnp[i].c6, bnp[i].c5, bnp[i].c4, bnp[i].c3, bnp[i].c2, bnp[i].c1);

	}

	getchar();
	getchar();
}



void main1() {
	//����1:λ�����ӡ����  //ʧ��,c��������������С��λΪ1�ֽ�

	typedef struct numc {
		char c1 : 1;
	}NUMC;




	NUMC *numcP;
	printf("%d\n", sizeof(NUMC));
	numcP = (NUMC *)malloc(sizeof(NUMC) * 8);

	char * charP;

	charP = (char *)numcP;

	*charP = 8;

	printf("%d\n", *charP);

	for (int i = 7;i >= 0;i--) {
		printf("%d", numcP[i]);
	}
	
	getchar();
}

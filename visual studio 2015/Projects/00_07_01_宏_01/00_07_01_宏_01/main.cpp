#include<stdio.h>
#include<stdlib.h>



void printf1() {
	printf("1111");
}
void printf2() {
	printf("2222");
}


void a1(char name[], char type[]) {
	printf("%s,%s", name, type);
}

//����һ������������ģ�� type name(##type a){},
//ע��,�����##�𵽵������ӵ�����,���޶���,���ǲ���ʹ��#
#define A2(name,type) type name(##type a){printf("helloworld");return a;}
A2(a2,int)

int main4() {

//ͨ���������ͷ��ز������ú���,����#���ַ�����������,��a1��void�����ַ�����������a1
#define A1(name,type)  name(#name,#type)

	A1(a1, void);
	
	printf("\n");
	a2(11);
	printf("\n");
	printf("%d", a2(11));
	getchar();
	return 0;
}

int main() {
	//##������:ƴ��������ַ���������ַ���
	//������滻���Ǻ�����x����x


//P(1)�ȼ���P1
#define P(x) Q##x

	int P(1) = 11;
	int P(2) = 22;
	printf("%d,%d\n", P(1), P(2));

	Q1 = 111;
	Q2 = 222;
	printf("%d,%d\n", Q1, Q2);

//PP(1)�ȼ���printf1,PP(1)()�ȼ���printf1();
#define PP(x) printf##x

	PP(1)();
	PP(2)();

	printf("\n");

	printf1();
	printf2();

	
	getchar();
	return 0;
}

int main2() {
	//define ���滻ע��,ֻ���滻,�����Ƚ����κ�����
	//

//#define LF(x) x*x*x//�߼�������,���»����:3+1*3+1*3+1���Ϊ10,define����ֻ���滻����
//�����Ǻ������滻
#define LF(x) (x)*(x)*(x)

	printf("%d", LF(3+1));

	getchar();


	return 0;
}




int main1() {
	//����#��Ӧ��


	//printf("%s", A1(a1));

	//#���ַ�����������
#define printfn(x) printf(#x);
	printfn(hello world);

#define printfnn(x) printf("%s=%d",#x,x)

	int a1 = 10, a2 = 20;

	printfnn(a1);



	getchar();

	return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct demo1 {
	unsigned int day : 5;
	unsigned int month : 5;
	unsigned int year : 14;
	//unsigned long long : 14;
}b1;


struct demo2 {
	unsigned char c1 : 1;
	unsigned char c2 : 2;

};

struct demo3 {
	unsigned char c1 : 1;
	unsigned char c2 : 2;
	unsigned int num : 10;

};

void main3() {
	printf("%d", sizeof(struct demo3));
	//��Ȼdemo2��ӡ����1,���Ǽ���int�Ժ�,���ֽڶ���,��ӡ8;
	//c1,c2����ռ4���ֽ�,numռ4���ֽ�
	getchar();
}


void main2() {
	printf("%d", sizeof(struct demo2));
	//��ӡ1,��������ַ����С��8λ,�����Ϊһ���ֽ�,ͨ��λ��������λ�ֶ�

	getchar();
}

void main() {

	printf("%d,%d", sizeof(struct demo1),sizeof(long long));
	//��û��long long��ʱ���ӡ4���ֽ�,ֻ��int,���������û�дﵽint�Ĵ�С,���Ի��Զ����뵽int��С4byte
	//����long long ��ʱ��,���Զ����뵽16���ֽ�
	getchar();

}
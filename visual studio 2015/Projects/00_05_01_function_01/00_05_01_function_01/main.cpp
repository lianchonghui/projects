#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


int addA(int num, ...) {

	double last = 0.0;

	//����һ��va_listָ��,�����ڴ�����va_start�����׵�ַ��va_list����ָ��ָ��İ���num����С���ڴ�
	va_list args;

	va_start(args, num);

	//ͨ��ѭ���������в���,��ͨ��va_arg()��ָ������ʹ洢�����ز���ֵ
	for (int i = 0;i < num;i++) {

		last+=va_arg(args, double);


	}
	//����ɨ�����
	va_end(args);

	return last;
}

int main() {
	//�������������

	//����������Ĳ���
	//1.va_listָ�붨���ڴ��ַ
	//2.va_start����va_listָ����ڴ�ռ�
	//3.ѭ��ɨ�����в���,ͨ��va_arg����,������ָ��������д���ڴ�,��������ֵ
	//4.������ȡ


	double res = addA(4, 12.0, 12.5, 13.0, 13.5);

	printf("%fl", res);

	getchar();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#define NDEBUG //���ж���NDEBUG��ʱ��������

#define DEBUG //����myassert�Ķ���

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#ifndef  DEBUG //��û�ж���DEBUG��ʱ��myassert(x)��ִ���κζ���,������������
#define myassert(x)
#else
#define myassert(x) \
if (!(x))\
{\
	printf("myassert(%s)�꿪ʼ���...\n",#x);\
	printf("��ǰ������Ϊ%s,�ļ���Ϊ%s,�����к�Ϊ%d",__FUNCTION__,__FILE__,__LINE__);\
	char str[50];\
	sprintf(str,"��ǰ������Ϊ%s,�ļ���Ϊ%s,�����к�Ϊ%d",__FUNCTION__,__FILE__,__LINE__);\
	MessageBoxA(0, str, "error", 0);\
}

#endif // !




int main() {

	int num1, num2;
	scanf_s("%d%d", &num1, &num2);

	myassert(num2 != 0);//����

	printf("%d", num1 / num2);
	

	system("pause");
	return 0;
}




int main1() {
	//assert.hͷ�ļ������Ķ���


	int num1,num2;
	scanf_s("%d%d", &num1,&num2);

	assert(num2 != 0);//����

	printf("%d", num1 / num2);

	system("pause");
	return 0;
}
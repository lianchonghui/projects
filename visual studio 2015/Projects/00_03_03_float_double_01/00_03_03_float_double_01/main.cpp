#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void main() {


	//float f1 = 1.5; 
	//printf("%d", sizeof(f1));
	//printf("%x", &f1);

	//system("pause");

	//ͨ��int��double����ת��ʵ����������

	//double db2 = 13.44;
	//int num = 13;
	//double newnum = num / 10;//1.000000
	//double newnum2 = num / 10.0;//1.30000
	//printf("newnum=%f,newnum2=%f",newnum,newnum2);
	////˵��һ����������10�Ժ��һ��С�����Զ�ȡ��Ȼ��ֵΪdouble����,���ǳ���10.0�ͻ���ʽת��Ϊdouble

	//double db;
	//scanf("%lf", &db);

	//printf("��ǰdb��%f \n", db);
	//
	//double newdb = (int)(db * 10 + 0.5) / 10;//ע������Ҫ����10.0,intǿת����db*10+0.5�Ĳ���,ǿת�Ժ�Ϊint������,�������10,�ͻ������ͻ��Զ�ȡ��,����10.0��ת��Ϊdouble�ٳ��Ͳ���ȡ����

	//printf("���������Ժ��db��%f \n", newdb);

	//printf("͵�õ�money��%f", db - newdb);

	//printf("%d", sizeof(long long));//8
	char str[6] = "hello";
	char str2[] = { 'h','e','l','l','o'};

	//printf("%s", str);
	//printf("\n%d", sizeof(str));
	//printf("\n%s", str2);
	////�����str2[5]�ͻ��ӡ����,ĩβ������,��Ϊ%s������'\0'�Ż������ȡ
	////�����str2[6],�����ڵ�Ԫ�ز���,Ҳ�����ȡ����,���һ��Ԫ���ǿ��ַ�,Ҳ�����ֶ����'\0',
	////(�½����鲢ָ����С,û�г�ʼ���Ļ��Զ������ַ�)
	////������Ϊ�ַ�����ʱ����str,�����С��Ҫ���ַ�������һ�����Զ����'\0'������־
	//printf("\n%d", sizeof(str2));


	/*printf("%i,%i,%i\n", 15, 015, 0x15);*/
	
	int i1, i2, i3;
		scanf("%i %i %i", &i1,&i2,&i3);
		printf("%d,%d,%d\n", i1, i2, i3);

	int d1, d2, d3;
	scanf("%d %d %d", &d1, &d2, &d3);
	printf("%d,%d,%d\n", d1, d2, d3);
	system("pause");








}
#include<iostream>
#include<stdlib.h>

using namespace std;
int jia(int a, int b);
int jian(int a, int b);
int change(int(*p)(int, int));
int(*changep(int(*p)(int, int)))(int, int);

int main() {

	//����ָ��
	//int (* p)(int, int) = jia;//����ͬ��
	int(* p)(int, int)(jia);
	cout << p(1, 2) << endl;

	//����ָ����Ϊ����
	change(jia);

	cout << "------------------" << endl;
	cout << p(1, 2) << endl;//3

	//changep�ı���p(����ָ��)��ָ��,��ͨ������ֵ�����ⲿ��p.(��Ϊ�����и�������,����������÷���ֵ,������ͨ�����������û��߲����Ƕ���ָ��ķ�ʽ)
	p=changep(p);

	cout << p(1, 2) << endl;//-1

	system("pause");
	return 0;

}

int jia(int a, int b) {
	return a + b;
}

int jian(int a, int b) {
	return a - b;
}

//����ָ����Ϊ���������
int change(int(*p)(int, int)) {
	
	cout << p(1, 2) << endl;

	//ͨ������ָ��ı�ָ��ָ��ĺ�������Ϊ�����и������ƣ������ڲ��ĺ���ָ��p�ĸı�Ժ������pû��Ӱ��
	p = jian;
	cout << p(1, 2) << endl;

	return 0;
}

//����ָ����Ϊ����ֵ�����
//����ָ����Ϊ����ֵ�ĸ�ʽ�ǣ�
//���纯������ֵ�Ǻ���ָ��Ϊ:int(* )(int,int),����һ�������ĺ���ָ��.������Ϊ����ֵ��ʱ�������Ͳ�������*�ź���,
//�����Ǻ�����Ϊchangep,������int(* p)(int,int)//ע��,���������һ������ָ��,ָ����Ϊp

int(* changep(int(* p)(int,int)))(int, int) {
	p = jian;
	return p;
}
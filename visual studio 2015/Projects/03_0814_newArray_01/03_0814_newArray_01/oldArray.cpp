#include<iostream>
namespace my {
	namespace inmy {
	}
}
class myclass {
public:
	class inclass {
	};
	struct mystruct {
	};
	//namespace myns { }//����Ӧ��������,namespace����
};

int main() {

	myclass mc;
	myclass::inclass ic;
	myclass::mystruct ms;

	//��������,��������ʵ��һ��ָ�볣��,�����޸���ָ��,
	//�����κζ����鸳ֵ�ķ�ʽ�Ǹı���ָ��Ķ��ᱨ��,��ֵ�����޸�

	int a1[3] = { 1,3,4 };
	//int a2[3] = a1;//����,����������ʼ��
	//int a3[3];
	//a3 = a1;//����,a3�ǲ������޸ĵ���ֵ

	int a4[3] = { 0 };
	//a4 = a1;//��ֵ�����޸�

	return 0;
}
#include <iostream>
using namespace std;

//����new��������̽��
//1.new�����������ȷ����ڴ�(�ײ�Ӧ����malloc),Ȼ���ʼ��(���ù��캯��).�������ȫ��new��ʵ�ֵ�.
//2.ÿ��ʹ��new�������һ�ι��캯��,������ÿ��new�Ľ���֮�ʵ�.
//3.��������ڲ�new���غ���û�е���ȫ��new,�����Ͳ�����ù��캯����ʼ��,��Ϊû�е���ȫ��new,��û�з����ڴ�,�����͵��ò��˹��캯��
//4.ͬ�ֶ���ĺ���(�������캯��)����ڴ�����,�ǹ��õ�,�������ڶ���,ÿ������˽�е�.
//5.��Ȼ���캯������,�������û�и���������ڴ�,���繹�캯����ǰһ��������������ڴ�,�������Ҳ�ǵ��ò��˵�.
//6.��Ȼһ���������ι��캯��,���Ǵ�������ʱֻ������һ���ڴ�(ȫ��new��malloc),���Դ����Ķ���ֻ��һ��
//7.size_t��size���ǽṹ��(��)�Ĵ�С,���Զ�����
//8.�ֲ�new��ȫ��new��ִ��˳����:�ֲ�new->ȫ��new->ȫ��new�е�malloc->ȫ��new���ù��캯��->�ֲ�new���ù��캯��

//����delete��������̽��
//1.delete��ִ��˳����:������������->�ֲ�delete->ȫ��delete->ȫ��delete�е�free
//2.delete������������ֻ�����һ��,����һ��ʼ����delete֮���ȵ�������������

static int i = 1;
static int j = 1;
class mystr
{
private:
	int a;
public:

	mystr()
	{
		if (i == 1) {

			cout << "mystr1" << endl;
		}
		else
			cout << "mystr2" << endl;
		
	}
	~mystr()
	{
		cout << "~mystr" << endl;
	}
	void * operator new(size_t size)
	{

		if (j == 1) {
		cout << "���󱻴���" << endl;
		cout << size << endl;
		mystr *my1 = ::new mystr;
		i++;//�ж���ȫ��new�ȵ��ù��캯�����Ǿֲ�new�ȵ��ù��캯��
		j++;
		return my1;

		}
		else
		{
			cout << "2���󱻴���" << endl;
			return 0;
		}
	}
};

void * operator new(size_t size) {

	if (size == 0) {
		return 0;
	}
	cout << "ȫ��" << size << endl;
	void *p = malloc(size);
	return p;

}

int main()
{
	mystr *my1 = new mystr;
	mystr *my2 = new mystr;

	getchar();
	return 0;
}
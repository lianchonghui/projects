#include<stdio.h>
#include<stdlib.h>

//typedef,���Ͷ���,�����ڱ���׶�
//�����������Ƕ���һ���µ����Ͷ��Ǹ����е�������һ������������һ���������õĺ������ƣ������Ǳ��������ı�������typedef����������͵ı���


int add(int a, int b) {
	printf("%d\n", a + b);

	return a + b;
}


void main() {

	//typedef �������͵Ķ���
	typedef unsigned int UINT;
	typedef long long LL;

	UINT num = 12;
	LL ll= 324342354;
	printf("%d,%d\n", num, ll);

	getchar();

}

void main2() {
	//typedef��struct���Ͷ���

	//struct�����Ͷ���
	struct person {

		int id;
		char name[16];
		short age;

	};

	//����һ��struct person

	struct person p1 = { 1,"abc",21 };

	//ʹ��typedef,����һ��struct person ����
	typedef struct _person {
		int id;
		char name[16];
		short age;
	}Person;//Person������struct _person

	//struct _person p2;
	//ʹ��Person��������һ������
	Person p3 = { 2,"def",32 };
	
	printf("%d,%s,%d\n", p1.id, p1.name, p1.age);
	printf("%d,%s,%d\n", p3.id, p3.name, p3.age);

	getchar();
}



void main1() {
	//typedef����ָ�����Ͷ���

	//����ָ��������ͳ�ʼ��
	int(*addP)(int a, int b) = add;
	addP(12,32);

	//����ָ�����Ͷ���
	typedef int(*FuncPointer)(int a, int b);//��׼��ʽ,���ʱ��FuncPointer����һ������ָ������,�����Ǻ���ָ��,���Բ���FuncPoint = add;

	FuncPointer pFunc = add;//������һ��FuncPointer���͵ĺ���ָ��pFunc����ֵָ��add����

	pFunc(12, 11);


	getchar();



}
/*
�������壺


typedefΪC���ԵĹؼ��֣�������Ϊһ���������Ͷ���һ�������֡�������������Ͱ����ڲ��������ͣ�int,char�ȣ����Զ�����������ͣ�struct�ȣ��� �ڱ����ʹ��typedefĿ��һ����������һ���Ǹ�����һ���׼���������ȷ�������֣���һ���Ǽ�һЩ�Ƚϸ��ӵ�����������


��;һ����#define������


typedef ��Ϊ�е��� #define �꣬����ʵ���������ͬ���֡���ͬ���� typedef �ڱ���ʱ�����ͣ�����ñ�������Ӧ����ԽԤ�������������ı��滻��


��;�������ٴ���


����һ�����͵ı���������ֻ�Ǽ򵥵ĺ��滻����������ͬʱ����ָ���͵Ķ�����󡣱��磺



    char* pa, pb; // ��������������ǵ���ͼ����ֻ������һ��ָ���ַ�������ָ�룬  
    // ��һ���ַ�������  

��������У�



    typedef char* PCHAR;  
    PCHAR pa, pb;    

�����÷������ã��ر���char* pa, pb�Ķ��壬��ѧ��������Ϊ�Ƕ����������ַ���ָ�룬��ʵ���ǣ�����typedef char* PCHAR�Ͳ���������������⣬�����˴���ķ�����


��;��:    ֱ�ۼ��

���ھɵ�C�����У�����struct����ǰ�Ĵ����У�����struct�¶���ʱ������Ҫ����struct������ʽΪ�� struct �ṹ�����������磺



    struct tagPOINT1  
     {  
        int x;  
        int y;   
    };  
    struct tagPOINT1 p1;  

����C++�У������ֱ��д���ṹ��������������tagPOINT1 p1;



    typedef struct tagPOINT  
    {  
        int x;  
        int y;  
    }POINT;  

POINT p1; // �����ͱ�ԭ���ķ�ʽ��д��һ��struct���Ƚ�ʡ�£������ڴ���ʹ�õ�ʱ��,������C++�У�typedef��������;�����Ǻܴ󣬵��������������������ǰ�ľɴ��뻹���а����ģ��Ͼ���������Ŀ���п��ܻ���������Щ������������Ĵ��롣


��;�ģ�ƽ̨�޹���


��typedef��������ƽ̨�޹ص����͡�

typedef ������һ����Ҫ����;���Ǿ��Ƕ�������޹ص����ͣ����磬����Զ���һ���� REAL �ĸ������ͣ���Ŀ������������Ի����ߵľ��ȣ� 



    typedef long double REAL;   

�ڲ�֧�� long double �Ļ����ϣ��� typedef �������������������� 



    typedef double REAL;   

���ң����� double ����֧�ֵĻ����ϣ��� typedef ����������������



    typedef float REAL;   

Ҳ����˵������ƽ̨ʱ��ֻҪ���� typedef ������У����ö�����Դ�����κ��޸ġ�

��׼��͹㷺ʹ����������ɣ�����size_t�����⣬��Ϊtypedef�Ƕ�����һ�����͵��±��������Ǽ򵥵��ַ����滻���������Ⱥ������Ƚ���


��;�壺���θ�������


typedef ���������θ������ͣ���ָ������顣 
���磬�㲻�������������ظ������� 81 ���ַ�Ԫ�ص����飺 



    char line[81];  
    char text[81];   

����һ�� typedef��ÿ��Ҫ�õ���ͬ���ͺʹ�С������ʱ������������ 



    typedef char Line[81];   

��ʱLine���ͼ������˾���81��Ԫ�ص��ַ����飬ʹ�÷������£� 



    Line text, secondline;  
    getline(text);   

ͬ����������������������ָ���﷨�� 



    typedef char * pstr;  
    int mystrcmp(pstr, pstr);  

���ｫ�����ǵ����һ�� typedef ���塣��׼���� strcmp()�������� const char *'���͵Ĳ�������ˣ������ܻ��������������������� mystrcmp()�� 



    int mystrcmp(const pstr, const pstr);   

��GNU��gcc��g++���������ǻ���־���ģ�����˳�򣬡�const pstr'������Ϊ��char* const����һ��ָ�� char ��ָ�볣���������߱��Ĳ���ͬһ��˼��Ϊ�˵õ���ȷ�����ͣ�Ӧ������������ 



    typedef const char* pstr;  


��;���������


����򻯡�Ϊ���ӵ���������һ���µļ򵥵ı����������ǣ���ԭ�������������ñ����滻һ���ָ������������ѭ�����Ѵ��������Ĳ�����������滻���õ��ľ���ԭ��������򻯰档������ 

 ԭ������




    void (*b[10]) (void (*)());  

������Ϊb�����滻�ұ߲���������ģ�pFunParamΪ����



    typedef void (*pFunParam)();  

���滻��ߵı���b��pFunxΪ��������



    typedef void (*pFunx)(pFunParam);  

ԭ��������򻯰棺



    pFunx b[10];  

ԭ������




    doube(*)() (*e)[9];  

������Ϊe�����滻��߲��֣�pFunyΪ����һ��



    typedef double(*pFuny)();  

���滻�ұߵı���e��pFunParamyΪ������



    typedef pFuny (*pFunParamy)[9];  

ԭ��������򻯰棺



    pFunParamy e;  

��⸴���������õġ������򡱣��ӱ��������������ң�����������һ��Բ���ž͵�ת�Ķ��ķ��������ڷ�������������ţ����ǰ����Һ����˳�����ѭ����ֱ���������������ꡣ������



    int (*func)(int *p);  

�����ҵ�������func��������һ��Բ���ţ����������һ��*�ţ���˵��func��һ��ָ�룻Ȼ���������Բ���ţ��ȿ��ұߣ�������Բ���ţ���˵��(*func)��һ������������func��һ��ָ�����ຯ����ָ�룬������ָ�룬���ຯ������int*���͵��βΣ�����ֵ������int��



    int (*func[5])(int *);  

func�ұ���һ��[]�������˵��func�Ǿ���5��Ԫ�ص����飻func�������һ��*��˵��func��Ԫ����ָ�루ע�������*��������func����������func[5]�ģ�ԭ����[]��������ȼ���*�ߣ�func�ȸ�[]��ϣ�������������ţ����ұߣ�������Բ���ţ�˵��func�����Ԫ���Ǻ������͵�ָ�룬��ָ��ĺ�������int*���͵��βΣ�����ֵ����Ϊint��


��;�ߣ�typedef �ʹ洢��ؼ��֣�storage class specifier�� 


����˵���ǲ����е����˾��ȣ�typedef ���� auto��extern��mutable��static���� register һ������һ���洢��ؼ��֡��Ⲣ����˵ typedef ������Ӱ�����Ĵ洢���ԣ���ֻ��˵����乹���ϣ�typedef ������������ static��extern �����͵ı������������潫�����ڶ������壺 



    typedef register int FAST_COUNTER; // ����  

��������ͨ��������������㲻�����������ж���洢��ؼ��֡���Ϊ���� typedef �Ѿ�ռ���˴洢��ؼ��ֵ�λ�ã��� typedef �����в����� register�����κ������洢��ؼ��֣���
*/
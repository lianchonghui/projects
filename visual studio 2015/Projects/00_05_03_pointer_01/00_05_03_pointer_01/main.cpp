#include<stdio.h>
int num2 = 1;

void cpointer(int* p) {

	p = &num2;

	printf("%x\n", p);


}

void cpoint2(int** pp) {
	*pp = &num2;

}

void main77() {
	//数组名是一个指针常量,所以这个数组名指针不可以再赋值指向别的变量或常量, 
	int a[3] = { 2,3,4 };
	//a是一个指针常量

	//常量指针和指针常量
	//常量指针:定义为指针指向的变量的值不可通过该指针修改
	//指针常量:定义为常量的值是一个指针,这个指针不可以被修改指向其他变量或常量,但指向的变量可以被修改

	//a就是一个指针常量
	//a = 0x123123123;//表达式必须是可修改的左值
	//所以a是一个常量,但a又是一个地址数据(指针的一种)
	//所以
	*a = 12;
	printf("%d", a[0]);
	//a指向的值被修改,所以a是一个指针常量

	//指针有两种描述(变量或者只是一个变量地址):
	//指针作为实体(变量)，是一个用来保存一个内存地址的计算机语言中的变量。
	//指针作为数据类型(变量地址)，可以从一个函数类型、一个对象类型或者一个不完备类型中导出

	getchar();
}



void main10() {

	int num = 100;
	int* p = &num;
	//printf("%d\n", *p++);
	//这里是先*p映射(赋值)给%d,然后p++,相当于*(p++),*和++的优先级一样,运算顺序是从右到左,因为++在右表示先赋值再++

	printf("%d\n", (*p)++);
	//这里是先*p取值然后映射给%d,最后是100+1
	
	
	printf("%d\n", ++*p);
	//这里是先取值100,然后自增,然后映射给%d,运算顺序是从右到左,因为左++是先自增在赋值


	printf("%x,%x,%x,%x", num, &num, *(&num), &(*(&num)));
	

	//char* cp;
	//short* sp;
	//int* ip;
	//double* dp;
	// 
	//printf("%x,%x,%x,%x",sizeof(cp), sizeof(sp), sizeof(ip), sizeof(dp));


	getchar();
}




void main9(){
	//指针引用多为数组
	int arr[5] = {1,2,4,6,8};
	printf("%p,%p,%p\n", arr, &arr, *arr);
	printf("%d,%d,%d\n", sizeof(arr), sizeof(&arr), sizeof(*arr));//20,4,4


	int arr2[3][4]{ 1,2,3,4,5,6,7,8,9,10,11,12 };
	printf("%p,%p,%p,%p\n", arr2, &arr2, *arr2,**arr2);
	printf("%d,%d,%d,%d\n", sizeof(arr2), sizeof(&arr2), sizeof(*arr2), sizeof(**arr2));//48,4,16,4
	//arr2二维数组的起始地址,大小为整个数组的大小
	//&arr2二维数组的地址,大小只为存储地址的大小
	//*arr2表示arr[0]的地址,也是arr[0][0]的地址,大小是正行大小(4个元素)
	//**arr2第一个元素值
	/*printf("%x,%x,%x\n",&,)*/



	getchar();
}

void main8() {

	int inum = 100;
	double dnum = 100.00;

	int* ip = &inum;
	double* dp = &dnum;
	int** ipp = &ip;

	printf("%d,%d\n", sizeof(int), sizeof(double));
	printf("%d,%d,%d\n", sizeof(ip), sizeof(dp),sizeof(ipp));
	//不管是什么类型指针,指针变量的大小都是4字节

	getchar();





}


void main7() {
	//指向数组的指针与指向数组元素的指针(即二维数组与一维数组)
	int arr[5] = { 1,2,4,6,8 };



	int* p = arr;//指向元素的指针
	
	int arrarr[5][8] = { {0} };
	int(* aap)[8] = arrarr;//一定要有括号(*aap),*aap表示了一个一维数组

	int (*pa)[5] = &arr;//指向数组的指针表示有五个arr,就是arrarr[5][5]???

	printf("%x,%x\n", arr, &arr);
	printf("%d,%d\n", sizeof(*arr), sizeof(*(&arr)));
	printf("%d,%d\n", sizeof(*p), sizeof(*pa));//*p=4表示每一维数组元素的大小,*pa=20表示每个二维数组中的一组元素的大小

	//若有定义int(*p)[3];则定义了一个名为p的指针变量，表示p是一个指针变量，
	//	它可以指向每行有三个整数（即int型）元素的二维数组.p是指向一维数组
	//	的指针变量。这句话的理解是首先(*p)[3]是一个指向一维数组的指针变量，
	//	意思就是p这个指针是指向一个含有3个元素的数组的，那么p指针每一次加1
	//	就相当于把p中存的地址加6（前提是int类型占2个字节，在VC中是占4个字节）。
	//	举个例子：int a[3][3]; int(*p)[3]; p = a; 
	//p=a的意思是把数组a的首地址存放到p中那么p[1]就是a[1][0]的地址，
	//p[1][0]就等于a[1][0]，而p[1][2]就等于a[1][2].
	
	getchar();

}

void main6() {

	//指针和数组的关系,指针的运算
	int arr[5] = { 1,2,4,6,8 };

	//printf("%x,%x,%x", arr, &arr, &arr[0]);//相等

	//printf("\n%x,%x\n", *arr, arr[0]);//相等

	//printf("%x,%x\n", &arr[1], arr + 1);//相等,因为int* p=arr,所以arr其实就是一个指向int类型的常量指针,常量不可赋值,
	//但是arr==&arr,这个是在一个地址中存储了跟地址一样的数值?
	//这是错的,因为arr=&arr=&arr[0],而arr[0]就是arr地址下的变量值

	//数组名表示的是一个常量指针,
	//常量指针的值存的不是一个变量的地址,但是可以通过*数组名来获取该指针指向的值

	//printf("%x,%x\n", *(arr + 2), arr[2]);//相等

	//结论:
	//arr=&arr=&arr[0],arr+i=&arr[i],*arr=arr[0],*(arr+i)=arr[i]


	//通过指针循环遍历数组
	//for (int* arrp = arr;arrp<arr+5;arrp++) {
	//	/**arrp = *arrp - 1;*/
	//	printf("%d,%x\n", *arrp, arrp);

	//}
	int* arrp2 = arr;
	while (arrp2 < (arr + 5)) {

		printf("%d,%x\n", *arrp2++, arrp2 - 1);//*arrp2++等价于*(arrp2++),是先*arrp2,然后arrp2++,是指针地址的++(先引用再自增).而(*arrp2)++是指向额变量值++

	}



	getchar();


}



void main5() {

	int i = 100;
	//int* ip = i;//不允许,会发生访问冲突
	//*ip = 3;


	//指针变量的赋值
	int num = 10;

	int* ip1 = &num;
	//int* ip2 = &ip1;//不允许,因为ip2和&ip1的类型不一样,ip2的类型是int*(int类型指针),而&ip1的类型是(int*)*(不能这样表达),即int**
	int** ip2 = &ip1;


}




void main4() {

	int i = 100;

	//double* dp = &i;
	int* ip = &i;
	printf("%x,%f", i, *ip);//用%f不能正确显示i的值

	getchar();





}



void main3() {
	//指针的类型和指针的(值)指向的变量类型要一直
	
	char c = 'c';
	int i = 1;
	char* cp=&c;
	//int* ip=&c;//不允许

	//cp = ip;



}



void main2() {

	//通过二级指针改变指针的指向
	//因为指针变量有基本数据类型的特性,要改变指针变量的值(指向),不能通过参数传递(会复制创建一个新的变量)
	//应用:
	//当然程序内部直接可以重新给指针变量赋值,但另外一个进程的程序是不能改变这个程序的指针变量的
	//所以我们就可以通过二级指针来改变一级指针的指向
	//外部程序能访问该程序的指针地址不能访问该程序的其他变量地址?这又说不通
	int num = 0;
	int* p = &num;
			
	int** pp = &p;

	printf("%x\n", p);

	cpoint2(pp);

	printf("%x\n", p);
	//p的数值改变了
	getchar();


}


void main1() {
	int num1 = 0;
	int* p1 = &num1;

	printf("%x\n", p1);

	cpointer(p1);


	printf("%x\n", p1);

	//p1的值没有改变,说明指针变量是基本数据类型?可以算是基本数据类型?
	getchar();


}
void main11() {
	int a;
	int * const p = &a;    //指针量*p修改*p = 8；（OK）p修改 p++（ERROR）
	int ab;
	const int *p1 = &a;//量指针    *p修改 *p = 8；（ERROR）p 修改 p = &b  （OK）
		
	const int * const p11 = &a;    // *p  p均改变
}

void main() {

	int arr[4] = { 1,2,4,5 };
	printf("%x",sizeof(arr));

}
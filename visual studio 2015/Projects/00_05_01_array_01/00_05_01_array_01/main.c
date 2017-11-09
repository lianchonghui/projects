#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


void main() {
	while (1) {

	
		int num = 0;
		int result = 0;
		scanf("%d", &num);
		while (num)
		{
			num /= 10;
			result++;
		}

		printf("%d\n", result);

		getchar();
	}
	getchar();

}





void main6() {

	//int i = 100;
	//int** ipp = &i;//错误,间接级别不同

	//printf("%d", ipp);

	int a[2][3] = { 1,2,3,4,5,6 };
	int(* p)[3] = a;

	printf("%x,%x,%x,%x,%x,%x\n",a,p,a + 1,p+1,*(p+1),**p);

	getchar();

}



void main5() {
	//动态二维数组及其初始化,二维数组在内存中是线性排列的
	//1.列固定的动态二维数组
	//2.行列都不固定的二维数组



	//1.列固定的动态二维数组
	int x, y;
	char c;
	scanf_s("%d%d%c", &x,&y,&c,1);
	//使用scanf_s();获取字符时,要在&c后面加上一个参数表示最长的输入长度
	//如果读取的是%s,表示最长的输入长度是n-1,有一个是结束标志\0
	//
	//scanf("%d%d%c", &x, &y,&c);

	//定义一个空类型指针,指向一块分配的内存
	void *p = malloc(sizeof(int)*x*y);//分配内存,连续的内存
	
	//y必须是一个已知的常量,才能将这片内存当做一个二维数组来使用
	//因为定义一个变量,必须给它分配内存空间,分配多达?根据什么来分配呢?
	//首先,基本变量是根据类型来分配的如int,float,double等来分配4或8个字节
	//对于数组的内存分配,是根据类型*数量即sizeof(int)*n来分配的,n可以根据数组元素个数而定
	//在二维数组中,arr[n][m],第一个[n]的大小可以根据元素个数来动态决定,而m是不是能输出来的
	//因为每个数组元素(二维里面的一维数组)里的元素不一定相等


	int(*ap)[9] = p;//指针类型不同,不能转换,c++中是不允许的
	int num = 1;

	for (int i = 0;i < x;i++) {

		for (int j = 0;j < 9;j++) {

			ap[i][j] = num++;

			printf("%4d", ap[i][j]);

		}
		printf("\n");
	}



	printf("----------------------------\n");

	//2.行列都不固定的二维数组
	//二级指针-->指针数组(数组里面的指针)-->指向一个二维数组
	int x2, y2;
	char c2;
	scanf_s("%d%d%c", &x2, &y2, &c2, 1);
	
	//二级指针(这里是数组指针,指向一个数组,所以大小为一个数组x个元素的大小总和)可以存储指针数组(一个存储指针的数组)的地址
	int **pp = (int**)malloc(sizeof(int*)*x);
	//pp是一个二级数组指针,相当于是int* pp[n]
	//int a[3][4];
	//int(* ap)[4] = a;
	//int(* app) = a[0];

	for (int i = 0;i < x;i++) {

		//分配内存,有多少列,每个指针都存储这样一片内存的地址
		//pp[i]就相当于二维数组a[i][j]的a[i],

		pp[i] = malloc(sizeof(int*)*y2);
		
	}
	
	int num2 = 1;
	for (int i = 0;i < x;i++) {
		for (int j = 0;j < y;j++) {
			//pp[i][j] = num2++;
			*(*(pp + i) + j) = num2++;

			printf("%4d", pp[i][j]);

		}
		printf("\n");
	}










	getchar();//会读取前面scanf_()输入的\n字符
	//getchar();

	//关于scanf()和getchar()的输入:
	//对于回车转义符\n,scanf("%c",&c)和getchar()会读取
	//当有scanf("%d%d",&num1,&num2)时我们键盘输入的是2\n2\n,中间\n没有格式符与之映射就会跳过,而最后一个\n就会保留在键盘缓冲区
	//这种情况当我们在这个scanf()之后要键盘输入字符时,缓冲区\n就会当做一个字符输入

}





void main4() {
	//二维数组初始化的三种方式(直接初始化除外):
	//1.嵌套循环初始化
	//2.单个循环内用算式技巧初始化
	//3.利用指针方式初始化


	//1.嵌套循环初始化
	int arr1[3][4];
	int num1 = 1;
	for (int i = 0;i < 3;i++) {
		
		for (int j = 0;j < 4;j++) {

			arr1[i][j] = num1++;
			printf("arr1[%d][%d]=%2d   ", i, j, arr1[i][j]);
		}

		printf("\n");
	}

	printf("-----------\n");

	//2.单个循环内用算式技巧初始化
	int arr2[3][4];
	int num2 = 1;

	for (int i = 0;i < 3 * 4;i++) {

		arr2[i / 4][i % 4] = num2++;

		printf("arr2[%d][%d]=%2d   ", i / 4, i % 4, arr2[i / 4][i % 4]);

		if (i % 4 == 3) {
			printf("\n");

		}

	}



	printf("-----------\n");

	//3.利用指针方式初始化
	int arr3[3][4];
	int num3 = 1;

	int(*p)[4] = arr3;

	for (int i = 0;i < 3;i++) {
		
		for (int j = 0;j < 4;j++) {

			//p[i][j] = num3++;
			*(*(p + i) + j )= num3++;//里面的*获取到了二维数组中的一位数组(数组元素)的地址,外面的*获取到了一维数组元素中的元素
			printf("arr3[%d][%d]=%2d   ", i, j, *(*(p + i) + j));
		}
		printf("\n");

	}


	getchar();
}







void main3() {
	//二维数组和指针的关系


	int arr[2][3] = { 1,2,3,4,5,6 };
	

	//二维数组中的数组指针:像一位数组名相当于一个一级指针一样,二维数组名也是一个一级指针,但这个指针是一个数组指针了

	//int* ap = arr;//不可以,arr本质是数组,不是指针,arr的范围确定不能用int*,要用int*[3]才能确定
	int(*ap)[3] = arr;//ap是一个数组指针,指针指向的是一个数组(这里是一维数组)
	printf("%d,%d,%d\n", **ap,**arr,arr[0][0]);

	//定义一个一级指针指向二维数组内的第一个一维数组的元素
	int(*ap3) = arr[0];
	printf("%x,%x\n", *(ap3+1),arr[0][1]);//相等,都是2


	printf("----------------------\n");
	//所以
	printf("%p,%p,%p\n", ap, arr[0],&arr[0][0]);//相等
	printf("%p,%p,%p\n", ap + 1, arr[1],&arr[1][0]);//相等
	//主要点:ap+1的地址的二维数组中的第二个元素(数组元素)的起始地址

	printf("----------------\n");

	//二维数组arr的&arr被赋值一个指针的情况:
	//这个时候&arr就是一级指针ap2的值, 这个指针指向二维数组变量,其范围应该是int*2*3,
	int(*ap2)[2][3] = &arr;

	//使用指针遍历二维数组
	//ap2=&arr,*ap2=arr
	printf("%x,%x,%x,%x,%x\n", ap,*ap2,arr,arr[0],&arr[0][0], ap2[0][0], *ap2[0]);//相等
	printf("%x,%x,%x,%x,%x,%x,\n",arr[0][0],*arr[0],**ap,*ap[0],ap[0][0],*ap2[0][0]);//相等,所以有三种方式数组取值(*arr[0]与*ap[0],**ap一样,ap[0][0]与arr[0][0]一样)

	//数组取值的四种方式
	//方式一:通过数组名/指针加下标直接遍历
	//方式二:*(数组名或者指针)+下标(地址)方式直接取值
	//方式三:int(*ap2)[2][3] = &arr;,通过一个指向二维数组的指针间接获取值*ap2[0][0]

	getchar();

}






void main2() {

	//一维数组和指针的关系


	//数组名arr的类型就是(编译器当其是,本质是数组地址,可以隐式转换为指针而已,就像float会隐式转换为double)int*(常量指针),
	//指向一个常量就是数组的起始地址),一个int指针,所以我们可以直接赋值一个int*指针
	//arr的其实是(arr+0),是常量指针,可以直接通过*(arr+i)来获取数组的元素值

	//arr和&arr的区别
	//1.&arr是数组变量arr的地址,是常量指针arr的地址
	int i = 100;
	int* ip = &i;
	int** ipp = &ip;
	//所以&arr可以赋值给一个二级指针?
	//int** app = &arr;//不可以
	//int(* app)[5] = &arr;//可以
	//为什么
	//因为arr本质不是指针,只是一个数组地址其范围是整个数组的大小,所以&arr(数组变量的地址就是一个变量的地址)可以赋值给一个变量指针,这个指针是一个数组指针(一级指针)
	//对数组指针的话还要再指定这个指针的影响范围,所以就要再加上[]来确定(比如对int* 指针,其范围已经指定,就是int类型的大小)
	//数组变量arr的作用范围是5个int空间数据,所以&arr赋值给变量app(指针变量),app的类型应该是:int(*)[5],也就是指向包含五个int数据的数组指针
	//数组指针:指向数组的指针
	//如果是二维数组的话,

	//arr+1和&arr+1的区别:
	//arr+1表示数组第二个元素地址,&arr+1,表示跨过arr数组的下一个地址

	//数组首地址的意义:
	//首地址是元素的起始,也是是这个数组的起始,假设有两个相连的数组,那么这个首地址也是这两个数组的起始



	//也可以直接通过指针和下标遍历数组

	//遍历数组的三种方式
	//方式一:通过数组名和下标直接遍历arr[i]
	//方式二:通过指针和下标直接遍历ap[i](方式一与二一样)
	//方式三:通过*(指针+下标)间接遍历*(ap+i)
	//方式四:定义一个数组指针int*app[5]用&arr赋值,然后通过指针间接遍历:*app[i]

	int arr[5] = { 1,2,4,8,16 };


	//创建一个int类型的数组指针(不是指针数组)
	int* ap = arr;//ap不能初始化为&arr,arr就是int*类型

	//int** appp = arr;

	//int** ap2p = &ap;

	//printf("%x,%x\n", **appp, **ap2p);

	int(* app)[5] = &arr;//可以
	//int** app = &arr;//不可以

	printf("%p,%p,%p,%p",arr,app + 1, &arr + 1,arr+1);//app+1=&arr+1=arr+sizeof(int)*4
	//指针加1表示的是其值加上类型的大小

	for (int i = 0;i < 5;i++) {

	printf("%d\n", ap[i]);

	printf("%d\n", *(ap + i));


	}


	getchar();


}




void main1() {

	//printf("%d", sizeof(double));

	//double arr[5] = { 0 };
	//printf("%d\n", sizeof(arr));
	//for (int i=0;i<8;i++) {
	//	/*printf("%lf", arr[i]);*/
	//
	//}

	//const int a = 2;//

	//	int i=0;
	//while (1) {
	//	printf("-------\n");
	//	printf("%x\n", &a);

	//int arr2[a] = { 0 };//不合法,a是可变的常量,为什么?
	//printf("%d\n", arr2);
	//printf("%d\n", &arr2);
	//printf("%d\n", sizeof(arr2));
	//	i++;
	//	if (i > 100)
	//		break;


	//}


	//printf("%d\n", 0 % 4);
	//int a[][3] = { {1,2} ,{1,2},{1,2,3} };//第二个是一定要指定的,因为无法通过元素多少(每一个内部数组内个数不一定相等)自动确定

	//int d[5][3];
	//for (int i = 0;i < 15;i++) {
	//	/*d[i / 3][i % 3] = i;*/
	//	printf("d[%d][%d]=%d\n", i / 3, i % 3, i);


	//}
	//int num = 0;
	//int *p = &num;
	//printf("%x,%x,%x,%x\n", &num,p,*p,&p);


	int arr[5] = { 0 };
	printf("%x,%x,%x", arr, &arr, &arr[0]);



	getchar();

}
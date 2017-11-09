#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<io.h>

#include<errno.h>
#include<string.h>

int main() {

	//文件数据块操作:fwrite(),fread();
	
	//1.对于fwrite(),fread()首先要给一个缓冲区,即数组
	//2.每个元素的长度
	//3.总共多少元素(缓冲区内元素的个数)
	//4.文件指针

	FILE * pf = fopen("D:/2.txt", "w+");

	if (pf == NULL) {
		printf("文件打开失败!");
	}
	else {

	//创建写入缓冲区,并写入数据
	double db[10] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };

	//写入
	fwrite(db, sizeof(double), 10, pf);


	//创建读取缓冲区,并初始化
	double dbr[10] = { 0 };

	//文件指针回到文件开头
	rewind(pf);

	fread(dbr, sizeof(double), 10, pf);//将文件通过pf指针读取存储到缓冲区

	//遍历缓冲区数据
	for (int i = 0;i < 10;i++) {
		printf("%fl ", dbr[i]);
	}
	printf("\n");
	
	fclose(pf);//fclose()的作用是关闭流,同时pf=null,而delete()指针以后就要赋值NULL
	//pf = NULL;

	}
	

	system("pause");
	return 0;
}



int main8() {
	//Windows键盘输入无缓冲模式分析(没缓冲其实是两个字节缓冲)


	system("pause");
	return 0;
}




int main7() {

	//文件定位:ftell和fseek()
	//ftell()用于获取指针位置与文件开头的的字节数
	//fseek()用于定位文件指针的位置

	FILE * pf = fopen("D:/1.txt", "a+");//这里用a打开文件,如果用w打开会抹除原来的数据

	if (pf == NULL) {
		printf("文件打开失败\n");
	}
	else {
		printf("文件打开成功\n");
	
	int length = ftell(pf);
	printf("fseek前文件字符个数是:%d\n", length);//指针一开始指向文件开头,当指针指向文件末尾以后才能统计字符(字节)数

	//fseek(pf, 0, SEEK_END);
	fseek(pf, 0, 2);
	//2 SEEK_END
	//0 SEEK_SET 等价于rewind(),//文件回到开头,指针回到起始位置//fflush()针对缓冲区,指针会到起始位置   文件>程序缓冲区
	//1 SEEK_CUR

	length = ftell(pf);

	printf("fseek后文件字符个数是:%d\n", length);

	fputs("\n//我插入了一段文字", pf);//插入了一段字符串后,指针位置是向后移动这个字符串长度的大小
	//这里第一个\n字符要想达到换行的目的,就要以a或者at的方式打开文件,ab方式打开不换行,也没空格

	//rewind(pf);
	length = ftell(pf);
	printf("在末尾插入了一段文字后后文件字符个数是:%d\n", length);

	fclose(pf);
	//pf = NULL;

	}

	system("pause");
	return 0;
}



int main6() {

	//输出错误信息:perror/ferror/clearerr/strerr

	//在库函数中有个errno变量，每个errno值对应着以字符串表示的错误类型。当你调用"某些"函数出错时，该函数已经重新设置了errno的值。perror函数只是将你输入的一些信息和现在的errno所对应的错误一起输出。

	

	//1.strerr标准输出(设备)文件，对应终端的屏幕。进程将从标准输入文件中得到输入数据，将正常输出数据输出到标准输出文件，而将错误信息送到标准错误文件中。在C中，程序执行时，一直处于开启状态。
	
	//2.perror(s) 用来将上一个函数发生错误的原因输出到标准设备(stderr)。参数 s 所指的字符串会先打印出，后面再加上错误原因字符串。此错误原因依照全局变量errno(这里的说法不准确,errno是一个宏,该宏返回左值) 的值来决定要输出的字符串。
	//perror和strerror都是C语言提供的库函数，用于获取与errno相关的错误信息，区别不大，用法也简单。最大的区别在于perror向stderr输出结果，而 strerror向stdout输出结果。
	
	//3.ferror，函数名，在调用各种输入输出函数（如 putc.getc.fread.fwrite等）时，如果出现错误，除了函数返回值有所反映外，还可以用ferror函数检查。 
	//它的一般调用形式为 ferror(fp)；如果ferror返回值为0（假），表示未出错。如果返回一个非零值，表示出错。应该注意，对同一个文件 每一次调用输入输出函数，
	//均产生一个新的ferror函 数值，因此，应当在调用一个输入输出函数后立即检 查ferror函数的值，否则信息会丢失。在执行fopen函数时，ferror函数的初始值自动置为0。
	
	//4.clearerr的作用是使文件错误标志和文件结束标志置为0.假设在调用一个输入输出函数时出现了错误，ferror函数值为一个非零值。在调用clearerr（fp）后，ferror（fp）的值变为0。
	//只要出现错误标志，就一直保留，直到对同一文件调用clearerr函数或rewind函数，或任何一个输入输出函数。



	//FILE *pf = fopen("D:/1.txt", "r");
	//printf("%d\n", ferror(pf));//ferror()用来检查输入输出函数(getc(),putc(),fread(),fwrite()等)是否出错

	FILE *pf = fopen("D:/1.txt", "w");
	if (pf == NULL) {
	//if (!ferror(pf)) {
		fprintf(stderr, strerror(errno));
		printf("w方式打开文件失败.\n");
		perror("输出的错误是ABC");//输出的是  输出的错误是ABC:错误信息
		printf("strerror:%s\n", strerror(errno));//strerror在string.h中定义
		//errno 是记录系统的最后一次错误代码。代码是一个int型的值，在errno.h中定义
		
		//clearerr(pf);

		//perror("错误是:");
		
		//ferror(pf);

	}



	system("pause");
	return 0;
}





int main5() {

	//fscanf()的注意事项
	//注意:fscanf()的读取一定要与fprintf()对应(实际格式),否则无法正确读取


	system("pause");
	return 0;
}






int main4() {

	//_access函数,io.h中定义
	//0 文件是否不存在,返回0文件存在,存在返回-1
	//2 文件是否不可写,返回0文件可写
	//4 文件是否不可读,返回0文件可读
	//6 文件是否不可读不可写,返回0文件可读可写

	//FILE *pf = fopen("D:/1.txt", "w");

	printf("%d\n", _access("D:\\1.txt", 0));

	if (_access("D:/1.txt", 0)) {
		printf("文件不存在\n");
	}
	else {
		printf("文件存在\n");
	}
	



	system("pause");
	return 0;
}



int mian3() {

	//fflush()和rewind()





	system("pause");
	return 0;
}


int main2() {
	//文件型结构体
	char ch;
	//printf("缓冲区的有效数据是%d\n",stdin->_cnt);



	system("pause");
	return 0;
}


int main1() {
	//_getw(),_putw()函数

	int w = _getw(stdin);//从键盘获取输入四个字节

	_putw(w, stdout);//显示器输出


	//键盘输入:123456回车键   打印的是:1234
	//键盘输入:123回车键      打印的是:123换行
	//键盘输入:12回车34       打印的是:12换行3
	//键盘输入:我爱你         打印的是:我爱
	//键盘输入:我回车爱你     打印的是:我换行

	printf("-----------------------------\n");

	putchar(97);
	putchar(97);
	putchar(97);
	putchar(97);
	putchar('\n');

	int num = _putw(97, stdout);//可以输出一个字符,但后续的会当做空字符处理

	//_putw(97, stdout);//可以输出一个字符,但后续的会当做空字符处理

	printf("\n num=%d", num);//通过num可以看出,_putw()输出的是num=97


	system("pause");

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main() {
	
	//fgetc(),fputc(),fgets(),fputs(),sprintf(),fprintf(),fwrite(),fread()


	//fgetc()从参数stream所指的文件中读取一个字符，并把它作为一个字符返回,光标位置后移一个字节。若读到文件尾或出现错误时，它就返回EOF，你必须通过ferror或feof来区分这两种情况。
	//fputc()将字符ch写到文件指针fp所指向的文件的当前写指针的位置。在正常调用情况下，函数返回写入文件的字符的ASCII码值，出错时，返回EOF（-1）。当正确写入一个字符或一个字节的数据后，文件内部写指针会自动后移一个字节的位置。EOF是在头文件 stdio.h中定义的宏。

	//char *fgets(char *buf, int bufsize, FILE *stream);
	//从文件结构体指针stream中读取数据，每次读取一行。读取的数据保存在buf指向的字符数组中，每次最多读取bufsize-1个字符（第bufsize个字符赋'\0'），
	//如果文件中的该行，不足bufsize个字符，则读完该行就结束。如若该行（包括最后一个换行符）的字符数超过bufsize-1，则fgets只返回一个不完整的行，
	//但是，缓冲区总是以NULL字符结尾，对fgets的下一次调用会继续读该行。函数成功将返回buf，失败或读到文件结尾返回NULL。因此我们不能直接通过fgets的返回值来判断函数是否是出错而终止的，应该借助feof函数或者ferror函数来判断。

	//int fputs(str,fp)
	//fputs是一种函数，具有的功能是向指定的文件写入一个字符串（不自动写入字符串结束标记符‘\0’）。成功写入一个字符串后，文件的位置指针会自动后移，函数返回值为非负整数；否则返回EOF(符号常量，其值为-1)。


	//int sprintf( char *buffer, const char *format, [ argument] … );
	//字符串格式化命令，主要功能是把格式化的数据写入某个字符串中。sprintf 是个变参函数。
	//返回写入buffer 的字符数，出错则返回-1. 如果 buffer 或 format 是空指针，且不出错而继续，函数将返回-1，并且 errno 会被设置为 EINVAL。
	//sprintf 返回被写入buffer 的字节数，结束字符‘\0’不计入内。即，如果“Hello”被写入空间足够大的buffer后，函数sprintf 返回5。


	//int fprintf( FILE *stream, const char *format, ... );
	//fprintf()函数根据指定的format(格式)发送信息(参数)到由stream(流)指定的文件. fprintf()只能和printf()一样工作. fprintf()的返回值是输出的字符数,发生错误时返回一个负值.

	//int fscanf(FILE*stream, constchar*format, [argument...]);
	// 从一个流中执行格式化输入,fscanf遇到空格和换行时结束，注意空格时也结束。这与fgets有区别，fgets遇到空格不结束。返回值：整型，成功返回读入的参数的个数，失败返回EOF(-1)。

	
	//size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
	//这个函数以二进制形式对文件进行操作，不局限于文本文件
	//返回值：返回实际写入的数据块数目
	//	（1）buffer：是一个指针，对fwrite来说，是要获取数据的地址；
	//	（2）size：要写入内容的单字节数；
	//	（3）count : 要进行写入size字节的数据项的个数；
	//	（4）stream : 目标文件指针；
	//	（5）返回实际写入的数据项个数count。
	//	说明：写入到文件的哪里？ 这个与文件的打开模式有关，如果是w + ，则是从file pointer指向的地址开始写，替换掉之后的内容，文件的长度可以不变，stream的位置移动count个数；如果是a + ，则从文件的末尾开始添加，文件长度加大。
	//	fseek对此函数有作用，但是fwrite[1]  函数写到用户空间缓冲区，并未同步到文件中，所以修改后要将内存与文件同步可以用fflush（FILE *fp）函数同步。


	//size_t fread ( void *buffer, size_t size, size_t count, FILE *stream) ;
	//参 数
	//	buffer
	//	用于接收数据的内存地址
	//	size
	//	要读的每个数据项的字节数，单位是字节
	//	count
	//	要读count个数据项，每个数据项size个字节.
	//	stream
	//	输入流
	//	返回值
	//	实际读取的元素个数。如果返回值与count不相同，则可能文件结尾或发生错误。从ferror和feof获取错误信息或检测是否到达文件结尾。　

	system("pause");
	return 0;
}



void main6() {
	//fclose()对文件指针的影响

	FILE* fp = fopen("D:/test2.txt", "w");

	printf("%p", fp);

	fclose(fp);

	printf("%p", fp);

	fp = fopen("D:/test2.txt", "w");

	printf("%p", fp);

	system("pause");


}

void main5() {
	//这里研究的是feof()函数

	//当以wt写入时,rb读取的是\r\n即1310,rt读取的是\n,即10,在文本文件打开中是换行的
	//当以wb写入时,rb和rt读取的都是\n且在文本文件打开不换行
	//w与wt的效果一样

	//FILE* fp = fopen("D:/test2.txt", "w");

	//int num = fprintf(fp, "%s\n%s", "test1","test2");
	


	FILE* fp = fopen("D:/test2.txt", "rb");
	printf("%p", fp);
	while (!feof(fp)) {
		//printf("fp1=%d,", feof(fp));

		char ch = fgetc(fp);
		/*putchar(ch);*/

		//fgetc()调用并更改了statement值,读取到末尾的时候(应该是末尾的下一个),会得到-1,并更改statement值为1,fp2就会等于1;在此之前statement的值还是0,即feof(fp)的值等于0
		//对于-1会打印为空格

	/*	if (ch == -1) {
			printf("%c", ch);
		}
*/
		printf("%d ", ch);

		//printf("fp2=%d,", feof(fp));

	}

	system("pause");

	/*当feof(FILE *)读到EOF标志并不认为文件结束了，依旧返回0，直到读到EOF的下一个字符才返回1，这时才认为是文件结束。

		因此若以while(!feof(fp))为循环条件的时候，要将一个文件(fp)完全复制到另一个文件(fp1), 需要加上判断if(ch != -1), 如下:


	while (!feof(in))
	{
		ch = fgetc(in);
		if (ch != -1)
			fputc(ch, out);

	}*/

	//“C”语言的“feof()”函数和数据库中“eof()”函数的运作是完全不同的。数据库中“eof()”函数读取当前指针的位置，
	//	“C”语言的“feof()”函数返回的是最后一次“读操作的内容”。多年来把“位置和内容”相混，从而造成了对这一概念的似是而非。
	//(这里feof()位置在结束标志(EOF)的时候,"读操作的内容"读的是结束标志,依然会返回1,)
	//(因为feof只是返回系统的一个statment的值，它是要fgetc fgets fread等等系统调用修改的。
		//fseek(fp, 0, SEEK_END)后文件指针指向size, 如果此时feof(fp)的话，是不会返回非0的，原因就是根本没有系统调用改变了那个statment的值。所以还是返回0，
		//这样如果不做判断直接fgetc的话，就会获得一个 - 1, 当然也因为这个 - 1系统改变了statment的值，所以
		//先fseek(fp, 0, SEEK_END)然后fgetc（）之后再调用feof的时候就会返回非0)
	//	那么，位置和内容到底有何不同呢？举个简单的例子，比如有人说“你走到火车的最后一节车箱”这就是位置。
	//	而如果说“请你一直向后走，摸到铁轨结束”这就是内容。也就是说用内容来判断会“多走一节”。这就是完全依赖于“while(!feof(FP)) { ... }”进行文件复制时，
	//	目标文档总会比源文档“多出一些”的原因。

	//EOF就是-1

	//ascii码中，编码小于 0x20 的， “打印”出来的都是“空白”，大于 0x7E“打印”出来的也是“空白”。 - 1 的内码，大于 0x7E，所以“打印”出来的是空白。
}

void main4() {
	//这里研究的是wt和wb,rt和rb的区别

	//当以wt写入时,rb读取的是\r\n即1310,rt读取的是\n,即10,在文本文件打开中是换行的
	//当以wb写入时,rb和rt读取的都是\n且在文本文件打开不换行


	//FILE* fp = fopen("D:/test2.txt", "wt");

	//int num = fprintf(fp, "%s\n%s", "test1","test2");
	//
	FILE* fp = fopen("D:/test2.txt", "rb");

	while (!feof(fp)) {
		printf("fp1=%d,", feof(fp));

	char ch = fgetc(fp);
	/*putchar(ch);*/

	if (ch == -1) {
		printf("%c", ch);
	}

	printf("%d ", ch);

	printf("fp2=%d,", feof(fp));

	}

	system("pause");
}


void main3() {
	//这里研究的是fclose()的问题

	FILE* fp = fopen("D:\\test.txt", "w");//注意at和wt写入的区别,w与wt的效果一样
	//FILE* fp = fopen("D:\\test.txt", "at+");//注意at和wt写入的区别

	/*while (!feof(fp)) {

		char ch = fgetc(fp);
		putchar(ch);

	}*/
	/*rewind(fp);*/

	int a = fprintf(fp, "%s\n", "this is the first example for testing file writing.");
	//写入到fp的是%s\n123
	//当wt时,Windows下\n会转化为\r\n写入,此时打开test.txt是换行的,以rt+/rb+打开读取时是换行的,且在末尾换行后有一个空格
	//当wb时,Windowsxia\n就是以\n的二进制写入,此时打开test.txt是不换行的,用rt+/rb+打开读取是换行的.且在末尾换行后有一个空格

	//以下写入的时候,两句sentence都是successfully的,这说明不管wt还是wb在缓冲区的时候都是\n,写入到文件的时候才转化为\r\n


	printf("%d\n", a);

	if (a == strlen("this is the first example for testing file writing.\n"))
		printf("%s\n", "the sentence is written into the file successfully.");

	fclose(fp);//fclose()1

	fp = fopen("D:\\test.txt", "at+");
	//fp = fopen("D:\\test.txt", "wt+");
	//fp = fopen("D:\\testt.txt", "at+");
	a = fprintf(fp, "%s\n", "this is the second example for testing file writing.");

	printf("%d\n", a);

	if (a == strlen("this is the second example for testing file writing.\n"))
		printf("%s\n", "the sentence is written into the file successfully.");


	//int res=fclose(fp);//fclose()2
	//fclose(fp);
	//如果fclose()1没有,这里会导致second那句没有写入到test中,为什么?如果fp的路径为testt.txt的时候,second的语句就会写入到testt.txt中
	//再者,如果第一个fopen()的打开方式由wt改为at的话,second语句会写入的test中,且second语句是在first语句的前面

	//所以,原因是当第一个打开方式是wt且没有fclose()1的时候,fp重定向到了at的fopen(),如果没有没有fclose()2则会顺序写入到test.txt中
	//如果有fclose()2,结果会导致先将second语句刷入到test.txt中,然后用wt打开,在抹掉数据,刷入first的句子.

	//所以当有fclose()1,first,second句子都会按顺序刷入到test.txt,
		//this is the first example for testing file writing.
		//this is the second example for testing file writing.


	
	//当wt改为at的时候会在second刷入后刷入first的句子
		//this is the second example for testing file writing.
		//this is the first example for testing file writing.

	//只有fclose()1的时候会执行结果跟没有fclose一样

	//没有fclose()1和没有fclose()2的时候,为什么first和second的句子会顺序刷入到test.txt中?
	//当关闭程序的时候是真么刷新缓冲区的?
	//当第一个打开方式为wt第二个方式为at的时候,数据是按顺序刷入的(且原来数据被抹掉了)
	//当第一个打开方式为at第二个打开方式为wt的时候,只有second的句子
	//所以在没有fclose()的情况下,刷入的方式是先执行第一个打开方式,再执行第二个打开方式刷入数据
	
	//printf("%d\n", res);
	system("pause");

}

void main2() {
	FILE* fp = fopen("D:\\test.txt", "wb+");//注意wt和wb写入的区别

	while (!feof(fp)) {

		char ch = fgetc(fp);
		putchar(ch);
	
	}
	/*rewind(fp);*/

	//int a = fprintf(fp, "%s\n123", "this is the first example for testing file writing.");
	//写入到fp的是%s\n123
	//当wt时,Windows下\n会转化为\r\n写入,此时打开test.txt是换行的,以rt+/rb+打开读取时是换行的,且在末尾换行后有一个空格
	//当wb时,Windowsxia\n就是以\n的二进制写入,此时打开test.txt是不换行的,用rt+/rb+打开读取是换行的.且在末尾换行后有一个空格

	//以下写入的时候,两句sentence都是successfully的,这说明不管wt还是wb在缓冲区的时候都是\n,写入到文件的时候才转化为\r\n


	//printf("%d\n", a);

	//if (a == strlen("this is the first example for testing file writing.\n123"))
	//	printf("%s\n", "the sentence is written into the file successfully.");

	//fp = fopen("D:\\test.txt", "at+");
	//a = fprintf(fp, "%s\n", "this is the second example for testing file writing.");

	//printf("%d\n", a);

	//if (a == strlen("this is the second example for testing file writing.\n"))
	//	printf("%s\n", "the sentence is written into the file successfully.");


	//fclose(fp);
	//fclose();这里会导致second那句没有写入到test中,为什么?

	system("pause");

}

void main1() {

	FILE* fp = fopen("D:\\test.txt", "wt+");//注意wt和wb写入的区别

	//while (!feof(fp)) {

	//	char ch = fgetc(fp);
	//	putchar(ch);
	//
	//}
	//rewind(fp);

	int a = fprintf(fp, "%s\n123", "this is the first example for testing file writing.");//写入到fp的是%s\n123
	//当wt时,Windows下\n会转化为\r\n写入,
	//当wb时,Windowsxia\n就是以\n的二进制写入

	


	printf("%d\n", a);

	if (a == strlen("this is the first example for testing file writing.\n"))
		printf("%s\n", "the sentence is written into the file successfully.");

	fp = fopen("D:\\test.txt", "at+");
	a= fprintf(fp, "%s\n", "this is the second example for testing file writing.");

	printf("%d\n", a);

	if (a == strlen("this is the second example for testing file writing.\n"))
		printf("%s\n", "the sentence is written into the file successfully.");


	fclose(fp);

	system("pause");



}
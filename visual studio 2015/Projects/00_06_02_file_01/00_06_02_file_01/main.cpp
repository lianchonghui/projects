#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main() {
	
	//fgetc(),fputc(),fgets(),fputs(),sprintf(),fprintf(),fwrite(),fread()


	//fgetc()�Ӳ���stream��ָ���ļ��ж�ȡһ���ַ�����������Ϊһ���ַ�����,���λ�ú���һ���ֽڡ��������ļ�β����ִ���ʱ�����ͷ���EOF�������ͨ��ferror��feof�����������������
	//fputc()���ַ�chд���ļ�ָ��fp��ָ����ļ��ĵ�ǰдָ���λ�á���������������£���������д���ļ����ַ���ASCII��ֵ������ʱ������EOF��-1��������ȷд��һ���ַ���һ���ֽڵ����ݺ��ļ��ڲ�дָ����Զ�����һ���ֽڵ�λ�á�EOF����ͷ�ļ� stdio.h�ж���ĺꡣ

	//char *fgets(char *buf, int bufsize, FILE *stream);
	//���ļ��ṹ��ָ��stream�ж�ȡ���ݣ�ÿ�ζ�ȡһ�С���ȡ�����ݱ�����bufָ����ַ������У�ÿ������ȡbufsize-1���ַ�����bufsize���ַ���'\0'����
	//����ļ��еĸ��У�����bufsize���ַ����������оͽ������������У��������һ�����з������ַ�������bufsize-1����fgetsֻ����һ�����������У�
	//���ǣ�������������NULL�ַ���β����fgets����һ�ε��û���������С������ɹ�������buf��ʧ�ܻ�����ļ���β����NULL��������ǲ���ֱ��ͨ��fgets�ķ���ֵ���жϺ����Ƿ��ǳ������ֹ�ģ�Ӧ�ý���feof��������ferror�������жϡ�

	//int fputs(str,fp)
	//fputs��һ�ֺ��������еĹ�������ָ�����ļ�д��һ���ַ��������Զ�д���ַ���������Ƿ���\0�������ɹ�д��һ���ַ������ļ���λ��ָ����Զ����ƣ���������ֵΪ�Ǹ����������򷵻�EOF(���ų�������ֵΪ-1)��


	//int sprintf( char *buffer, const char *format, [ argument] �� );
	//�ַ�����ʽ�������Ҫ�����ǰѸ�ʽ��������д��ĳ���ַ����С�sprintf �Ǹ���κ�����
	//����д��buffer ���ַ����������򷵻�-1. ��� buffer �� format �ǿ�ָ�룬�Ҳ����������������������-1������ errno �ᱻ����Ϊ EINVAL��
	//sprintf ���ر�д��buffer ���ֽ����������ַ���\0���������ڡ����������Hello����д��ռ��㹻���buffer�󣬺���sprintf ����5��


	//int fprintf( FILE *stream, const char *format, ... );
	//fprintf()��������ָ����format(��ʽ)������Ϣ(����)����stream(��)ָ�����ļ�. fprintf()ֻ�ܺ�printf()һ������. fprintf()�ķ���ֵ��������ַ���,��������ʱ����һ����ֵ.

	//int fscanf(FILE*stream, constchar*format, [argument...]);
	// ��һ������ִ�и�ʽ������,fscanf�����ո�ͻ���ʱ������ע��ո�ʱҲ����������fgets������fgets�����ո񲻽���������ֵ�����ͣ��ɹ����ض���Ĳ����ĸ�����ʧ�ܷ���EOF(-1)��

	
	//size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
	//��������Զ�������ʽ���ļ����в��������������ı��ļ�
	//����ֵ������ʵ��д������ݿ���Ŀ
	//	��1��buffer����һ��ָ�룬��fwrite��˵����Ҫ��ȡ���ݵĵ�ַ��
	//	��2��size��Ҫд�����ݵĵ��ֽ�����
	//	��3��count : Ҫ����д��size�ֽڵ�������ĸ�����
	//	��4��stream : Ŀ���ļ�ָ�룻
	//	��5������ʵ��д������������count��
	//	˵����д�뵽�ļ������ ������ļ��Ĵ�ģʽ�йأ������w + �����Ǵ�file pointerָ��ĵ�ַ��ʼд���滻��֮������ݣ��ļ��ĳ��ȿ��Բ��䣬stream��λ���ƶ�count�����������a + ������ļ���ĩβ��ʼ��ӣ��ļ����ȼӴ�
	//	fseek�Դ˺��������ã�����fwrite[1]  ����д���û��ռ仺��������δͬ�����ļ��У������޸ĺ�Ҫ���ڴ����ļ�ͬ��������fflush��FILE *fp������ͬ����


	//size_t fread ( void *buffer, size_t size, size_t count, FILE *stream) ;
	//�� ��
	//	buffer
	//	���ڽ������ݵ��ڴ��ַ
	//	size
	//	Ҫ����ÿ����������ֽ�������λ���ֽ�
	//	count
	//	Ҫ��count�������ÿ��������size���ֽ�.
	//	stream
	//	������
	//	����ֵ
	//	ʵ�ʶ�ȡ��Ԫ�ظ������������ֵ��count����ͬ��������ļ���β�������󡣴�ferror��feof��ȡ������Ϣ�����Ƿ񵽴��ļ���β����

	system("pause");
	return 0;
}



void main6() {
	//fclose()���ļ�ָ���Ӱ��

	FILE* fp = fopen("D:/test2.txt", "w");

	printf("%p", fp);

	fclose(fp);

	printf("%p", fp);

	fp = fopen("D:/test2.txt", "w");

	printf("%p", fp);

	system("pause");


}

void main5() {
	//�����о�����feof()����

	//����wtд��ʱ,rb��ȡ����\r\n��1310,rt��ȡ����\n,��10,���ı��ļ������ǻ��е�
	//����wbд��ʱ,rb��rt��ȡ�Ķ���\n�����ı��ļ��򿪲�����
	//w��wt��Ч��һ��

	//FILE* fp = fopen("D:/test2.txt", "w");

	//int num = fprintf(fp, "%s\n%s", "test1","test2");
	


	FILE* fp = fopen("D:/test2.txt", "rb");
	printf("%p", fp);
	while (!feof(fp)) {
		//printf("fp1=%d,", feof(fp));

		char ch = fgetc(fp);
		/*putchar(ch);*/

		//fgetc()���ò�������statementֵ,��ȡ��ĩβ��ʱ��(Ӧ����ĩβ����һ��),��õ�-1,������statementֵΪ1,fp2�ͻ����1;�ڴ�֮ǰstatement��ֵ����0,��feof(fp)��ֵ����0
		//����-1���ӡΪ�ո�

	/*	if (ch == -1) {
			printf("%c", ch);
		}
*/
		printf("%d ", ch);

		//printf("fp2=%d,", feof(fp));

	}

	system("pause");

	/*��feof(FILE *)����EOF��־������Ϊ�ļ������ˣ����ɷ���0��ֱ������EOF����һ���ַ��ŷ���1����ʱ����Ϊ���ļ�������

		�������while(!feof(fp))Ϊѭ��������ʱ��Ҫ��һ���ļ�(fp)��ȫ���Ƶ���һ���ļ�(fp1), ��Ҫ�����ж�if(ch != -1), ����:


	while (!feof(in))
	{
		ch = fgetc(in);
		if (ch != -1)
			fputc(ch, out);

	}*/

	//��C�����Եġ�feof()�����������ݿ��С�eof()����������������ȫ��ͬ�ġ����ݿ��С�eof()��������ȡ��ǰָ���λ�ã�
	//	��C�����Եġ�feof()���������ص������һ�Ρ������������ݡ����������ѡ�λ�ú����ݡ���죬�Ӷ�����˶���һ��������Ƕ��ǡ�
	//(����feof()λ���ڽ�����־(EOF)��ʱ��,"������������"�����ǽ�����־,��Ȼ�᷵��1,)
	//(��Ϊfeofֻ�Ƿ���ϵͳ��һ��statment��ֵ������Ҫfgetc fgets fread�ȵ�ϵͳ�����޸ĵġ�
		//fseek(fp, 0, SEEK_END)���ļ�ָ��ָ��size, �����ʱfeof(fp)�Ļ����ǲ��᷵�ط�0�ģ�ԭ����Ǹ���û��ϵͳ���øı����Ǹ�statment��ֵ�����Ի��Ƿ���0��
		//������������ж�ֱ��fgetc�Ļ����ͻ���һ�� - 1, ��ȻҲ��Ϊ��� - 1ϵͳ�ı���statment��ֵ������
		//��fseek(fp, 0, SEEK_END)Ȼ��fgetc����֮���ٵ���feof��ʱ��ͻ᷵�ط�0)
	//	��ô��λ�ú����ݵ����кβ�ͬ�أ��ٸ��򵥵����ӣ���������˵�����ߵ��𳵵����һ�ڳ��䡱�����λ�á�
	//	�����˵������һֱ����ߣ����������������������ݡ�Ҳ����˵���������жϻᡰ����һ�ڡ����������ȫ�����ڡ�while(!feof(FP)) { ... }�������ļ�����ʱ��
	//	Ŀ���ĵ��ܻ��Դ�ĵ������һЩ����ԭ��

	//EOF����-1

	//ascii���У�����С�� 0x20 �ģ� ����ӡ�������Ķ��ǡ��հס������� 0x7E����ӡ��������Ҳ�ǡ��հס��� - 1 �����룬���� 0x7E�����ԡ���ӡ���������ǿհס�
}

void main4() {
	//�����о�����wt��wb,rt��rb������

	//����wtд��ʱ,rb��ȡ����\r\n��1310,rt��ȡ����\n,��10,���ı��ļ������ǻ��е�
	//����wbд��ʱ,rb��rt��ȡ�Ķ���\n�����ı��ļ��򿪲�����


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
	//�����о�����fclose()������

	FILE* fp = fopen("D:\\test.txt", "w");//ע��at��wtд�������,w��wt��Ч��һ��
	//FILE* fp = fopen("D:\\test.txt", "at+");//ע��at��wtд�������

	/*while (!feof(fp)) {

		char ch = fgetc(fp);
		putchar(ch);

	}*/
	/*rewind(fp);*/

	int a = fprintf(fp, "%s\n", "this is the first example for testing file writing.");
	//д�뵽fp����%s\n123
	//��wtʱ,Windows��\n��ת��Ϊ\r\nд��,��ʱ��test.txt�ǻ��е�,��rt+/rb+�򿪶�ȡʱ�ǻ��е�,����ĩβ���к���һ���ո�
	//��wbʱ,Windowsxia\n������\n�Ķ�����д��,��ʱ��test.txt�ǲ����е�,��rt+/rb+�򿪶�ȡ�ǻ��е�.����ĩβ���к���һ���ո�

	//����д���ʱ��,����sentence����successfully��,��˵������wt����wb�ڻ�������ʱ����\n,д�뵽�ļ���ʱ���ת��Ϊ\r\n


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
	//���fclose()1û��,����ᵼ��second�Ǿ�û��д�뵽test��,Ϊʲô?���fp��·��Ϊtestt.txt��ʱ��,second�����ͻ�д�뵽testt.txt��
	//����,�����һ��fopen()�Ĵ򿪷�ʽ��wt��Ϊat�Ļ�,second����д���test��,��second�������first����ǰ��

	//����,ԭ���ǵ���һ���򿪷�ʽ��wt��û��fclose()1��ʱ��,fp�ض�����at��fopen(),���û��û��fclose()2���˳��д�뵽test.txt��
	//�����fclose()2,����ᵼ���Ƚ�second���ˢ�뵽test.txt��,Ȼ����wt��,��Ĩ������,ˢ��first�ľ���.

	//���Ե���fclose()1,first,second���Ӷ��ᰴ˳��ˢ�뵽test.txt,
		//this is the first example for testing file writing.
		//this is the second example for testing file writing.


	
	//��wt��Ϊat��ʱ�����secondˢ���ˢ��first�ľ���
		//this is the second example for testing file writing.
		//this is the first example for testing file writing.

	//ֻ��fclose()1��ʱ���ִ�н����û��fcloseһ��

	//û��fclose()1��û��fclose()2��ʱ��,Ϊʲôfirst��second�ľ��ӻ�˳��ˢ�뵽test.txt��?
	//���رճ����ʱ������ôˢ�»�������?
	//����һ���򿪷�ʽΪwt�ڶ�����ʽΪat��ʱ��,�����ǰ�˳��ˢ���(��ԭ�����ݱ�Ĩ����)
	//����һ���򿪷�ʽΪat�ڶ����򿪷�ʽΪwt��ʱ��,ֻ��second�ľ���
	//������û��fclose()�������,ˢ��ķ�ʽ����ִ�е�һ���򿪷�ʽ,��ִ�еڶ����򿪷�ʽˢ������
	
	//printf("%d\n", res);
	system("pause");

}

void main2() {
	FILE* fp = fopen("D:\\test.txt", "wb+");//ע��wt��wbд�������

	while (!feof(fp)) {

		char ch = fgetc(fp);
		putchar(ch);
	
	}
	/*rewind(fp);*/

	//int a = fprintf(fp, "%s\n123", "this is the first example for testing file writing.");
	//д�뵽fp����%s\n123
	//��wtʱ,Windows��\n��ת��Ϊ\r\nд��,��ʱ��test.txt�ǻ��е�,��rt+/rb+�򿪶�ȡʱ�ǻ��е�,����ĩβ���к���һ���ո�
	//��wbʱ,Windowsxia\n������\n�Ķ�����д��,��ʱ��test.txt�ǲ����е�,��rt+/rb+�򿪶�ȡ�ǻ��е�.����ĩβ���к���һ���ո�

	//����д���ʱ��,����sentence����successfully��,��˵������wt����wb�ڻ�������ʱ����\n,д�뵽�ļ���ʱ���ת��Ϊ\r\n


	//printf("%d\n", a);

	//if (a == strlen("this is the first example for testing file writing.\n123"))
	//	printf("%s\n", "the sentence is written into the file successfully.");

	//fp = fopen("D:\\test.txt", "at+");
	//a = fprintf(fp, "%s\n", "this is the second example for testing file writing.");

	//printf("%d\n", a);

	//if (a == strlen("this is the second example for testing file writing.\n"))
	//	printf("%s\n", "the sentence is written into the file successfully.");


	//fclose(fp);
	//fclose();����ᵼ��second�Ǿ�û��д�뵽test��,Ϊʲô?

	system("pause");

}

void main1() {

	FILE* fp = fopen("D:\\test.txt", "wt+");//ע��wt��wbд�������

	//while (!feof(fp)) {

	//	char ch = fgetc(fp);
	//	putchar(ch);
	//
	//}
	//rewind(fp);

	int a = fprintf(fp, "%s\n123", "this is the first example for testing file writing.");//д�뵽fp����%s\n123
	//��wtʱ,Windows��\n��ת��Ϊ\r\nд��,
	//��wbʱ,Windowsxia\n������\n�Ķ�����д��

	


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
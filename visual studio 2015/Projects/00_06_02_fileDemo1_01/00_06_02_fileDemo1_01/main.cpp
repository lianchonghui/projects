#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<io.h>

#include<errno.h>
#include<string.h>

int main() {

	//�ļ����ݿ����:fwrite(),fread();
	
	//1.����fwrite(),fread()����Ҫ��һ��������,������
	//2.ÿ��Ԫ�صĳ���
	//3.�ܹ�����Ԫ��(��������Ԫ�صĸ���)
	//4.�ļ�ָ��

	FILE * pf = fopen("D:/2.txt", "w+");

	if (pf == NULL) {
		printf("�ļ���ʧ��!");
	}
	else {

	//����д�뻺����,��д������
	double db[10] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };

	//д��
	fwrite(db, sizeof(double), 10, pf);


	//������ȡ������,����ʼ��
	double dbr[10] = { 0 };

	//�ļ�ָ��ص��ļ���ͷ
	rewind(pf);

	fread(dbr, sizeof(double), 10, pf);//���ļ�ͨ��pfָ���ȡ�洢��������

	//��������������
	for (int i = 0;i < 10;i++) {
		printf("%fl ", dbr[i]);
	}
	printf("\n");
	
	fclose(pf);//fclose()�������ǹر���,ͬʱpf=null,��delete()ָ���Ժ��Ҫ��ֵNULL
	//pf = NULL;

	}
	

	system("pause");
	return 0;
}



int main8() {
	//Windows���������޻���ģʽ����(û������ʵ�������ֽڻ���)


	system("pause");
	return 0;
}




int main7() {

	//�ļ���λ:ftell��fseek()
	//ftell()���ڻ�ȡָ��λ�����ļ���ͷ�ĵ��ֽ���
	//fseek()���ڶ�λ�ļ�ָ���λ��

	FILE * pf = fopen("D:/1.txt", "a+");//������a���ļ�,�����w�򿪻�Ĩ��ԭ��������

	if (pf == NULL) {
		printf("�ļ���ʧ��\n");
	}
	else {
		printf("�ļ��򿪳ɹ�\n");
	
	int length = ftell(pf);
	printf("fseekǰ�ļ��ַ�������:%d\n", length);//ָ��һ��ʼָ���ļ���ͷ,��ָ��ָ���ļ�ĩβ�Ժ����ͳ���ַ�(�ֽ�)��

	//fseek(pf, 0, SEEK_END);
	fseek(pf, 0, 2);
	//2 SEEK_END
	//0 SEEK_SET �ȼ���rewind(),//�ļ��ص���ͷ,ָ��ص���ʼλ��//fflush()��Ի�����,ָ��ᵽ��ʼλ��   �ļ�>���򻺳���
	//1 SEEK_CUR

	length = ftell(pf);

	printf("fseek���ļ��ַ�������:%d\n", length);

	fputs("\n//�Ҳ�����һ������", pf);//������һ���ַ�����,ָ��λ��������ƶ�����ַ������ȵĴ�С
	//�����һ��\n�ַ�Ҫ��ﵽ���е�Ŀ��,��Ҫ��a����at�ķ�ʽ���ļ�,ab��ʽ�򿪲�����,Ҳû�ո�

	//rewind(pf);
	length = ftell(pf);
	printf("��ĩβ������һ�����ֺ���ļ��ַ�������:%d\n", length);

	fclose(pf);
	//pf = NULL;

	}

	system("pause");
	return 0;
}



int main6() {

	//���������Ϣ:perror/ferror/clearerr/strerr

	//�ڿ⺯�����и�errno������ÿ��errnoֵ��Ӧ�����ַ�����ʾ�Ĵ������͡��������"ĳЩ"��������ʱ���ú����Ѿ�����������errno��ֵ��perror����ֻ�ǽ��������һЩ��Ϣ�����ڵ�errno����Ӧ�Ĵ���һ�������

	

	//1.strerr��׼���(�豸)�ļ�����Ӧ�ն˵���Ļ�����̽��ӱ�׼�����ļ��еõ��������ݣ���������������������׼����ļ�������������Ϣ�͵���׼�����ļ��С���C�У�����ִ��ʱ��һֱ���ڿ���״̬��
	
	//2.perror(s) ��������һ���������������ԭ���������׼�豸(stderr)������ s ��ָ���ַ������ȴ�ӡ���������ټ��ϴ���ԭ���ַ������˴���ԭ������ȫ�ֱ���errno(�����˵����׼ȷ,errno��һ����,�ú귵����ֵ) ��ֵ������Ҫ������ַ�����
	//perror��strerror����C�����ṩ�Ŀ⺯�������ڻ�ȡ��errno��صĴ�����Ϣ�����𲻴��÷�Ҳ�򵥡�������������perror��stderr���������� strerror��stdout��������
	
	//3.ferror�����������ڵ��ø������������������ putc.getc.fread.fwrite�ȣ�ʱ��������ִ��󣬳��˺�������ֵ������ӳ�⣬��������ferror������顣 
	//����һ�������ʽΪ ferror(fp)�����ferror����ֵΪ0���٣�����ʾδ�����������һ������ֵ����ʾ����Ӧ��ע�⣬��ͬһ���ļ� ÿһ�ε����������������
	//������һ���µ�ferror�� ��ֵ����ˣ�Ӧ���ڵ���һ��������������������� ��ferror������ֵ��������Ϣ�ᶪʧ����ִ��fopen����ʱ��ferror�����ĳ�ʼֵ�Զ���Ϊ0��
	
	//4.clearerr��������ʹ�ļ������־���ļ�������־��Ϊ0.�����ڵ���һ�������������ʱ�����˴���ferror����ֵΪһ������ֵ���ڵ���clearerr��fp����ferror��fp����ֵ��Ϊ0��
	//ֻҪ���ִ����־����һֱ������ֱ����ͬһ�ļ�����clearerr������rewind���������κ�һ���������������



	//FILE *pf = fopen("D:/1.txt", "r");
	//printf("%d\n", ferror(pf));//ferror()������������������(getc(),putc(),fread(),fwrite()��)�Ƿ����

	FILE *pf = fopen("D:/1.txt", "w");
	if (pf == NULL) {
	//if (!ferror(pf)) {
		fprintf(stderr, strerror(errno));
		printf("w��ʽ���ļ�ʧ��.\n");
		perror("����Ĵ�����ABC");//�������  ����Ĵ�����ABC:������Ϣ
		printf("strerror:%s\n", strerror(errno));//strerror��string.h�ж���
		//errno �Ǽ�¼ϵͳ�����һ�δ�����롣������һ��int�͵�ֵ����errno.h�ж���
		
		//clearerr(pf);

		//perror("������:");
		
		//ferror(pf);

	}



	system("pause");
	return 0;
}





int main5() {

	//fscanf()��ע������
	//ע��:fscanf()�Ķ�ȡһ��Ҫ��fprintf()��Ӧ(ʵ�ʸ�ʽ),�����޷���ȷ��ȡ


	system("pause");
	return 0;
}






int main4() {

	//_access����,io.h�ж���
	//0 �ļ��Ƿ񲻴���,����0�ļ�����,���ڷ���-1
	//2 �ļ��Ƿ񲻿�д,����0�ļ���д
	//4 �ļ��Ƿ񲻿ɶ�,����0�ļ��ɶ�
	//6 �ļ��Ƿ񲻿ɶ�����д,����0�ļ��ɶ���д

	//FILE *pf = fopen("D:/1.txt", "w");

	printf("%d\n", _access("D:\\1.txt", 0));

	if (_access("D:/1.txt", 0)) {
		printf("�ļ�������\n");
	}
	else {
		printf("�ļ�����\n");
	}
	



	system("pause");
	return 0;
}



int mian3() {

	//fflush()��rewind()





	system("pause");
	return 0;
}


int main2() {
	//�ļ��ͽṹ��
	char ch;
	//printf("����������Ч������%d\n",stdin->_cnt);



	system("pause");
	return 0;
}


int main1() {
	//_getw(),_putw()����

	int w = _getw(stdin);//�Ӽ��̻�ȡ�����ĸ��ֽ�

	_putw(w, stdout);//��ʾ�����


	//��������:123456�س���   ��ӡ����:1234
	//��������:123�س���      ��ӡ����:123����
	//��������:12�س�34       ��ӡ����:12����3
	//��������:�Ұ���         ��ӡ����:�Ұ�
	//��������:�һس�����     ��ӡ����:�һ���

	printf("-----------------------------\n");

	putchar(97);
	putchar(97);
	putchar(97);
	putchar(97);
	putchar('\n');

	int num = _putw(97, stdout);//�������һ���ַ�,�������Ļᵱ�����ַ�����

	//_putw(97, stdout);//�������һ���ַ�,�������Ļᵱ�����ַ�����

	printf("\n num=%d", num);//ͨ��num���Կ���,_putw()�������num=97


	system("pause");

	return 0;
}
#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fenge(char path[],char filename[]) {
	//�ָ��ļ�

	//�ָ��ļ�����
	//1.�������ָ��ļ�ָ��
	//2.�����ָ����ļ���¼�ļ�·��
	//3.����д����ļ�ָ��

	//ͨ�������õ�Ҫ�ָ��ļ���·��filepath
	char filepath[100];
	sprintf(filepath, "%s/%s", path, filename);

	//ʹ��rb��ʽ�򿪷ָ��ļ�,�����ָ��ļ���ָ��pathp
	FILE * pathp = fopen(filepath,"rb");

	if (pathp == NULL) {
		printf("�ļ���ʧ��!");
	}
	else {

		//������¼�ָ��б���־��·��
		char listpath[100] = { 0 };
		sprintf(listpath, "%s/list.txt", path);
		FILE * listp = fopen(listpath, "wt");

		//����ļ���С
		fseek(pathp, 0, 2);
		int length = ftell(pathp);
		printf("%d\n", length);
		rewind(pathp);

		//���ļ���ȷ�,�õ�ÿ�ݴ�Сnewlength
		int newlength = length / 5;
		
		//�����洢�ָ���ļ���·��������newpath���ļ�ָ��newpathp
		char newpath[100] = { 0 };
		FILE * newpathp = NULL;

		for (int i = 1;i <= 5;i++) {
			//�����ָ���ļ���·�����ļ�ָ��
			sprintf(newpath, "%s/%d%s", path, i, filename);
			fputs(newpath, listp);
			fputc('\n',listp);//��־��¼һ���ָ��ļ�·������

			//ָ���ļ�ָ��λ��
			//fseek(pathp, newlength*(i-1), 0);
			int tlength = ftell(pathp);
			printf("%d\n", tlength);

			//��wb��ʽ�򿪷ָ�õ����ļ�·����ָ��newpathp
			newpathp = fopen(newpath, "wb");
			
			//�ֽ�ѭ����pathp�ж�ȡ��д�뵽newpathp��
			for (int j = 0;j < newlength;j++){
			
				int ich = fgetc(pathp);

				fputc(ich, newpathp);

			}

			//rewind(pathp);//ÿ�ηָ��Ժ��ļ�ָ��ص���ʼλ��//��߿����Ż�,ֻҪʡ���ϱ�ָ���ļ�ָ��λ�þ�ok

		}
		
		fclose(listp);
		fclose(pathp);
		fclose(newpathp);


	}
}

void hebing(char list[]) {

	FILE * listp = fopen(list, "r");
	FILE * newfilew = fopen("D:/1/newfile.mp4","wb");

	char temppath[200];
	/*while (fgets(temppath, 200, listp)) {
		printf("%s", temppath);
	}*/

	while (fgets(temppath, 200, listp)) {
		printf("%s", temppath);

		//��ȡÿ�ж�ȡ���ַ�������
		//fgets()��ÿ���������з���????
		int length = strlen(temppath);
		printf("%d\n", length);

		temppath[length - 1] = '\0';//���з��滻Ϊ'\0'

		FILE * newfilep = fopen(temppath, "rb");

		int ich = fgetc(newfilep);
		while (!feof(newfilep)) {//��ָ��ָ��EOF��ʱ��,feof����ֵ����0,������fgetc(),ָ����ǰһ��,feof()����-1
			fputc(ich, newfilew);
			ich = fgetc(newfilep);

		}





	}

		fclose(listp);
		fclose(newfilew);


}



int main() {


	char path[100] = "D:/1";
	char filename[100] = "1.mp4";
	//fenge(path,filename);
	char list[100] = "D:/1/list.txt";

	hebing(list);
	system("pause");
	return 0;
}
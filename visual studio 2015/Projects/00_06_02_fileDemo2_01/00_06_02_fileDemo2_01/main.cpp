#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fenge(char path[],char filename[]) {
	//分割文件

	//分割文件步骤
	//1.创建被分割文件指针
	//2.创建分割后的文件记录文件路径
	//3.创建写入的文件指针

	//通过参数得到要分割文件的路径filepath
	char filepath[100];
	sprintf(filepath, "%s/%s", path, filename);

	//使用rb方式打开分割文件,穿件分割文件的指针pathp
	FILE * pathp = fopen(filepath,"rb");

	if (pathp == NULL) {
		printf("文件打开失败!");
	}
	else {

		//创建记录分割列表日志的路径
		char listpath[100] = { 0 };
		sprintf(listpath, "%s/list.txt", path);
		FILE * listp = fopen(listpath, "wt");

		//检查文件大小
		fseek(pathp, 0, 2);
		int length = ftell(pathp);
		printf("%d\n", length);
		rewind(pathp);

		//将文件五等分,得到每份大小newlength
		int newlength = length / 5;
		
		//创建存储分割后文件的路径的数组newpath和文件指针newpathp
		char newpath[100] = { 0 };
		FILE * newpathp = NULL;

		for (int i = 1;i <= 5;i++) {
			//创建分割后文件的路径和文件指针
			sprintf(newpath, "%s/%d%s", path, i, filename);
			fputs(newpath, listp);
			fputc('\n',listp);//日志记录一个分割文件路径后换行

			//指定文件指针位置
			//fseek(pathp, newlength*(i-1), 0);
			int tlength = ftell(pathp);
			printf("%d\n", tlength);

			//以wb方式打开分割得到的文件路径的指针newpathp
			newpathp = fopen(newpath, "wb");
			
			//字节循环从pathp中读取和写入到newpathp中
			for (int j = 0;j < newlength;j++){
			
				int ich = fgetc(pathp);

				fputc(ich, newpathp);

			}

			//rewind(pathp);//每次分割以后文件指针回到起始位置//这边可以优化,只要省略上边指针文件指针位置就ok

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

		//获取每行读取的字符串长度
		//fgets()是每次遇到换行符就????
		int length = strlen(temppath);
		printf("%d\n", length);

		temppath[length - 1] = '\0';//换行符替换为'\0'

		FILE * newfilep = fopen(temppath, "rb");

		int ich = fgetc(newfilep);
		while (!feof(newfilep)) {//当指针指向EOF的时候,feof返回值还是0,当下面fgetc(),指针向前一步,feof()返回-1
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
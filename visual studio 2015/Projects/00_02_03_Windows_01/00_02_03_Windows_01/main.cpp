#include<Windows.h>
#include<stdlib.h>

//SHELL EXECUTE����˵��
//ShellExecute(0, "open", "http://www.csdn.net", 0, 0, 1);
//��һ��������ָʾ�Ǹ�����ִ�еģ�0����ϵͳִ�еģ��ڶ�����������ִ��ʲô������
//һ������£�ֻ�С�open��, ��print��, ��������������ִ�е��ļ�·���������ƻ�����ַ�������ʼ���ַ�����ĸ��������������ϵͳ������һЩ������������Ϊ0��
//���һ�������ǿ��ƴ򿪵Ĵ�����ʾ�����أ���󻯣���С�������һ�㲻��ʲô���ã���Щʱ�������󻯣���С�������أ���ʾ�ȵȡ�

void main() {

	//MessageBox�ǵ����Ի���,0��ʾ��ϵͳ����,���һ��������ʾ�Ի�������,
	//MessageBox(0, "����:helloworld!", "����:hello", 6);

	//ShellExecute(0, "open", "http://www.baidu.com", 0, 0, 1);
	//ShellExecute(0, "open", "D:\\CMD.txt",0,0,1);
	
	//ShellExecute(0, "print", "D:\\CMD.txt", 0, 0, 1);
	
	//ShellExecute(0, "open", "C:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe",0,0,1);

	ShellExecute(0, "open", "mailto_lianglumia@live.com", 0, 0, 1);
	
}
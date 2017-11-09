#include<Windows.h>
#include<stdlib.h>

//SHELL EXECUTE参数说明
//ShellExecute(0, "open", "http://www.csdn.net", 0, 0, 1);
//第一个参数，指示那个窗口执行的，0就是系统执行的，第二个参数就是执行什么操作，
//一般情况下，只有”open”, ”print”, 第三个参数就是执行的文件路径或者名称或者网址，或者邮件地址，第四个，第五个，都是系统保留的一些参数，都设置为0，
//最后一个参数是控制打开的窗口显示，隐藏，最大化，最小化，这个一般不起到什么作用，有些时候控制最大化，最小化，隐藏，显示等等。

void main() {

	//MessageBox是弹出对话框,0表示由系统弹出,最后一个参数表示对话框类型,
	//MessageBox(0, "内容:helloworld!", "标题:hello", 6);

	//ShellExecute(0, "open", "http://www.baidu.com", 0, 0, 1);
	//ShellExecute(0, "open", "D:\\CMD.txt",0,0,1);
	
	//ShellExecute(0, "print", "D:\\CMD.txt", 0, 0, 1);
	
	//ShellExecute(0, "open", "C:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe",0,0,1);

	ShellExecute(0, "open", "mailto_lianglumia@live.com", 0, 0, 1);
	
}
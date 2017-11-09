//system属于lib函数库,所以要引入stdlib头文件
#include<stdlib.h>

void main() {

	//system("ipconfig");
	//system("pause");

	//system("notepad");

	//打开计算机管理
	//system("compmgmt.msc");

	//注意(x86)前一定要有空格(64位系统默认),注意"和\的转义,注意有空格的地址有用引号括起来
	system("\"C\:\\Program Files\\Internet Explorer\\iexplore.exe\" http://www.baidu.com");

}
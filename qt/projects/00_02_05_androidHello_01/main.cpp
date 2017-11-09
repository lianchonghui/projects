#include "mainwindow.h"
#include <QApplication>
#include<Android/log.h>  //调用日志输出函数

int main()
{
    _android_log_print(ANDROID_LOG_DEBUG, "itcast","hello world  hello yincheng ");  //输出调试信息


    return 1;
}

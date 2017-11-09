#!/usr/bin/env python
# -*- coding:utf-8 -*-


'''
    1.class定义是动态创建的，而创建class的方法本质使用type()函数
    2.python解释器遇到calss定义时，仅仅扫描下class定义的语法，然后调用type()函数创建class
    
    3.type()函数依次传入的三个参数
        1）calss的名称
        2）继承的父类集合tuple（注意tuple的单元素写法）
        3）class的方法名称与函数绑定：方法名=函数名


'''

def main():
    h=Hello()
    h.hello()



def fn(self,name='world'):
    print ('Hello,%s.' % name)

Hello=type('Hello',(object,),dict(hello=fn))



if __name__=='__main__':
    main()
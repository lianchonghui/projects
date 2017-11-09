#!/usr/bin/env python
# -*- coding:utf-8 -*-

# 注意import一般放在代码开始的最顶端
import sys

' a test module'

__author__ = 'Taro Lian'


def main():
    print_module()


def print_module():
    # 这里使用了sys模块的argv，当我们在别的py文件导入这个模块从外部传入的变量
    # 如python m_module_demo.py lcx，argv就是lcx了
    args = sys.argv

    if len(args) == 1:

        # print __author__
        print 'hello python'
    elif len(args) == 2:
        # print __author__
        print 'hello,%s!' % args[1]
    else:
        print 'Too many arguments'


if __name__ == '__main__':
    main()

#!/usr/bin/env python
# -*- coding:utf-8 -*-

import functools


def main():

    # int把字符串转化为整数，默认是十进制转换，返回值都是十进制
    int2=functools.partial(int,base=2)
    print int2('1000000')

    print int2('1010101')




if __name__=='__main__':
    main()
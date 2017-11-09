#!/usr/bin/env python
# -*- coding:utf-8 -*-

# python中的可变参数 *args,**kwargs
# *args 表示的是tuple,在函数参数中可以节后没有()的tuple
# *kwargs 表示dict,在函数参数中是没有{}的dict
# 如果存在tuple有*args,dict有**kwargs,可以传入实际参数*args,**kwargs


def main():
    foo(1, 2, 3)
    foo(a=1, b=2, c=3)
    foo(1, 2, 3, a=1, b=2, c=3)
    foo(1, 'b', 'c', a=1, b='b', c='c')


def foo(*args, **kwargs):
    print 'args=', args
    print 'kwargs=', kwargs
    print '-' * 20


if __name__ == '__main__':
    main()

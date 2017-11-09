#!/usr/bin/env python
# -*- coding:utf-8 -*-

'''
    1.python异常捕获语法
        try:
            pass
        except 错误对象名，e:
            # logging.exception(e) #如果记录日志
            # raise # 如果继续往上抛出
            # raise 异常名 # 如果想改变异常类型，可以向上抛出你想要抛出的异常
        finally:
            pass
    
    2.异常的抛出会调用堆栈一层一层往上抛
    3.异常向上抛出的过程可以改变异常的类型：raise 其他异常
    4.

'''


import logging


def main():
    try:
        show(1)
    except ValueError, e:
        print 'welcome to valueeError'
        print e # e 需要上一层给出，否则为''
    except StandardError,e:
        print 'welcome to main standarError'
        print e # 如果上一层只是raise，会自动传递e过来
    finally:
        print '-' * 20


def foo(s):
    n = int(s)

    if n == 1:
        raise FooError('invalid value:%s' % s)


def show(s):
    try:
        return foo(s) * 2

    except FooError, e:
        print 'welcome show FooError'
        print '-----------------记录日志--------------------'
        logging.exception(e)
        print '-----------------记录结束--------------------'
        raise
        #raise ValueError(e)  # 向上抛出异常的过程可以改变异常类型
    except StandardError, e:
        print 'welcome show standardError'
        logging.exception(e)
        raise
    finally:
        print 'finall...'


# 自定义异常类

class FooError(StandardError):
    print 'welcome to FooError'


if __name__ == '__main__':
    main()

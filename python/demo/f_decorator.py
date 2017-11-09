#!/usr/bin/env python
# -*-coding:utf-8-*-

import functools


def main():
    now()
    print 'now.__name__:', now.__name__  # wrapper
    print '-' * 20
    # now=log(now)
    # now()

    now2()
    # now=log('execute')(now)
    print 'now2.__name__:', now2.__name__  # wrapper

    # now.__name__的函数签名被改变了，有些以来函数签名的代码执行就会出错
    # 不要使用wrapper.__name__ = func.__name__
    # 可以使用python内置的代码functools.wraps
    # import functools
    print '-' * 20
    now3()
    print 'now3.__name__:', now3.__name__
    print '-' * 20
    now4()
    print 'now4.__name__:', now4.__name__


def log3(func):
    @functools.wraps(func)
    def wrapper(*args, **kw):
        print 'call %s():' % func.__name__
        return func(*args, **kw)
    return wrapper


def log4(text):
    def decorator(func):
        @functools.wraps(func)
        def wrapper(*args, **kw):
            print '%s %s():' % (text, func.__name__)
            return func(*args, **kw)
        return wrapper
    return decorator


@log3
def now3():
    print '2016-09-15'


@log4('execute')
def now4():
    print '2016-09-15'


def log(func):
    def wrapper(*args, **kw):
        print 'call %s():' % func.__name__
        return func(*args, **kw)
    return wrapper


@log
def now():
    print '2016-09-15'


def log2(text):
    def decorator(func):
        def wrapper(*args, **kw):
            print '%s %s():' % (text, func.__name__)
            return func(*args, **kw)
        return wrapper
    return decorator


@log2('execute')
def now2():
    print '2016-09-15'


if __name__ == '__main__':
    main()

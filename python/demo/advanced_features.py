#!/usr/bin/env python
#-*- coding:utf-8 -*-

from collections import Iterable
import os


def main():
    slice_demo()
    print '-' * 20
    iterator_demo_dict()
    print '-' * 20
    iterator_demo()
    print '-' * 20
    iterator_demo_iterable()
    print '-' * 20
    index_loop_demo()
    print '-' * 20
    list_generator_demo()
    print '-' * 20
    generator_demo()
    print '-' * 20
    generator_fun_loop()

# 切片


def slice_demo():
    L = [1, 2, 3, 4, 5, 6, 7, 8]
    print 'L:', L
    print '[0:3]:', L[0:3]
    print '[:4]:', L[:4]
    print '[2:5]:', L[2:5]
    print '[-2:]:', L[-2:]
    print '[:7:2]', L[:7:2]
    print '[:]', L[:]

    print '-' * 20

    str = 'ABCDEFGH'
    print 'str:', str
    print '[0:3]:', str[0:3]
    print '[:4]:', str[:4]
    print '[2:5]:', str[2:5]
    print '[-2:]:', str[-2:]
    print '[:7:2]', str[:7:2]
    print '[:]', str[:]

# dict的迭代


def iterator_demo_dict():
    d = {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5}
    # 注意:dict在存储的时候是无序的。
    print 'd:', d

    for key in d:
        print 'key:', key
        print 'd[key]:', d[key]

    print '-' * 10

    for value in d.itervalues():
        print 'values:', value

    print '-' * 10

    for item in d.iteritems():
        print 'key&values', item

    print '-' * 10

    for k, v in d.iteritems():
        print 'key:', k
        print 'value:', v

# 迭代


def iterator_demo():
    for ch in 'abcdefg':
        print ch

    print '-' * 10

    for i in range(10):
        print i

# 可迭代的判断


def iterator_demo_iterable():
    print 'abc:', isinstance('abc', Iterable)
    print '[1,2,3]:', isinstance([1, 2, 3], Iterable)
    print 'init:123', isinstance(123, Iterable)

# 下标循环


def index_loop_demo():
    for i, value in enumerate(['a', 'b', 'c']):
        print i, value
    for arr in enumerate(['a', 'b', 'c', 'd']):
        print 'arr:', arr
        # print 'arr[]:'arr[0],arr[1],arr[2],arr[3]
        # 注意enumerate返回的是tuple不算dict，所以以上错误。

# 列表生成式


def list_generator_demo():
    a = [x * x for x in range(1, 11)]
    b = [x * x for x in range(1, 11) if x % 2 == 0]
    c = [m + n for m in 'ABC' for n in 'XYZ']
    d = [d for d in os.listdir('.')]
    e = {'a': 'A', 'b': 'B', 'c': 'C'}
    e = [k + '=' + v for k, v in e.iteritems()]
    f = ['Hello', 'World', 'IBM', 'Python']
    f = [s.lower() for s in f]
    print a
    print b
    print c
    print d
    print e
    print f
    # return a,b

# generator
# 列表生成式是有内存限制的，假如100w个元素的列表我们仅仅访问前面几个元素


def generator_demo():
    g = (x * x for x in range(10))
    for n in g:
        print n

# 函数是生成器


def generator_fun_demo(max):
    n, a, b = 0, 0, 1
    while n < max:
        yield b  # 函数每次执行到这里暂停，当有next()以后继续
        a, b = b, a + b
        n = n + 1


def generator_fun_simple():
    print 'step 1'
    yield 1
    print 'step 2'
    yield 2
    print 'step 3'
    yield 3


def generator_fun_loop():
    gfs = generator_fun_simple()
    gfs.next()
    gfs.next()
    generator_fun_simple().next()
    generator_fun_simple().next()
    # 注意，每次generator_fun_simple.next()的调用都是从头开始执行
    # 因为这里generator_fun_simple()不是一个变量了
    # 在for循环里，generator_fun_simple()却是一个变量。
    # 注意，这里说的变量跟函数名是一个变量是不一样的意思。
    # 这里，type(gfs)是generator，type(generator_fun_simple)是function，type(fun())是generator
    # 当函数没有yield也没有return的时候gfs就是NoneType

    print '-' * 10
    for g in generator_fun_simple():
        print g

    print '-' * 10
    g = generator_fun_simple()
    for g in g:
        print g

    print '-' * 10
    for gfd in generator_fun_demo(6):
        print gfd


if __name__ == '__main__':
    main()

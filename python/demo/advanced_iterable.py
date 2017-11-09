#!/usr/env/bin python
# -*- coding:utf-8 -*-

 '''
 总结下迭代：列表（变量级）迭代，函数（生成器）迭代，实例迭代
 可迭代对象可使用for循环，next方法

    1.列表生成式：如：mylist=[x*x for x in range(1,11)]

    2.生成器：
        1)  g=(x*x for x in range(1,11))
            g.next()
            g.next()
            for n in g:
                print n
        2)  def fib(max):
                n,a,b = 0,0,1
                while n<max:
                    yield b
                    a,b = b,a+b
                    n = n + 1
            for n in fib(6):
                print n
        
    3.可迭代对象

    __iter__
        如果一个类想被用于 for ... in 循环,类似 list 或 tuple 那样,就必须实现一个 __iter__()
        方法,该方法返回一个迭代对象,然后,Python 的 for 循环就会不断调用该迭代对象的
        next() 方法拿到循环的下一个值,直到遇到 StopIteration 错误时退出循环。
        我们以斐波那契数列为例,写一个 Fib 类,可以作用于 for 循环:

        class Fib(object):
            def __init__(self):
                self.a, self.b = 0, 1 # 初始化两个计数器 a,b

            def __iter__(self):
                return self # 实例本身就是迭代对象,故返回自己

            def next(self):
                self.a, self.b = self.b, self.a + self.b # 计算下一个值
                if self.a > 100000: # 退出循环的条件
                    raise StopIteration();
                return self.a # 返回下一个值

        现在,试试把 Fib 实例作用于 for 循环:
        >>> for n in Fib():
        ...
        ...
        1
        1
        2
        print n3
        5
        ...
        46368
        75025

'''

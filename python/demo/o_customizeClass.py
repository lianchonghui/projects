#!/usr/bin/env python
# -*- coding:utf-8 -*-

'''
    1.__str__(self)
    2.__repr__(self)
    3.__iter__(self)
        对于__iter__(self)需要有一个next(self)
    4.__getitem__
    5.__getattr__
    6.__call__
    

###
    总结下迭代：列表（变量级）迭代，函数（生成器）迭代，实例迭代
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
    
'''


def main():
    s = Student("Hinata")
    print s  # 打印的是__str__()函数的返回值

    for n in s:
        print n

    print '-' * 20
    print s[0:7]

    print '-' * 20
    print s.age()
    # print s.abc

    print '-' * 20
    s()


class Student(object):

    def __init__(self, name):
        self.name = name

        self.a, self.b = 0, 1

    # 直接调用对象时返回对象的信息
    def __str__(self):
        return 'Student object (name:%s)' % self.name

    # 用与返回开发者看到的对象信息的字符串，如在ipython中直接s出现的字符串
    def __repr__(self):
        return 'Student object (name:%s)' % self.name

    # __iter__用于实现实例转化为可迭代对象 且必须有next(self)函数
    def __iter__(self):
        return self  # 实例本身就是迭代对象，故返回自己

    def next(self):
        self.a, self.b = self.b, self.a + self.b  # 轮替
        if self.a > 10000:  # 退出循环的条件
            raise StopIteration()
        return self.a

    # __getitem__(self ,n) 让类可以当作list来使用
    '''
    def __getitem__(self,n):
        a,b=1,1
        for x in range(n):
            a,b=b,a+b
        return a
    '''
    # 增加切片的处理

    def __getitem__(self, n):
        if isinstance(n, int):
            a, b = 1, 1
            for x in range(n):
                a, b = b, a + b
            return a
        if isinstance(n, slice):
            start = n.start
            stop = n.stop
            a, b = 1, 1
            L = []
            for x in range(stop):
                if x >= start:
                    L.append(a)
                a, b = b, a + b
            return L

    # __getattr__(self,attr) 动态处理一个类的所有属性和方法
    # __getattr__常用于REST API
    def __getattr__(self, attr):
        if attr == 'age':
            return lambda: 25
        raise AttributeError(
            '\'Student\' object has no attribute \'%s\'' % attr)
        # 如果没有raise异常，调用类不存在的属性和方法都会返回None

    # __call__(self) 使实例当作方法来调用
    # 如实例s可以直接通过s()就调用了__call__方法
    def __call__(self):
        print('My name is %s.' % self.name)


if __name__ == '__main__':
    main()

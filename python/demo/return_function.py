#!/usr/bin/env python
# -*- coding:utf-8 -*-


def main():
    f = lazy_sum(1, 2, 3, 4, 5)
    print f()

    print '-' * 20

    f1, f2, f3 = count()
    print f1()
    print f2()
    print f3()

    print '-' * 20

    f1, f2, f3 = count_true()
    print f1()
    print f2()
    print f3()


# 返回函数的函数
# *args中*的作用是传入tuple和list时候不用再加[]或()
def lazy_sum(*args):
    def sum():
        ax = 0
        for n in args:
            ax = ax + n
        return ax
    return sum

# 闭包：
# 1.返回函数在其内部引用了外部函数变量
# 2.当外部函数返回了内部函数以后，其内部的局部变量还被新函数引用，即接收外部函数返回的函数变量为新函数
# 3.返回的函数没有立刻执行，直到调用以后才执行

# 闭包的错误使用


def count():
    fs = []
    for i in range(1, 4):
        def f():
            return i * i
        fs.append(f)
    return fs
# 返回的函数引用了i，但它并非立刻执行，等到3个函数都返回时，它们所引用的变量i已经变成3了
# 意思就是返回的函数是f(x)=x*x,此时因为函数没有立刻执行，当返回以后才执行，只是x=3

# 修正如下


def count_true():
    fs = []
    for i in range(1, 4):
        def f(j):
            def g():
                return j * j
            return g
        fs.append(f(i))
    return fs
# 此时返回的函数是g，当返回函数的时候g也没有立刻执行，不同的是每次循环以后，传入的参数i都是固定了的
# fs中的是f(1),f(2),f(3),而上闭包的错误使用中的是i*i,i*i,i*i


if __name__ == '__main__':
    main()

#!/usr/bin/env python
# -*- coding:utf-8 -*-


def main():
    f = build(2, 3)
    print f
    # <function <lambda> at xxxx>
    print f()

    f2 = lambda x: x * x
    print f2
    print f2(2)

    # f表示的是无参数的函数
    # f2表示的是有一个参数的函数


def build(x, y):
    return lambda: x * x + y * y


if __name__ == '__main__':
    main()

#!/usr/bin/env python
# -*- coding:utf-8 -*-


def main():
    map_show()
    print '-' * 20
    reduce_show()
    print '-' * 20
    char2num_show()
    print '-' * 20
    filter_show()
    print '-' * 20
    filter_show2()
    print '-' * 20
    sorted_show()


def map_f(x):
    return x * x


def map_show():
    var = map(map_f, [1, 2, 3, 4, 5, 6, 7, 8, 9])
    print var


def reduce_f(x, y):
    return x + y


def reduce_show():
    var = reduce(reduce_f, [1, 3, 5, 7, 9])
    print var


def char2num(s):
    return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4,
            '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}[s]
    # 通过key获取字典的value


def fn(x, y):
    return x * 10 + y


def char2num_show():
    var = reduce(fn, map(char2num, '13579'))
    print var


# filter
def filter_f(n):
    return n % 2 == 1


def filter_show():
    var = filter(filter_f, [1, 2, 4, 5, 6, 8, 9])
    print var


def filter_f2(s):
    return s and s.strip()


def filter_show2():
    var = filter(filter_f2, ['A', '', 'B', None, 'C', '   '])
    print var
# 注意：空字符串’‘，None,整数0，False都为假

# sorted
# sorted的函数变量，当函数返回的是1时，x，y调换，返回-1时位置不变


def sorted_desc(x, y):
    if x > y:
        return -1
    if x < y:
        return 1
    return 0


def sorted_show():
    var = sorted([35, 23, 56, 2, 12], sorted_desc)
    print var


if __name__ == '__main__':
    main()

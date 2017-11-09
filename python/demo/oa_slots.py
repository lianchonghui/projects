#!/usr/bin/env python
# -*- coding:utf-8 -*-

# python作为动态语言可以给实例绑定任何属性和方法
# __slots__限制允许动态添加的变量(包括参数和方法)

from types import MethodType


def main():
    s = Student()

    # 实例参数的绑定
    s.name = 'Taro'
    print s.name  # Taro

    # 实例方法的绑定
    s.setAge = MethodType(setAge, s, Student)
    s.setAge(22)
    print s.age

    # 类方法的绑定(把实例参数改为None)
    Student.setScore = MethodType(setScore, None, Student)
    s.setScore(99)
    print s.score


class Student(object):
    __slots__ = ('age', 'score', 'name', 'setAge', 'setScore')

    def setHobby(self, hobby):
        self.hobby = hobby


def setAge(self, age):
    self.age = age


def setScore(self, score):
    self.score = score


if __name__ == '__main__':
    main()

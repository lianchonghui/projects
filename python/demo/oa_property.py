#!/usr/bin/env python
# -*- coding:utf-8 -*-

'''
    很多时候我们希望可以直接通过instanceName.arg来使用类的属性
    但又需要对采用get和set方法来对arg进行检验获取等
    这就可以使用@property
    对一个属性name
    @property
    def name(self):
        return _name

    @name.setter
    def name(self,value):
        self._name=value

    如上是@property的使用
    1.如果只有@property，则这个属性只读
    2.如果有@property和@xxx.setter这个属性可读可写

'''


def main():
    s = Student()
    s.birth = 2017
    print s.birth
    print s.age


class Student(object):

    @property
    def birth(self):
        return self._birth

    @birth.setter
    def birth(self, value):
        if value > 2016:
            print '你从未来穿越来的吧'
            raise ValueError('你穿越了，这个时代不属于你')
        else:
            self._birth = value

    @property
    def age(self):
        return 2016 - self._birth


if __name__ == '__main__':
    main()

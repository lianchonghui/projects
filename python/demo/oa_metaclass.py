#!/usr/bin/env python
# -*- coding:utf-8 -*-

'''
    对于面向对象，类也是一种对象，叫类对象
    python中的对象都是通过type()产生的
    而类对象是通过metaclass产生，本质上metaclass继承了type

    metaclass可以动态的根据参数创建不同的类(对象)
    如在ORM中，每行数据--每个表 映射在object是 对象-类对象
    每行数据的字段是固定的但value是不同的
    每个表也有相同的属性
    对象由类对象实例化
    类对象则由元类实例化

'''


def main():
    demo1 = MyListDemo()
    '''
        注意，上面会打印
        This is MyList
        This is MyListDemo
        说明：
            1.metaclass可以隐式继承到子类
            2.metaclass的调用顺序是：
                1）metaclass创建父类的类对象
                2）metaclass创建子类的类对象

    '''


class ListMetaclass(type):

    def __new__(cls, name, bases, attrs):
        if name == 'MyList':
            print 'This is MyList'
            return type.__new__(cls, name, bases, attrs)
        # elif name=='MyListDemo':
        print 'This is MyListDemo'
        attrs['add'] = lambda self, value: self.append(value)
        return type.__new__(cls, name, bases, attrs)
        # else:
        #    print 'else'
        #    return type.__new__(cls,name,bases,attrs)


class MyList(list):
    __metaclass__ = ListMetaclass


class MyListDemo(MyList):
    pass


if __name__ == '__main__':
    main()

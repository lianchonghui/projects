#!/usr/bin/env python
# -*- coding:utf-8 -*-

'''
1.类的声明：class o_name(super_class)
2.类可以什么都没有
3.类的构造方法为__init__(self)
4.类的实例方法需要传递一个self参数
5.类的类方法需要传递一个cls参数，且定义前有@classmethod，只能由类调用
6.类直接调用实例方法需要传递一个实例进去作为self的实际参数
7.static方法的定义前有@staticmethod
8.类的私有变量的命名方式为_name,__name__
    1) _name 只是表示其为私有变量，但是仍然可以直接引用
    2) __name 不能直接引用的私有变量，python将其转换为了_className__name变量了，可以通过这种技巧引用私有变量
9.继承和多态

10.获取对象的信息
    1) type() -- 1 arg
    2) isinstance(instanceName,className) -- 2 args ,return bool
    3) dir() -- 1 arg return a string list 获取对象的所有属性和方法

11.python的多继承和Mixin设计
    class Dog(Mammal,RunnableMixin,CarnivorousMixin):
        pass
    
    使用Mixin（功能类）来给类增加功能而不是设计多层次的复杂的继承关系

12.子类调用父类的方式：class B(A)
    A.method(self,arg)                # 1  
    super(B, self).method(arg)        # 2  
    super().method(arg)               # 3  
    方法1跟方法2的区别在于，当父类名字改变，方法一就要修改代码，方法2不用
    方法3是python3.x出现的。


注意：
1.python没有方法重载，对于参数类型，python可以接受任何参数;对于参数个数，可以使用缺省参数的办法(既然在java中需要事先声明了变量然后用方法重载来赋值，python也做到相同效果)
2.如果有重载的方法(只是这样说而已),python以最后一个加载的方法为准


'''


def main():
    s = Student('Hinata', 99)
    print s
    s.print_stu_info()
    print '-' * 20
    # s.class_func() # static_func() takes no arguments (1 given)
    # s.class_func(Student) # class_func() takes exactly 1 argument (2 given)
    s.instance_func()
    s.static_func()

    print '-' * 20
    # Student.instance_func()
    # unbound method instance_func() must be called with Student instance as
    # first argument (got nothing instead)
    Student.instance_func(s)
    Student.class_func()
    Student.static_func()


class Student():
    '''
    def __init__(self,name):
        self.name=name
        #因为python不用声明变量，所以直接定义就可以使用self.name
    '''

    def __init__(self, name='', score=0):
        self.name = name
        self.score = score

    def print_stu_info(self):
        print 'name:', self.name, 'score:', self.score

    # python的实例方法，类方法和静态方法

    def instance_func(self):
        print 'instanct function'
        print self

    @classmethod
    def class_func(cls):
        print 'class function'
        print cls

    @staticmethod
    def static_func():
        print 'static function'


if __name__ == '__main__':
    main()

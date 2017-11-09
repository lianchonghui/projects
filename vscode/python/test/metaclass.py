#!/usr/bin/env python
#-*- coding:utf-8 -*-

def printHello(self):
    print 'Hello boy.'


def metafun(name,bases,attrs):
     new_attrs={'printHello':printHello}
     return type(name,bases,new_attrs)

class Mymetaclass(type):
    def __new__(cls,name,bases,attrs):
        new_attrs={'printHello':printHello}
        print 'cls:',cls #创建类对象的类,Mymetaclass
        print 'name:',name #被创建的类对象,prino
        print 'bases:',bases #父类对象 type
        print 'attrs:',attrs #属性
        #return type(name,bases,new_attrs)
        #return type.__new__(cls,name,bases,new_attrs)
        #以下方式最佳,可以保持完整的继承性
        return super(Mymetaclass,cls).__new__(cls,name,bases,new_attrs)

#网上文档说这里可以作用到整个模块的所有类,但发现无任何作用
#__metaclass__=metafun

class printo(object):
    #作用到这个类
    __metaclass__=metafun
    st='123'

p=printo()
print hasattr(p,'printHello')
p.printHello()

#!/usr/bin/env python
# -*- coding:utf-8 -*-

r'''这是一个演示模块.

- 模块的单行说明可以使用单引号,可以放在任何位置
- 每一个.py文件都是一个模块，所以每个.py文件都可以这么用
- 注意：''内不是注释，而是一个说明变量
- python的单行注释为#，多行注释是''' '''或者""" """
1.一个.py文件就是一个模块
2.一个包文件必须有一个__init__.py文件，不然这个目录就当成普通目录
3.__init__.py可以是空文件，也可以有python代码
4.__init__.py本身就是一个模块，模块名就是包名
5.包可以是多层的，记得每个包下都有__init__.py文件

'''

__author__ = 'Taro Lian'


def print_init():
    print 'from package module_pck_demo'

class Student(object):
	def __init__(self,name,age):
		self.name=name
		self.age=age
	def getName(self):
		return self.name
	def setName(self,name):
		self.name=name

class Animal(object):
	def __init__(self,name):
		self.name=name
	def run():
		print 'run'

class Dog(Animal):
	def run():
		print 'dog run'
	

#!/usr/bin env python
#-*- coding:utf-8 -*-

def parameter_changed(L=[]):
    L.append('End')
    print id(L)
    return L

def parameter_changed2():
    LL=[]
    LL.append('Start')
    print id(LL)
    return LL

L1=parameter_changed()
print L1
print id(L1)
L2=parameter_changed()
print L2
print id(L2)

LL1=parameter_changed2()
print LL1
print id(LL1)
LL2=parameter_changed2()
print LL2
print id(LL2)

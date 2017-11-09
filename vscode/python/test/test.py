#!/usr/bin/env python
# -*- coding:utf-8 -*-


from exception import Calculate
from exception import MyError

c=Calculate()
try:
    c.a=1
    print 'move'
except MyError,e:
    print e
except StandardError,e:
    print e
finally:
    print 'finally'





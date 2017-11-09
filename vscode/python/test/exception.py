#!/usr/bin/env python
#-*- coding:utf-8 -*-

'a calculate model'

class MyError(StandardError):
    pass

class Calculate(object):

    def sum(self):
        return self._a+self._b

    @property
    def a(self):
        return self._a
    @a.setter
    def a(self,a):
        if not isinstance(a,int):
            raise TypeError('TypeError')
        if a==0:
            raise ValueError('ValueError')
        if a==1:
            raise MyError('invalid number:%d' % a)
        self._a=a

    @property
    def b(self):
        return self._b
    @b.setter
    def b(self,b):
        if not isinstance(b,int):
            raise TypeError
        if b==0:
            raise VblueError
        if b==1:
            raise MyError('invalid number:%s' % self._b)
        self._b=b


if __name__=='__main__':
    print 'It is a calculate module'
#!/usr/bin/env python
#-*- coding:utf-8 -*-

'Person module,incude Person class,Student class,Teacher class'

__author__='Lian'

import sys
import education

class Person(object):
    __slots__=('_name','_age')
    def __init__(self,name='notname',age=0):
        self._name=name
        self._age=age

    @property
    def name(self):
        return self._name
    @name.setter
    def name(self,name):
        if not isinstance(name,str):
            raise ValueError('name must be string')
        self._name=name;

    @property
    def age(self):
        return self._age
    @age.
    













    
    def age(self,age):
        if not isinstance(age,int):
            raise ValueError('age must be a number.')
        if age >200 or age <0:
            raise ValueError('age must between 0~200')
        self._age=age
    


class Student(Person,education.StudyMixin):
    __slots__=()
    def myStudy(self):
        print 'My name is %s' % self._name
        self.study()

class Teacher(Person,education.EducationMixin):
    __slots__=('_subject')
    def __init__(self,name='not',age=0,subject='not'):
        self._name=name
        self._age=age
        self._subject=subject

    @property
    def subject(self):
        return self._subject
    @subject.setter
    def subject(self,subject):
        if not isinstance(subject,str):
            raise ValueError('subject must be string.')
        self._subject=subject
    

        
    


if __name__=='__main__':
    print 'module is',sys.argv[0],',include Person class,Student class,Teacher class.'
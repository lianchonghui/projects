#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys

class StudyMixin(object):
    def __init__(self):
        pass
    def study(self):
        print 'good good study,day day up.'

class EducationMixin(object):
    def teach(self):
        print 'students is our baby.'


if __name__=='__main__':
    print sys.argv[0],'is module including StudyMixin class,EducationMixin class.'
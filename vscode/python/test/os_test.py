#!/usr/bin/env python
#-*- coding:utf-8 -*-

import os

for d in os.listdir('.'):
    print d
    if 'readme.txt'==d :
        f=open(d)
        str=f.readlines(4)
        print type(str)
        str2=''.join(str)
        print type(str2)
        print str2
        print isinstance(str2,unicode)
        str3=str2.decode('gbk')
        print str3
        #print isinstance(str3,ascii)
        print isinstance(str3,unicode)
        str4=str3.encode('utf-8')
        print str4
        print isinstance(str3,unicode)
        print isinstance(str4,unicode)
        str5=str4.decode('utf-8')
        print isinstance(str5,unicode)
        print str5
     

    else :
        print 'no readme.txt'
    

print 'end'
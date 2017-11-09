#!/usr/bin/env python
# -*- coding:utf-8 -*-

import unittest

class TestDict(unittest.TestCase):
    #测试前，一般用于建立数据库链接等
    def setUp(self):
        print 'setUp...'

    #测试后，一般用于关闭数据库的链接等
    def tearDown(self):
        print 'tearDown...'

    #测试MyDict的Value的正常获取
    def test_unit(self):
        d=Dict(a=1,b='test')
        self.assertEqual(d.a,1)#断言期待值相等，当key为a的时候Value为1
        self.assertEqual(d.b,'test')
        self.assertTrue(isinstance(d,dict))#断言期待返回True


    def test_key(self):
        d=Dict()
        d['key']='value'
        self.assertEqual(d.key,'value')

    def test_attr(self):
        d=Dict()
        d.key='value'
        self.assertTrue('key' in d)
        self.assertEqual(d['key'],'value')

    def test_keyerror(self):
        d=Dict()
        #断言期待抛出指定异常，assertRaises遵守上下文协议
        with self.assertRaises(KeyError):
            value=d['empty']

    def test_attrerror(self):
        d=Dict()
        with self.assertRaises(AttributeError):
            value=d.empty



# 需要单元测试的类
class Dict(dict):
    def __init__(self,**kw):
        super(Dict,self).__init__(**kw)
    
    def __getattr__(self,key):
        try:
            return self[key]
        except KeyError:
            raise AttributeError(r"'Dict' object has no attribute '%s'" % key)
        
    def __setattr__(self,key,value):
        self[key]=value
        



if __name__=='__main__':
    unittest.main()

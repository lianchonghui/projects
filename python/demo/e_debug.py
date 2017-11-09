#!/usr/bin/env python
# -*- coding:utf-8 -*-

'''
python的debug的方式
    1.print
    2.assert
        assert触发会抛出AssertionError，启动python -O（注意是大写的字母O） 可以关闭assert
    3.logging
        logging允许指定记录信息的级别，有debug,info,warning,error
    4.pdb
        python -m pdb xxx.py 启动pdb
    5.pdb.set_trace()
        用于给pdb设置断点，在代码中
        import pdb
        插入pdb.set_trace()会在该处设置一个断点
    6.IDE

'''
import logging
logging.basicConfig(level=logging.INFO)

def main():
    # foo_assert(0)
    foo_logging(0)

def foo_logging(s):
    n=int(s)
    logging.info('n=%d' % n)
    print 10/n

def foo_assert(s):
    n=int(s)
    assert n!=0,'n is zero'
    return 10/n




if __name__=='__main__':
    main()
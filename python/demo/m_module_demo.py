#!/usr/bin/env python
# -*- coding:utf-8 -*-

'hello'
# import module_pck_demo 不能通过import一个包使用包下的模块
# import module_pck_demo 导入的是该包下的__init__.py,但模块名是module_pck_demo
# import module_pck_demo.module_demo的方式导入包下的模块会先导入module_pck_demo模块再去导入子模块


# 模块内属性和方法的调用必须是模块名.属性/方法，不能省略模块名
try:
    import module_pck_demo as module_pck
    # 使用别名
    # 别名可以导入相同功能的库，而不用修改代码
    # 如,cStringIO比StringIO高效，单StringIO比cString通用
    '''
        try:
            import cStringIO as StringIO
        except ImportError:
            import StringIO
    '''
except ImportError:
    pass

from module_pck_demo import module_demo


def main():
    print module_demo.__author__
    print module_demo.__doc__
    module_pck.print_init()
    module_demo.print_module()
    print module_demo.__doc__

'hello'

if __name__ == '__main__':
    main()

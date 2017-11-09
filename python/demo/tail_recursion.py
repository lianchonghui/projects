#!/usr/bin/env python
# coding:utf-8


def main():
    print recsum(10)
    print tailrecsum(10)
    print fact(10)


def recsum(x):
    if x == 1:
        return x
    else:
        return x + recsum(x - 1)


def tailrecsum(x, runnint_total=0):
    if x == 0:
        return runnint_total
    else:
        return tailrecsum(x - 1, runnint_total + x)
# 尾递归就是把变化的参数传递给递归函数的变量，
# 这样函数中的形式变量runnint_total的实际变量是不断更新的。


def fact_iter(num, product):
    if num == 1:
        return product
    return fact_iter(num - 1, num + product)


def fact(n):
    return fact_iter(n, 1)


if __name__ == '__main__':
    print '中国'
    main()

'''
作者：匿名用户
链接：http://www.zhihu.com/question/20761771/answer/19996299
来源：知乎
著作权归作者所有，转载请联系作者获得授权。

尾递归和一般的递归不同在对内存的占用，普通递归创建stack累积而后计算收缩，尾递归只会占用恒量的内存（和迭代一样）。SICP中描述了一个内存占用曲线，用以上答案中的Python代码为例（普通递归）：

def recsum(x):
  if x == 1:
    return x
  else:
    return x + recsum(x - 1)

当调用recsum(5)，Python调试器中发生如下状况：

recsum(5)
5 + recsum(4)
5 + (4 + recsum(3))
5 + (4 + (3 + recsum(2)))
5 + (4 + (3 + (2 + recsum(1))))
5 + (4 + (3 + (2 + 1)))
5 + (4 + (3 + 3))
5 + (4 + 6)
5 + 10
15

这个曲线就代表内存占用大小的峰值，从左到右，达到顶峰，
再从右到左收缩。而我们通常不希望这样的事情发生，所以使用迭代，只占据常量stack space(更新这个栈！而非扩展他)。
---------------------
（一个替代方案：迭代）

for i in range(6):
  sum += i

因为Python，Java，Pascal等等无法在语言中实现尾递归优化
(Tail Call Optimization, TCO)，所以采用了for, while, goto等特殊结构代替recursive的表述。
Scheme则不需要这样曲折地表达，一旦写成尾递归形式，就可以进行尾递归优化。
---------------------
Python中可以写（尾递归）：

def tailrecsum(x, running_total=0):
  if x == 0:
    return running_total
  else:
    return tailrecsum(x - 1, running_total + x)

理论上类似上面：

tailrecsum(5, 0)
tailrecsum(4, 5)
tailrecsum(3, 9)
tailrecsum(2, 12)
tailrecsum(1, 14)
tailrecsum(0, 15)
15

观察到，tailrecsum(x, y)中形式变量y的实际变量值是不断更新的，
对比普通递归就很清楚，后者每个recsum()调用中y值不变，仅在层级上加深。所以，尾递归是把变化的参数传递给递归函数的变量了。
怎么写尾递归？形式上只要最后一个return语句是单纯函数就可以。如：

return tailrec(x+1);

而

return tailrec(x+1) + x;

则不可以。因为无法更新tailrec()函数内的实际变量，只是新建一个栈。

但Python不能尾递归优化（Java不行，C可以，我不知道为什么），
这里是用它做个例子。
====================================

如何优化尾递归：
在编译器处理过程中生成中间代码（通常是三地址代码），用编译器优化。
'''

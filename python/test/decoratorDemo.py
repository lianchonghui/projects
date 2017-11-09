#!/usr/bin/env python
# -*- coding:utf-8 -*-


def log(func):
	def wrapper(*args,**kw):
		print "call function %s" % func.__name__
		return func(*args,**kw)
	return wrapper

def log2(arg):
    def decorator(func):
        def wrapper(*args,**kw):
            print "call function %s" % func.__name__
            print arg
            return func(*args,**kw)
        return wrapper
    return decorator 

@log2("arg")
def printHello():
	print "hello python"



if __name__ == "__main__":
	printHello()

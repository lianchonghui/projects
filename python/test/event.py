#!/usr/bin/env python
# -*- coding:utf-8 -*-

import pythoncom
import pyHook

def onKeyboardEvent(event):
    print "MessaageName:",event.MessageName
    print "Message:",event.Message
    print "Time:",event.Time
    

def main():
    hm - pyHook.HookManager()
    hm.keyDown = onKeyboardEvent
    hm.HookKeyboard()
    pythoncom.PumpMessages()

if __name__ == "__main__":
    main()

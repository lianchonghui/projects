#!/usr/bin/env python
# -*- coding:utf-8 -*-

import cocos

class HelloWorld(cocos.layer.Layer):
    def __init__(self):
        super(HelloWorld,self).__init__()

        label = cocos.text.Label('Hello,world',font_name = 'Times New Roman',font_size = 32,anchor_x='center',anchor_y='center')
        label.position = 320,240
        self.add(label)

cocos.director.director.init()

main_scene = cocos.scene.Scene(HelloWorld())
cocos.director.director.run(main_scene)

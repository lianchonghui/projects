#!/usr/lib/env python
# -*- coding:utf-8 -*-

from django.http import HttpResponse
import datetime
from django.template import Context ,Template
from django.template.loader import get_template
from django.shortcuts import render_to_response



def current_datetime(request):
    # now = datetime.datetime.now()
    # html = "<html><body>It is now %s.</body></html>" % now
    '''
    t = get_template('current_datetime.html')
    html = t.render(Context({'current_date': now}))
    return HttpResponse(html)
    '''
    '''
    return render_to_response('current_datetime.html',{'current_date': now}) 
    '''
    current_date = datetime.datetime.now()
    return render_to_response('current_datetime.html',locals())
    
    
def hours_ahead(request,offset):
    offset = int(offset)
    dt = datetime.datetime.now() + datetime.timedelta(hours=offset)
    html = "<html><body>In %s hour(s),it will be %s.</body></html>" % (offset,dt)
    return HttpResponse(html)
    
def request_info(request):
    path = request.path
    host = request.get_host()
    fullpath = path # get_full_path()
    secure = request.is_secure()
    meta = request.META
     
    
    #html0 = "<html><body>path:{{ info.0 }},host:{{ info.1 }},fullpath:{{ info.2 }},sercure:{{ info.3 }}</body></html>"
    
    htmltem = '''<html><body><p>path:{{ infos.0 }}</p>
            <p>host:{{ infos.1 }}</p>
            <p>fullpath:{{ infos.2 }}</p>
            <p>secure:{{ infos.3 }}</p>
            <p>META.HTTP_REFERER:{{ infos.4.HTTP_REFERER }}</p>
            <p>META.HTTP_USER_AGENT:{{ infos.4.HTTP_USER_AGENT }}</p>
            <p>META.REMOTE_ADDR:{{infos.4.REMOTE_ADDR }} 
            </body></html>'''
            # 注意，META是一个字典，key对应的value可能为空，所以原则上应该使用字典的get()方法来取值，获取使用异常捕获。
    t = Template(htmltem)
    c = Context({'infos':[path,host,fullpath,secure,meta]})
    c0 = Context({'path': path,
                'host':host,
                'fullpath':fullpath,
                'secure':secure})
    html = t.render(c)
    return HttpResponse(html)

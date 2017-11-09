一.视图和URL配置
    1.静态URL和动态URL
            from django.conf.urls.defaults import *

            # Uncomment the next two lines to enable the admin:
            # from django.contrib import admin
            # admin.autodiscover()
            from djangowww1.views import current_datetime,hours_ahead

            urlpatterns = patterns('',
                # Example:
                # (r'^djangowww1/', include('djangowww1.foo.urls')),

                # Uncomment the admin/doc line below and add 'django.contrib.admindocs' 
                # to INSTALLED_APPS to enable admin documentation:
                # (r'^admin/doc/', include('django.contrib.admindocs.urls')),

                # Uncomment the next line to enable the admin:
                # (r'^admin/(.*)', admin.site.root),
                (r'^time/$',current_datetime),
                (r'^time/plus/(\d{1,2})/$',hours_ahead),
             )

二.模板
    <html>
        <head><title>Ordering notice</title></head>
        <body>
            <h1>Ordering notice</h1>
            <p>Dear {{ person_name }},</p>
            <p>Thanks for placing an order from {{ company }}. It's scheduled to 
                ship on {{ ship_date|date:"F j,Y" }}.</p>
            <p>Here are the items you've ordered:</p>
            <ul>
                <% for item in item_list %>
                    <li>{{ item }}</li>
                <% endfor %>
            </ul>
            <% if ordered_warranty %>
                <p>Your warranty information will be included in the packaging.</p>
            <% else %>
                <p>You didn't order a warranty,so you're on your own when
                    the products inevitably stop working.</p>
            <% endif %>
            <p>Sincerely,<br/>{{ company }}</p>
        </body>
    </html>

    1.模板标签
        1).{{ person_name }} -- 变量
        2).{% for item in item_list %} ... {% endfor %}  -- for 循环
            # {% for athlete in athlete_list reversed %} 反向迭代
            # 循环钱通常先检测列表的大小。可以用if标签先对列表进行判断，或者使用{% empty %}
                 {% for item in item_list %} ... {% empty %} ... {% endfor %} 
            # for循环不支持退出循环和continue。如果想退出循环，可以改变正在迭代的变量，让其仅仅包含需要迭代的项目
            # 在{% for %}循环有一个forloop的模板变量，包含一些提示循环进度的信息的属性。
                forloop.counter -- 从1开始计数，计算循环次数
                forloop.counter0 -- 从0开始计数，计算循环次数
                forloop.revcounter -- 最有一次循环被置位1，表示循环中剩余项的整型变量
                forloop.revcounter0 -- 最后一次循环被置位0
                
                forloop.last -- 在最后一次循环是被置位True
                    {% for link in links %}{{ link }}{% if not forloop.last %} | {% endif %}{% endfor %}

                forloop.parentloop 指向当前循环的上一级循环的forloop对象的引用（在嵌套的情况下）
                    {% for country in countries %}
                        <table>
                        {% for city in country.city_list %}
                            <tr>
                            <td>Country #{{ forloop.parentloop.counter }}</td>
                            <td>City #{{ forloop.counter }}</td>
                            <td>{{ city }}</td>
                            </tr>
                        {% endfor %}
                        </table>
                    {% endfor %}

        3).{% if ordered_warranty %} ... {% else %} ... {% endif %} -- if 判断
            # if 标签不允许在同一个标签同时使用and 和 or ，会造成逻辑模糊。如果有这个需求，可以使用if嵌套
            # 没有{% elif %}标签，使用if标签嵌套代替。
       
       
        4).{% ifequal user currentuser %}/{% ifnotequal user currentuser %} ... {% else %} ...{% endifequal %}/{% endifnotequal %}
            #只有模板变量，字符串，整数，小数可以作为{% ifequal %}标签的参数。其他类型，例如Python的字典，列表，布尔类型
        
        5).{# ... #} -- 注释标签
        
        6).include模板标签
            {% include 'nav.html' %} # 单引号/双引号都可以
            {% include 'include/nav.html' %}
            {% include template_time %} # 包含了以变量template_name的值为名称的模板内容
            # 如果include标签指定的模板没找到，如果DEBUG为True则报TemplateDoesNotExist异常，如果DEBUG为False，则在标签位置不显示任何东西
        
        7).{% block blockname%} ... {% endblock %}
        8).{% extends "templateName.html" %}
        

    2.模板渲染
        from django.template import Context,Template
        t = Template('My name is {{ name }}.')
        c = Context({'name': 'Stephane'})
        t.render(c) # 返回的是Unicode对象
        
        c = Context({'person_name': 'John Smith',
            'company': 'Outdoor Equipment',
            'ship_date': datetime.date(2009,4,2),
            'ordered_warranty': False})
        
        1.) 同一个模板对象，多个上下文
            # Bad
            for name in ('John','Julie','pat'):
                t = Template('Hello,{{ name }}')
                print t.render(Context({'name': name}))
        
            # Good
            t = Template('Hello,{{ name }}')
            for name in ('John','Julie','Pat'):
                print t.render(Context({'name': name}))
            
         2.) 深度变量查找（点语法）
            a. 点语法访问对象属性
                d = datetime(1993,5,2)
                t = Template('The month is {{ date.month }} and the year is {{ date.year }}.')
                c = Context({'date': d})
                t.render(c)
            
            b. 点语法访问自定义对象属性
                t = Template('Hello,{{ person.first_name }}{{ person.last_name }}.')
                c = Context({'person': Person('Jhon','Smith')})
                t.render(c)
         
            c. 点语法引用对象方法
                t = Template('{{ var }} -- {{ var.upper }} -- {{ var.isdigit }}')
                t.render(Context({'var': 'hello'}))
                t.render(Context({'var': '123'})) 
                # 如果方法抛出一个异常，除非该异常有一个silent_variable_failure属性并且值为True
                # 否则异常被传播，模板里的指定变量会被置位空字符串
                

            d. 点语法方位列表索引（不支持负数索引）
                t = Template('item 2 is {{ items.2 }}.')
                c = Context({'items': ['apples','bananas','carrots']})
                t.render(c)

            # 点语法的调用顺序,系统使用找到的第一个有效类型
                字典类型查找foo["bar"] - 属性查找foo.bar - 方法调用foo.bar() - 列表类型索引查找foo[bar]
            
            # 多层深度嵌套
                person = {'name': 'Sally','age': '43'}
                t = Template('{{ person.name.upper }} is {{ person.age }} years old.')
                c = Context({'person': person})
                t.render(c)
            
            # 防止点语法调用方法引发安全漏洞
            def delete(self):
                # Delete the count
            
            delete.alter_date = True # 设置方法的alter_date 属性，可防止这个方法被调用
            
        3). Context对象
            c = Context({"foo": "bar"})
            del c['foo'] # 删除条目
            c['newvariable'] = 'hello' # 添加条目
                
                
        
    3.过滤器（通过管道字符|）
        {{ name|lower }}
        {{ my_list|first|upper }} -- 多层过滤
        {{ bio|truncatewords:"30" }} -- 显示bio的前30个词 -- 过滤器有参数的类型
        
    4.在视图中使用模板
        # 如果模板单独为一个html文件，需要使用open(),fp.read(),fp.close()的重复代码
    
    5.模板加载（setting.py -- TEMPLATE_DIRS）
        TEMPLATE_DIRS = (
            '/home/taro/projects/python/djangowww1/templates',
        )
        
        TEMPLATE_DIRS = (
            'C:/www/django/templates',
        )
        
        TEMPLATE_DIRS = (
            os.path.join(os.path.dirname(__file__)),'templates').replace('\\','/'),
        )
            # __file__ 即是setting.py文件，后去setting.py文件的目录与templates拼接，如果在windows下会智能选择正确的后向斜杠拼接
        
        
    6.render_to_response()
        # 标准的使用模板的顺序是：--加载模板文件 -> Context渲染 -> 返回处理好的HttpResponse对象
        def current_datetime(request):
            now = datetime.datetime.now()
            t = get_template('current_datetime.html')
            html = t.render(Context({'current_date': now}))
            return HttpResponse(html)
        # 这是一个重复的代码
        # django.shortcuts模块中render_to_response()函数 自动get_template,自动创建Template和Context对象
        from django.shorcuts import render_to_redponse
        import datetime
        
        def current_datetime(request):
            now = datetime.datetime.now()
            return render_to_response('current_datetime.html',{'current_date': now})
            
            
    7.locals()技巧
        def current_datetime(request):
            current_date = datetime.datetime.now()
            return render_to_response('current_datetime.html',locals())
        # locals()囊括执行到该时间点是所定义的一切变量，通过名称获取
        
    8.get_template()使用子目录
        t = get_template('dateapp/current_datetime.html')
        return render_to_response('dateapp/current_datetime.html',{'current_date': now}) 
        # windows下都是使用/斜杠
    
    9.模板继承
        # base.html
        <!DOCTYPE HTML PUBLIC "-//W3C//DTD THML 4.01//EN">
        <html lang="en">
            <head>
                <title>{% block title %}{% endblock %}</title>
            </head>
            <body>
                <h1>My helpful timestamp site</h1>
                {% block content %}{% endblock%}
                {% block footer %}
                <hr>
                <p>Thanks for visiting my site.</p>
                {% endblock %}
            </body>
        </html>
        
        # current_datetime.html
        {% extends "base.html" %}
        {% block title %}The current time{% endblock%}
        {% block content %}
        <p>It is now {{ current_date }}.</P>
        {% endblock %}

三.模型
    1.数据库链接
        1).
        import MySQLdb 
        db=MySQLdb.connect(user='root',db='mydb',passwd='root',host='localhost')
        cursor = db.cursor()
        cursor.execute('SELECT name FROM books ORDER BY name')
        names = [row[0] for row in cursor.fetchall()]
        db.close()
        
        2).在setting.py中设置
            DATABASE_ENGINE = 'mysql'           # 'postgresql_psycopg2', 'postgresql', 'mysql', 'sqlite3' or 'oracle'.
            DATABASE_NAME = 'mydb'             # Or path to database file if using sqlite3.
            DATABASE_USER = 'root'             # Not used with sqlite3.
            DATABASE_PASSWORD = 'root'         # Not used with sqlite3.
            DATABASE_HOST = ''             # Set to empty string for localhost. Not used with sqlite3.
            DATABASE_PORT = ''             # Set to empty string for default. Not used with sqlite3
            
            # python manage.py shell 测试数据库配置
            >>> from django.db import connection
            >>> cursor = connection.cursor()
            
    2.python manage.py startapp books # 创建一个django app
    
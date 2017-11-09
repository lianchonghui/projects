from django.conf.urls.defaults import *

# Uncomment the next two lines to enable the admin:
# from django.contrib import admin
# admin.autodiscover()
from djangowww1.views import current_datetime,hours_ahead,request_info

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
    (r'^requestinfo/$',request_info),
)

#!/usr/bin/env python
# coding=utf-8
import os
import zbar
import Image
import urllib,urllib2,httplib,cookielib
import uuid
import cStringIO
from PIL import Image

def loadURLFromQRCode(url):
    #设置cookie
    cookie = cookielib.CookieJar()
    cj = urllib2.HTTPCookieProcessor(cookie)
    #设置登录

    #生成请求
    request = urllib2.Request(url)

    #
    #opener = urllib2.build_opener(request,cj)
    #f=opener.open(request)
    #print f

def ParseQRCode(url):
    filename = os.path.basename(url)
    if os.path.isfile(filename):
        print filename ,'exist'
    else:
        urllib.urlretrieve(url,filename)
    
    scanner = zbar.ImageScanner()

    scanner.parse_config('enable')

    imgfile = cStringIO.StringIO(urllib.urlopen(url).read())

    pil = Image.open(imgfile).convert('L')

    width,height = pil.size
    raw = pil.tostring()

    image = zbar.Image(width,height,'Y800',raw)
    scanner.scan(image)

    for symbol in image:
        print 'decoded', symbol.type, 'symbol','"%s"' %symbol.data

    loadURLFromQRCode(symbol.data)

if __name__ == '__main__':
    url = 'http://i2.itc.cn/20150327/3470_9584754f_9ea6_3675_bf18_766ff7c7a0ae_1.png'
    ParseQRCode(url);

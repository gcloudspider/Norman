/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include "BlogCSDN.h"
#include "Blog.h"
#include "Observer.h"
#include "ObserverBlog.h"


int main(){
    Blog *blog = new BlogCSDN("wuzhekai1985");
    Observer *observer1 = new ObserverBlog("tutupig",blog);
    blog->Attach(observer1);
    blog->SetStatus("发表设计模式C++  ----观察者模式");
    blog->Notify();

    delete blog;
    delete observer1;

    return 0;
}

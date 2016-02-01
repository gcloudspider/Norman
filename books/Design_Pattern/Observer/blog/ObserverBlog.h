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

#ifndef _OBSERVERBLOG_H_
#define _OBSERVERBLOG_H_
#include "Observer.h"
#include "Blog.h"
class ObserverBlog:public Observer{
private:
    string m_name;
    Blog *m_blog;

public:
    ObserverBlog(string name,Blog *blog);
    ~ObserverBlog();

    void Update();
};
#endif

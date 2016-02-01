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

#ifndef _BLOG_H_
#define _BLOG_H_
#include <iostream>
using namespace std;
#include "Observer.h"
#include <list>
class Blog{
public:
    Blog();
    virtual ~Blog();
    void Attach(Observer *observer);
    void Remove(Observer *observer);
    void Notify();

    virtual void SetStatus(string s);
    virtual string GetStatus();

private:
    list<Observer *> m_observers;
protected:
    string m_status;
};
#endif

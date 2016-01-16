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
#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#pragma once
#include <iostream>
using namespace std;

class Singleton{
public:
    static Singleton* GetInstance(const char* name);
    virtual void Show(){}
protected:      //必须为保护,如果是私有属性,子类无法访问父类的构造函数
    Singleton(){}

//私有
private:
    static Singleton *singleton; //唯一实例的指针
};

#endif

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
#pragma once

#include "Singleton.h"

class SingletonB:public Singleton{
    friend class Singleton;     //必须为友元类,否则父类无法访问子类的构造函数
public:
    void Show(){cout<<"SingletonB"<<endl;}
    //为保护属性,外界无法通过构造函数进行实例化
private:
    SingletonB(){}
};

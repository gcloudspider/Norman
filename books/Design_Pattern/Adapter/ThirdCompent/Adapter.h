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
#ifndef _ADAPTER_H_
#define _ADAPTER_H_
//目标接口类,客户需要的接口
class Target{
public:
    Target();
    virtual ~Target();
    virtual void Request();     //定义标准接口
};

class Adaptee{
public:
    Adaptee();
    ~Adaptee();
    void SpecificRequest();
};

class Adapter:public Target,private Adaptee{
public:
    Adapter();
    ~Adapter();
    virtual void Request();
};

class Adapter1:public Target{
public:
    Adapter1(Adaptee* adaptee);
    Adapter1();
    ~Adapter1();
    virtual void Request();
private:
    Adaptee* _adaptee;
};
#endif

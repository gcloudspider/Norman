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
#ifndef _TEMPLATEDEMO_H_
#define _TEMPLATEDEMO_H_
#include <iostream>
using namespace std;

//定义带默认类型形参的类模板,把T2默认设置为int型
template<class T1,class T2=int> class CeilDemo{
public:
    int ceil(T1,T2);
};


#endif

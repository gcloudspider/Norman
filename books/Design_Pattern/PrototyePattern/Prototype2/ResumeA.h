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
#ifndef _RESUMEA_H_
#define _RESUMEA_H_
#include "Resume.h"
class ResumeA:public Resume{
public:
    ResumeA(const char* str);   //构造函数
    ResumeA(const ResumeA &r);   //拷贝构造函数
    ~ResumeA();
    ResumeA* Clone();
    void Show();
};

#endif

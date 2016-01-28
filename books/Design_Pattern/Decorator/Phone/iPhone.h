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
#ifndef _IPHONE_H_
#define _IPHONE_H_
#include "Phone.h"
class iPhone:public Phone{
private:
    string m_name;
public:
    iPhone(string name);
    ~iPhone();
    void ShowDecorate();
};

#endif

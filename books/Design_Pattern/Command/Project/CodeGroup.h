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
#ifndef _CODEGROUP_H_
#define _CODEGROUP_H_
#pragma once
#include "IGroup.h"

class CCodeGroup:public IGroup{
public:
    CCodeGroup(void);
    ~CCodeGroup(void);
    void Find();
    void Add();
    void Delete();
    void Change();
    void Plan();
};

#endif

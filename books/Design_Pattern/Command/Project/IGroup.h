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
#ifndef _IGROUP_H_
#define _IGROUP_H_
#pragma once
#include <iostream>
using namespace std;
class IGroup{
public:
    IGroup(void);
    virtual ~IGroup(void);

    virtual void Find() = 0;
    virtual void Add() = 0;
    virtual void Delete() = 0;
    virtual void Change() = 0;
    virtual void Plan() = 0;
};
#endif

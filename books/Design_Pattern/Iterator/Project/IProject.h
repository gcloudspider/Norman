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
#ifndef _IPROJECT_H_
#define _IPROJECT_H_
#pragma once
#include "IProjectIterator.h"
#include <iostream>
using namespace std;
#include <vector>
class IProject{
public:
    IProject();
    virtual ~IProject();

    virtual void Add(string name,int num,int cost) =0;
    virtual string GetProjectInfo() = 0;
    virtual IProjectIterator* GetIterator() = 0;
    virtual void Erase() = 0;
};

#endif

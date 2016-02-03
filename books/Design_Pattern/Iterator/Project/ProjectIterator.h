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
#ifndef _PROJECTITERATOR_H_
#define _PROJECTITERATOR_H_
#pragma once
#include "IProjectIterator.h"
#include "IProject.h"

class CProjectIterator:public IProjectIterator{
public:
    CProjectIterator(vector<IProject*> pl);
    ~CProjectIterator();

    IProject *Next();
private:
    vector<IProject *> m_projectList;
    size_t m_currentItem;
};

#endif

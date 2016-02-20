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
#ifndef _EXTENDEDCHAIN_H_
#define _EXTENDEDCHAIN_H_
#include "linearList.h"
template<class T>
class extendedLinearList:linearList<T>{
public:
    virtual ~extendedLinearList(){}
    virtual void clear() = 0;
    virtual void push_back(const T& theElement) = 0;
}

#endif

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

#ifndef _REFCOUNT_H_
#define _REFCOUNT_H_
#include <iostream>
using namespace std;

#define SAFE_DELETE(p) if(p){delete p;p=NULL;}

class KRefCount{
public:
    KRefCount();
public:
    unsigned AddRef();
    unsigned Release();
    void Reset();
private:
    unsigned long m_nCount;
};
#endif

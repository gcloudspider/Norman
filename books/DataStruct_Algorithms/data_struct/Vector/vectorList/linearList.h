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
//C++ 支持抽象类(纯虚函数)和具体类
#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_
#include <iostream>
using namespace std;
template<class T>
class linearList{
public:
    virtual ~linearList(){};

    virtual bool empty() const = 0;
    
    virtual int size() const  = 0;
    
    virtual T& get(int theIndex) const = 0;

    virtual int indexOf(const T& theElement) const = 0;

    virtual void erase(int theIndex)  = 0;

    virtual void insert(int theIndex,const T& theElement) = 0;

    virtual void output(ostream& out) const = 0;

};
#endif

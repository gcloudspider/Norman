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
#ifndef _IOBSERVABLE_H_
#define _IOBSERVABLE_H_
#pragma once
#include "IObserver.h"
#include <iostream>
using namespace std;

class IObservable{
public:
    IObservable(void);
    virtual ~IObservable(void);

    virtual void AddObserver(IObserver *pObserver) =0;
    virtual void DeleteObserver(IObserver *pObserver) =0;
    virtual void NotifyObservers(string context) =0;
};

#endif

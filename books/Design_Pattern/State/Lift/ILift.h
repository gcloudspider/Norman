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
#ifndef _ILIFT_H_
#define _ILIFT_H_
#pragma once
#include <iostream>
using namespace std;
class ILift{
public:
    ILift(void);
    virtual ~ILift(void);

    static const int OPENING_STATE = 1;
    static const int CLOSING_STATE = 2;
    static const int RUNNING_STATE = 3;
    static const int STOPPING_STATE = 4;
    virtual void SetState(int state) =0;
    virtual void Open() = 0;
    virtual void Close() = 0;
    virtual void Run() = 0;
    virtual void Stop() = 0;
};

#endif

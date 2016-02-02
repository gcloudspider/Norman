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
#ifndef _LIFT_H_
#define _LIFT_H_
#pragma once
#include "ILift.h"

class CLift:public ILift{
public:
    CLift();
    ~CLift();
    void SetState(int state);
    void Open();
    void Close();
    void Run();
    void Stop();
private:
    int m_state;
    void OpenWithoutLogic();
    void CloseWithoutLogic();
    void RunWithoutLogic();
    void StopWithoutLogic();
};

#endif

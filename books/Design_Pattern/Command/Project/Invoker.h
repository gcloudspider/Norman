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
#ifndef _INVOKER_H_
#define _INVOKER_H_
#pragma once
#include "ICommand.h"
#include <iostream>
using namespace std;

class CInvoker{
public:
    CInvoker(void);
    ~CInvoker(void);
    void SetCommand(ICommand *pCommand);

    void Action();
private:
    ICommand *m_pCommand;
};

#endif

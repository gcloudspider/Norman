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
#ifndef _CONTEXT_H_
#define _CONTEXT_H_
#include <iostream>
using namespace std;
#include "OpenningState.h"
#include "CloseingState.h"
#include "RunningState.h"
#include "StoppingState.h"
class CContext{
public:
    CContext();
    ~CContext();
    static COpenningState *pOpenningState;
    static CCloseingState *pCloseingState;
    static CRunningState *pRunningState;
    static CStoppingState *pStoppingState;
    CLiftState *GetLiftState();
    void SetLiftState(CLiftState *pLiftState);
    void Open();
    void Close();
    void Run();
    void Stop();
private:
    CLiftState *m_pLiftState;
};

#endif

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
#ifndef _LIFTSTATE_H_
#define _LIFTSTATE_H_
#pragma once
class CContext;
class CLiftState{
public:
    CLiftState();
    virtual ~CLiftState();
    void SetContext(CContext *pContext);
    virtual void Open() = 0;
    virtual void Close() = 0;
    virtual void Run() = 0;
    virtual void Stop() = 0;
protected:
    CContext *m_pContext;
};
#endif

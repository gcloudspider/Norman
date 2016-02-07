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
#ifndef _IVISITOR_H_
#define _IVISITOR_H_
#pragma once
class CCommonEmployee;
class CManager;
class IVisitor{
public:
    IVisitor();
    virtual ~IVisitor();
    virtual void Visit(CCommonEmployee commonEmployee) =0;
    virtual void Visit(CManager manager) =0;
    virtual int GetToTalSalary() =0;
};

#endif

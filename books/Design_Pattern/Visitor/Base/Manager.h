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
#ifndef _MANAGER_H_
#define _MANAGER_H_
#pragma once
#include "Employee.h"
#include "IVisitor.h"

class CManager:public CEmployee{
public:
    CManager();
    ~CManager();
    string GetPerformance();
    void SetPerformance(string per);
    void Accept(IVisitor *pVisitor);

protected:
    string GetOtherInfo();

private:
    string m_performance;
};

#endif

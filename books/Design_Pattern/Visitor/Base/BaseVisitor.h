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
#ifndef _BASEVISITOR_H_
#define _BASEVISITOR_H_
#pragma once
#include "IVisitor.h"
#include "CommonEmployee.h"
#include "Manager.h"

class CBaseVisitor:public IVisitor{
public:
    CBaseVisitor();
    ~CBaseVisitor();
    void Visit(CCommonEmployee commonEmployee);
    void Visit(CManager manager);
    int GetTotalSalary();

private:
    string GetBasicInfo(CEmployee *pemployee);
    string GetManagerInfo(CManager manager);
    string GetCommonEmployee(CCommonEmployee employee);
    static const int MANAGER_COEFFICENT = 5;
    static const int COMMONEMPLOYEE_COEFFICENT = 2;
    int m_commonTotal;
    int m_managerTotal;
    void CalCommonSalary(int salary);
    void CalManagerSalary(int salary);
};

#endif

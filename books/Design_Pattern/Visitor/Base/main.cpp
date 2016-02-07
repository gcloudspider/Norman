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
#include "Manager.h"
#include "BaseVisitor.h"
#include "Employee.h"
#include "CommonEmployee.h"

void MockEmployee(vector<CEmployee*> *pvce){
    CCommonEmployee *pZhangSan = new CCommonEmployee();
    pZhangSan->SetJob("编写Java程序,绝对蓝领,苦工加搬运工");
    pZhangSan->SetName("张三");
    pZhangSan->SetSalary(1800);
}

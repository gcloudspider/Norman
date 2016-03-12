/**
* Create Date:2016年03月12日星期六 08:05:56
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _COMPANYUI_H
#define _COMPANYUI_H
#include "Company.h"
#include "Common.h"
class CompanyUI {
public:
    CompanyUI();
    ~CompanyUI();

    void welcomInfo();
    void showEmployeeInfo(EmployeeInfo_t& userInfo);

};

#endif

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
#ifndef _OUTERUSERINFO_H_
#define _OUTERUSERINFO_H_
#pragma once
#include <iostream>
#include "OuterUser.h"
#include "IUserInfo.h"
using namespace std;

class COuterUserInfo:public IUserInfo{
public:
    COuterUserInfo(void);
    ~COuterUserInfo(void);
    string GetUserName();
    string GetHomeAddress();
    string GetMobileNumber();
    string GetOfficeTelNumber();
    string GetJobPosition();
    string GetHomeTelNumber();
private:
    COuterUser* m_pOuterUser;
};
#endif

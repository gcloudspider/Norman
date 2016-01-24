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
#ifndef _IUSERINFO_H_
#define _IUSERINFO_H_
#pragma once
#include <iostream>
using namespace std;

//系统内部实体接口

class IUserInfo{
public:
    IUserInfo(void);
    virtual ~IUserInfo(void);

    virtual string GetUserName() = 0;
    virtual string GetHomeAddress() = 0;
    virtual string GetMobileNumber() = 0;
    virtual string GetOfficeTelNumber() = 0;
    virtual string GetJobPosition() = 0;
    virtual string GetHomeTelNumber() = 0;
};
#endif

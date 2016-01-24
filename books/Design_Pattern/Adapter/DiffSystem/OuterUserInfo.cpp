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
#include "OuterUserInfo.h"
#include "OuterUserBaseInfo.h"
#include "OuterUserHomeInfo.h"
#include "OuterUserOfficeInfo.h"
#include <iostream>

COuterUserInfo::COuterUserInfo(void){
    m_pOuterUser = new COuterUser();
}

COuterUserInfo::~COuterUserInfo(void){
    delete m_pOuterUser;
}

string COuterUserInfo::GetUserName(){
    COuterUserBaseInfo* pBaseInfo = m_pOuterUser->GetUserBaseInfo();
    pBaseInfo->GetUserName();
    delete pBaseInfo;
    pBaseInfo = NULL;
    return "0";
}

string COuterUserInfo::GetMobileNumber(){
    COuterUserBaseInfo* pBaseInfo = m_pOuterUser->GetUserBaseInfo();
    pBaseInfo->GetMobileNumber();
    delete pBaseInfo;
    pBaseInfo = NULL;
    return "0";
}

string COuterUserInfo::GetOfficeTelNumber(){
    COuterUserOfficeInfo* pOfficeInfo = m_pOuterUser->GetUserOfficeInfo();
    pOfficeInfo->GetOfficeTelNumber();
    delete pOfficeInfo;
    pOfficeInfo = NULL;
    return "0";
}

string COuterUserInfo::GetJobPosition(){
    COuterUserOfficeInfo* pOfficeInfo = m_pOuterUser->GetUserOfficeInfo();
    pOfficeInfo->GetJobPosition();
    delete pOfficeInfo;
    pOfficeInfo = NULL;
    return "0";
}

string COuterUserInfo::GetHomeTelNumber(){
    COuterUserHomeInfo* pHomeInfo = m_pOuterUser->GetUserHomeInfo();
    pHomeInfo->GetHomeTelNumber();
    delete pHomeInfo;
    pHomeInfo = NULL;
    return "0";
}

string COuterUserInfo::GetHomeAddress(){
    COuterUserHomeInfo* pHomeInfo = m_pOuterUser->GetUserHomeInfo();
    pHomeInfo->GetHomeAddress();
    delete pHomeInfo;
    pHomeInfo = NULL;
    return "0";
}

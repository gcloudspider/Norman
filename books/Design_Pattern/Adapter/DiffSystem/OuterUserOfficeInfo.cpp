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
#include "OuterUserOfficeInfo.h"

COuterUserOfficeInfo::COuterUserOfficeInfo(){
    
}

COuterUserOfficeInfo::~COuterUserOfficeInfo(){
    
}

string COuterUserOfficeInfo::GetOfficeTelNumber(){
    cout<<"办公室电话是..."<<endl;
    return "0";
}

string COuterUserOfficeInfo::GetJobPosition(){
    cout<<"这个人职位是BOSS..."<<endl;
    return "0";
}

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
#include "OuterUserHomeInfo.h"

COuterUserHomeInfo::COuterUserHomeInfo(){
    
}

COuterUserHomeInfo::~COuterUserHomeInfo(){
    
}

string COuterUserHomeInfo::GetHomeAddress(){
    cout<<"这里是员工家庭地址...."<<endl;
    return "0";
}

string COuterUserHomeInfo::GetHomeTelNumber(){
    cout<<"员工家庭电话是..."<<endl;
    return "0";
}

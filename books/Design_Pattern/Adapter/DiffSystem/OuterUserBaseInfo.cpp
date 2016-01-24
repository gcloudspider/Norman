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
#include "OuterUserBaseInfo.h"

COuterUserBaseInfo::COuterUserBaseInfo(){
    
}

COuterUserBaseInfo::~COuterUserBaseInfo(){
    
}

string COuterUserBaseInfo::GetUserName(){
    cout<<"姓名叫做..."<<endl;
    return "0";
}

string COuterUserBaseInfo::GetMobileNumber(){
    cout<<"这个人手机号码是0001..."<<endl;
    return "0";
}

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
#include "UserInfo.h"
CUserInfo::CUserInfo(void){
    
}

CUserInfo::~CUserInfo(void){
    
}

string CUserInfo::GetUserName(){
    cout<<"姓名叫做...."<<endl;
    return "0";
}

string CUserInfo::GetHomeAddress(){
    cout<<"这里是员工家庭地址...."<<endl;
    return "0";
}

string CUserInfo::GetMobileNumber(){
    cout<<"这个人的手机号码是0000...."<<endl;
    return "0";
}

string CUserInfo::GetOfficeTelNumber(){
    cout<<"办公室电话是...."<<endl;
    return "0";
}

string CUserInfo::GetJobPosition(){
    cout<<"这个人职位是BOSS..."<<endl;
    return "0";
}

string CUserInfo::GetHomeTelNumber(){
    cout<<"员工的家庭电话是..."<<endl;
    return "0";
}

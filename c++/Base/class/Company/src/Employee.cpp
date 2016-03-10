/**
* Create Date:2016年03月10日星期四 15:51:31
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#include<iostream>
using namespace std;
#include "../include/Employee.h"

CEmployee::CEmployee(int id,string name,int age,string sex,int type,string post,int level,float basePay,int status):
    m_id(id),
    m_name(name),
    m_age(age),
    m_sex(sex),
    m_type(type),
    m_post(post),
    m_level(level),
    m_basePay(basePay),
    m_status(status){

}

CEmployee::~CEmployee(){

}



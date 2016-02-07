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
#include "Employee.h"

CEmployee::CEmployee(){

}

CEmployee::~CEmployee(){

}

string CEmployee::GetName(){
    return m_name;
}

int CEmployee::SetName(string name){
    m_name = name;
}

int CEmployee::GetSalary(){
    return m_salary;
}

void CEmployee::SetSalary(int v){
    m_salary = v;
}

int CEmployee::GetSex(){
    return m_sex;
}

void CEmployee::SetSex(int x){
    m_sex = v;
}

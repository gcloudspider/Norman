/**
* Create Date:2016年03月10日星期四 16:19:23
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
#include "../include/Salesman.h"
#include "../include/Employee.h"

CSalesman::CSalesman(string name,int age,string sex,int type,string post,int status) :
    CEmployee(name,age,sex,type,post,status),
    m_basePay(0),
    m_percent(0.04){

}

CSalesman::~CSalesman() {

}
float CSalesman::getBasePay(){
    return m_basePay;
}

float CSalesman::getPercent() {
    return m_percent;
}


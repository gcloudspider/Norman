/**
* Create Date:2016年03月10日星期四 16:21:39
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
#include "../include/SaleManager.h"
#include "../include/Employee.h"

CSaleManager::CSaleManager(string name,int age,string sex,int type,string post,int status) :
    CEmployee(name,age,sex,type,post,status),
    CManager(name,age,sex,type,post,status),
    CSalesman(name,age,sex,type,post,status),
    m_basePay(5000),
    m_percent(0.05){

}

CSaleManager::~CSaleManager() {

}

float CSaleManager::getBasePay() {
    return m_basePay;
}

float CSaleManager::getPercent() {
    return m_percent;
}

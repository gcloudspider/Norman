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

CSalesman::CSalesman(int id,string name,int age,string sex,int type,string post,int level,float basePay,int status) :
    CEmployee(id,name,age,sex,type,post,level,basePay,status){

}

CSalesman::~CSalesman() {

}


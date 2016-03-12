/**
* Create Date:2016年03月10日星期四 15:44:48
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _MANAGER_H
#define _MANAGER_H
#include "Employee.h"
class CManager : virtual public CEmployee {
public:
    CManager(string name,int age,string sex,int type,string post,int status);
    
    ~CManager();

    float getBasePay();

private:
    float m_basePay;
};
#endif

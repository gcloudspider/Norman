/**
* Create Date:2016年03月10日星期四 15:02:48
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _SALEMANAGER_H
#define _SALEMANAGER_H
#include "Manager.h"
#include "Salesman.h"
class CSaleManager : public CManager,public CSalesman {
public:
    CSaleManager(string name,int age,string sex,int type,string post,int status);
    ~CSaleManager();

    float getBasePay();
    float getPercent();

private:
    float m_basePay;
    float m_percent;
    string m_depart;

};

#endif

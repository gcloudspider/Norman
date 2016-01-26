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

#ifndef _CONCRETECOMPANY_H_
#define _CONCRETECOMPANY_H_
#include "Company.h"

class CConcreteCompany:public CCompany{
public:
    //C++为类中提供类成员的初始化列表
    //声明不需要写初始化列表
    //将初始化列表写在定义.cpp文件中
    CConcreteCompany(string name);
    virtual ~CConcreteCompany();

    void Add(CCompany *pCom);
    void Show(int depth);

private:
    list<CCompany *> m_listCompany;

};
#endif

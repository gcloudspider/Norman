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
#include "BaseVisitor.h"

CBaseVisitor::CBaseVisitor(){
    m_commonTotal = 0;
    m_managerTotal = 0;
}

CBaseVisitor::~CBaseVisitor(){

}

void CBaseVisitor::Visit(CCommonEmployee commonEmployee){
    cout<<this->GetCommonEmployee(commonEmployee).c_str()<<endl;
    this->CalCommonSalary(commonEmployee.GetSalary());
}

void CBaseVisitor::Visit(CManager manager){
    cout<<this->GetManagerInfo(manager).c_str()<<endl;
    this->CalManagerSalary(manager.GetSalary());
}

string CBaseVisitor::GetBasicInfo(CEmployee *pemployee){
    string info = "";
    info.append("姓名:");
    info.append(pemployee->GetName());
    info.append("\t");

}

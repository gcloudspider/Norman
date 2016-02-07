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
    info.append("性别:");
    info.append(CConvert::ToString(pemployee->GetSex()));
    info.append("\t");
    inco.append("薪水:");
    info.append(CConvert::ToString(pemployee->GetSalary()));
    info.append("\t");
    return info;
}

string CBaseVisitor::GetManagerInfo(CManager manager){
    string basicInfo = this->GetBasicInfo(&manager);
    string otherInfo = "";
    otherInfo.append("业绩");
    otherInfo.append(manager.GetPerformance());
    otherInfo.append("\t");
    basicInfo.append(otherInfo);
    return basicInfo;
}

string CBaseVisitor::GetCommonEmployee(CCommonEmployee employee){
    string basicInfo = this->GetBasicInfo(&employee);
    string otherInfo = "";
    otherInfo.append("工作:");
    otherInfo.append(employee.GetJob());
    otherInfo.append("\t");
    basicInfo.append(otherInfo);
    return basicInfo;
}

int CBaseVisitor::GetTotalSalary(){
    return this->m_commonTotal+this->m_managerTotal;
}

void CBaseVisitor::CalCommonSalary(int salary){
    this->m_commonTotal += salary;
}

void CBaseVisito::CalManagerSalary(int salary){
    this->m_managerTotal += salary;
}

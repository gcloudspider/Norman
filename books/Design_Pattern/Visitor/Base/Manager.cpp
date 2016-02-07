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
#include "Manager.h"

CManager::CManager(){
    this->m_performance = "";
}

CManager::~CManager(){

}

string CManager::GetPerformance(){
    return m_performance;
}

void CManager::SetPerformance(string per){
    this->m_performance = per;
}

string CManager::GetOtherInfo(){
    string info = "";
    info.append("业绩:");
    info.append(this->m_performance);
    info.append("\t");
    return info;
}

void CManager::Accept(IVisitor *pVisitor){
    pVisitor->Visit(*this);
}

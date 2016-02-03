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
#include "Project.h"
CProject::CProject(){
    m_name = "";
    m_num = 0;
    m_cost = 0;
}

CProject::CProject(string name,int num,int cost)
    :m_name(name)
     ,m_num(num)
     ,m_cost(cost){
     
}

CProject::~CProject(){

}

string CProject::GetProjectInfo(){
    string info = "";
    info.append("项目名称是:");
    info.append(this->m_name);
    info.append("\t项目人数:");
    info.append(CConvert::ToString(m_num));
    info.append("\t项目费用:");
    info.append(CConvert::ToString(m_cost));
    return info;    
}

void CProject::Add(string name,int num,int cost){
    this->m_projectList.push_back(new CProject(name,num,cost));
}

IProjectIterator* CProject::GetIterator(){
    return new CProjectIterator(this->m_projectList);
}

void CProject::Erase(){
    vector<IProject*>::reverse_iterator projectDelIt = m_projectList.rbegin();
    for(;projectDelIt != m_projectList.rend();projectDelIt++){
        delete (*projectDelIt);
        (*projectDelIt) = NULL;
    }
    m_projectList.clear();
}



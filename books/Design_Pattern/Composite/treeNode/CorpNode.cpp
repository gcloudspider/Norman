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
#include "CorpNode.h"
#include "Convert.h"

CCorpNode::CCorpNode(void){
    m_name = "";
    m_position = "";
    m_salary = 0;
}

CCorpNode::CCorpNode(string _name,string _pos,int _salary)
    :m_name(_name),
    m_position(_pos),
    m_salary(_salary){
    
}

CCorpNode::~CCorpNode(void){
    
}

string CCorpNode::GetInfo(){
    string info="";
    info.append("姓名:");
    info.append(this->m_name);
    info.append("\t职位:");
    info.append(this->m_position);
    info.append("\t薪水:");
    info.append(CConvert::ToString(this->m_salary));
    return info;
}

void CCorpNode::SetParent(CCorpNode *_parent){
    this->m_pParent = _parent;
}

CCorpNode* CCorpNode::GetParent(){
    return this->m_pParent;
}

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
#include "BranchNode.h"

CBranchNode::CBranchNode(void){
    m_isLeaf = false;
}

CBranchNode::CBranchNode(string name,string pos,int salary)
:CCorpNode(name,pos,salary){
    m_isLeaf = false;
}

CBranchNode::~CBranchNode(void){
    
}

void CBranchNode::Add(CCorpNode *pcorpNode){
    pcorpNode->SetParent(this);
    m_subordinateList.push_back(pcorpNode);
}

vector<CCorpNode*> CBranchNode::GetSubordinateInfo(){
    return this->m_subordinateList;
}

bool CBranchNode::IsLeaf(){
    return m_isLeaf;
}

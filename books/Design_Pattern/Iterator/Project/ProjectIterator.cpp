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
#include "ProjectIterator.h"

CProjectIterator::CProjectIterator(vector<IProject *> pl)
    :m_projectList(pl){
    m_currentItem = 0;
        
}

CProjectIterator::~CProjectIterator(){

}

bool CProjectIterator::HasNext(){
    bool b = true;
    if(m_currentItem >= m_projectList.size())
        b = false;
    return b;
}

IProject* CProjectIterator::Next(){
    IProject *pp = m_projectList.at(m_currentItem++);
    return pp;
}

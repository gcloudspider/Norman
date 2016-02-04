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
#include "JTListIterator.h"

JTListIterator::JTListIterator(JTList *pList)
:m_pJTList(pList)
,m_pCurrent(NULL){

}

void JTListIterator::First(){
    m_pCurrent = m_pJTList->First();
}

void JTListIterator::Next(){
    m_pCurrent = m_pCurrent->pNext;
}

bool JTListIterator::IsDone()const {
    return m_pCurrent == m_pJTList->Last()->pNext;
}

Node *JTListIterator::CurrentItem() const{
    return m_pCurrent;
}

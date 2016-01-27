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
#include "CharacterB.h"

CharacterB::CharacterB(){
    this->m_chSymbol = 'B';
    this->m_nWeight = 100;
    this->m_nHeight = 200;
}

CharacterB::~CharacterB(){
    
}

void CharacterB::SetSize(int nWeight,int nHeight){
    this->m_nWeight = nWeight;
    this->m_nHeight = nHeight;
}

void CharacterB::Display(){
    cout<<"CharacterB:"<<m_chSymbol<<"("<<m_nWeight<<","<<m_nHeight<<")"<<endl;
}

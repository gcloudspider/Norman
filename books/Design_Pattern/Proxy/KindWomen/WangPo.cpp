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
#include "WangPo.h"

CWangPo::CWangPo(IKindWomen *pKindWomen){
    this->m_pKindWomen = pKindWomen;
}

CWangPo::~CWangPo(void){
    delete this->m_pKindWomen;
}

void CWangPo::HappyWithMan(){
    this->m_pKindWomen->HappyWithMan();
}

void CWangPo::MakeEyesWithMan(void){
    this->m_pKindWomen->MakeEyesWithMan();
}

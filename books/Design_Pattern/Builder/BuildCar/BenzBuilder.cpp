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
#include "BenzBuilder.h"
#include "BenzModel.h"
CBenzBuilder::CBenzBuilder(void){
    m_pBenz = new CBenzModel();
}

CBenzBuilder::~CBenzBuilder(void){
    delete m_pBenz;
}

void CBenzBuilder::SetSequence(vector<string> *pSeq){
    m_pBenz->SetSequence(pSeq);
}

CCarModel* CBenzBuilder::GetCarModel(){
    return m_pBenz;
}

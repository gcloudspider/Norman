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
#include "BMWBuilder.h"
#include "BMWModel.h"

CBMWBuilder::CBMWBuilder(void){
    m_pBMW = new CBMWModel();
}

CBMWBuilder::~CBMWBuilder(void){
    delete m_pBMW;
}

void CBMWBuilder::SetSequence(vector<string> *pSeq){
    m_pBMW->SetSequence(pSeq);
}

CCarModel * CBMWBuilder::GetCarModel(){
    return m_pBMW;
}

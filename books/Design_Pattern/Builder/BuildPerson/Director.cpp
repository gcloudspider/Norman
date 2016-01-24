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
#include "Director.h"

CDirector::CDirector(CBuilder *builder){
    m_pBuilder = builder;
}

void CDirector::Create(){
    m_pBuilder->BuildHead();
    m_pBuilder->BuildBody();
    m_pBuilder->BuildLeftArm();
    m_pBuilder->BuildRightArm();
    m_pBuilder->BuildLeftLeg();
    m_pBuilder->BuildRightLeg();
}

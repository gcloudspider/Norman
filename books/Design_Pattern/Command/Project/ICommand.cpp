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
#include "ICommand.h"

ICommand::ICommand(void){
    m_prg = new CRequirementGroup();
    m_ppg = new CPageGroup();
    m_pcg = new CCodeGroup();
}

ICommand::~ICommand(void){
    delete m_prg;
    delete m_ppg;
    delete m_pcg;
}

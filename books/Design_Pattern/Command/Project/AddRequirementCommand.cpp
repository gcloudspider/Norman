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
#include "AddRequirementCommand.h"

CAddRequirementCommand::CAddRequirementCommand(void){

}

CAddRequirementCommand::~CAddRequirementCommand(void){

}

void CAddRequirementCommand::Execute(){
    //执行增另一项需求命令
    this->ICommand::m_prg->Find();

    this->ICommand::m_prg->Add();

    this->ICommand::m_prg->Plan();
}

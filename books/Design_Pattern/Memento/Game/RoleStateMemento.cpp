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
#include "RoleStateMemento.h"

RoleStateMemento::RoleStateMemento(unsigned iBlood,unsigned iAttack,unsigned iDefense)
:m_iBlood(iBlood)
,m_iAttack(iAttack)
,m_iDefense(iDefense){
    
}

unsigned RoleStateMemento::GetBloodValue(){
    return m_iBlood;
}

unsigned RoleStateMemento::GetAttackValue(){
    return m_iAttack;
}

unsigned RoleStateMemento::GetDefenseValue(){
    return m_iDefense;
}



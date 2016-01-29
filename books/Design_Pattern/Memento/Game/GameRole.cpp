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
#include "GameRole.h"

GameRole::GameRole()
:m_iBlood(100)
,m_iAttack(100)
,m_iDefense(100){
    
}

RoleStateMemento *GameRole::SaveState(){
    return new RoleStateMemento(m_iBlood,m_iAttack,m_iDefense);
}

void GameRole::RecoveryState(RoleStateMemento* pRoleState){
    m_iBlood = pRoleState->GetBloodValue();
    m_iAttack = pRoleState->GetAttackValue();
    m_iDefense = pRoleState->GetDefenseValue();
    cout<<"Recovery...."<<endl;
}

void GameRole::ShowState(){
    cout<<"Blood:"<<m_iBlood<<endl;
    cout<<"Attack:"<<m_iAttack<<endl;
    cout<<"Defense:"<<m_iDefense<<endl;
}

void GameRole::Fight(){
    m_iBlood -= 100;
    m_iAttack -= 10;
    m_iDefense -= 20;

    if(m_iBlood == 0){
        cout<<"Game Over"<<endl;
    }
}

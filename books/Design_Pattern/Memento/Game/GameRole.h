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
#ifndef _GAMEROLE_H_
#define _GAMEROLE_H_
class GameRole{
public:
    GameRole();

    //存档
    RoleStateMemento *SaveState();
    //恢复存档
    void RecoveryState(RoleStateMemento *pRoleState);

    void ShowState();

    void Fight();

private:
    unsigned m_iBlood;      //生命力
    unsigned m_iAttack;     //攻击力
    unsigned m_iDefense;    //防卸力
};
#endif

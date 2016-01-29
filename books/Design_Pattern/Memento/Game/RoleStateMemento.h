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
#ifndef _ROLESTATEMEMENTO_H_
#define _ROLESTATEMEMENTO_H_
#include <iostream>
using namespace std;

class RoleStateMemento{
public:
    RoleStateMemento(unsigned iBlood,unsigned iAttack,unsigned iDefense);

private:
    friend class GameRole;

    unsigned GetBloodValue();
    unsigned GetAttackValue();
    unsigned GetDefenseValue();

    unsigned m_iBlood;
    unsigned m_iAttack;
    unsigned m_iDefense;
};

#endif

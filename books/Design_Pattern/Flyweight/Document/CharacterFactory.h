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
#ifndef _CHARACTERFACTORY_H_
#define _CHARACTERFACTORY_H_
#include <vector>
#include "Character.h"
#include "CharacterA.h"

class CharacterFactory{
public:
    CharacterFactory();
    ~CharacterFactory();

    //申请一个character对象
    Character* GetCharacter(char);

    //获取存储的Character* 数量
    vector<Character*>::size_type GetCount();

private:
    //保存Chaaracter* 容器,可以换成List等
    vector<Character*> m_vecCharacter;

};

#endif

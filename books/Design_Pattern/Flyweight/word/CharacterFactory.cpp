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
#include "CharacterFactory.h"

CharacterFactory::CharacterFactory(){
    m_mChar.insert(make_pair<char,Character*>('A',new CharacterA));
    m_mChar.insert(make_pair<char,Character*>('B',new CharacterB));
}

CharacterFactory::~CharacterFactory(){
    
}

Character* CharacterFactory::GetCharacter(char chIn){
    map<char,Character*>::iterator it = m_mChar.find(chIn);
    if(it != m_mChar.end()){
        return (Character*)it->second;
    }
    return NULL;
}

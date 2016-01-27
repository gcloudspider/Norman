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
    
}

CharacterFactory::~CharacterFactory(){
    
}

Character* CharacterFactory::GetCharacter(char c){
    vector<Character*>::iterator iter = this->m_vecCharacter.begin();
    for(;iter != this->m_vecCharacter.end();iter++){
        if((*iter)->GetSymbol() == c){
            return *iter;
        }
    }

    Character* pf = new CharacterA(c);
    this->m_vecCharacter.push_back(pf);
    return pf;
}

vector<Character*>::size_type CharacterFactory::GetCount(){
    return this->m_vecCharacter.size();
}

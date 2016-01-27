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
#include "Character.h"

int main(){
    CharacterFactory* pFactory = new CharacterFactory;

    Character* ch1 = pFactory->GetCharacter('A');
    ch1->Display();

    Character* ch2 = pFactory->GetCharacter('B');
    ch2->SetSize(500,800);
    ch2->Display();
    return 0;
}

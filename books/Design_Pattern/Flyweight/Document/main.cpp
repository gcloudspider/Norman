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
#include "Character.h"
#include "CharacterFactory.h"


int main(){
    //存储外部状态
    int ascent = 70;
    int descent = 0;
    int height = 100;
    int width = 120;
    int pointSize = 10;

    string test = "AABCDDEFGHI";
    string::iterator it = test.begin();
    CharacterFactory* pcF = new CharacterFactory();
    for(;it !=test.end();it++){
        pointSize ++;
        char c = *it;
        //申请一个Character对象
        Character* charc = pcF->GetCharacter(c);
        //应用外部状态
        charc->Display(width,height,ascent,descent,pointSize);
    }
    vector<Character*>::size_type sizeChar = pcF->GetCount();
    cout<<"count:"<<sizeChar<<endl;

    return 0;
}

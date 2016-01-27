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
#include "CharacterA.h"

CharacterA::CharacterA(char c)
:Character(c){
    
}

CharacterA::~CharacterA(){
    
}

char CharacterA::GetSymbol(){
    return this->symbol;
}

void CharacterA::Display(int width,int height,int ascent,int descent,int pointSize){
    //接收并作用外部状态
    this->ascent = ascent;
    this->descent = descent;
    this->height = height;
    this->pointSize = pointSize;
    this->width = width;

    cout<<this->symbol <<" "<<this->ascent<<" "<<this->descent<<" "
    <<this->height<<" "<<this->pointSize<<" "<<this->width<<endl;
}


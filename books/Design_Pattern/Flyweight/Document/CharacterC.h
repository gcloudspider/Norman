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
#ifndef _CHARACTERC_H_
#define _CHARACTERC_H_
#include "Character.h"
class CharacterC:public Character{
public:
    CharacterC(char c);
    ~CharacterC();
    virtual void Display(int width,int height,int ascent,int descent,int pointSize);

};
#endif

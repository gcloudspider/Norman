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

#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include <iostream>
using namespace std;

class Character{
public:
    virtual ~Character(){};

    virtual void SetSize(int,int) =0;
    virtual void Display()=0;
protected:
    Character(){};
    char m_chSymbol;
    int m_nWeight;
    int m_nHeight;
};
#endif

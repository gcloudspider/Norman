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
    //析构函数
    virtual ~Character();
    //应用外部状态
    virtual void Display(int width,int height,int ascent,int descent,int pointSize) =0;

    //获取内部状态
    virtual char GetSymbol()=0;
protected:
    /*内部状态*/
    char symbol;

    int width;
    int height;
    int ascent;
    int descent;
    int pointSize;

    //构造函数
    Character(char c);
};
#endif

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
#ifndef _BEVERAGE_H_
#define _BEVERAGE_H_
#include <iostream>
using namespace std;

class Beverage{
public:
    void PrepareBeverage();             //模板方法
    void BoilWater();
    void PourInCup();                   //算法一般步骤
    bool CustomWantsCondiments();       //hook方法,决定某些算法步骤是否挂勾在算法中
    virtual void Brew() = 0;
    virtual void AddCondiments() = 0;   //在子类中实现
};


#endif

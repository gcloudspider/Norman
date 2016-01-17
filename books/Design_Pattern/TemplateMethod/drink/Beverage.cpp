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
#include "Beverage.h"

void Beverage::PrepareBeverage(){
    BoilWater();
    Brew();
    PourInCup();
    if(CustomWantsCondiments()){
        AddCondiments();
    }
}

bool Beverage::CustomWantsCondiments(){
    return true;
}

void Beverage::BoilWater(){
    cout<<"烧开水"<<endl;
}

void Beverage::PourInCup(){
    cout<<"倒入杯中"<<endl;
}

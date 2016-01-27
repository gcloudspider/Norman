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
#include "NewHouseCorp.h"
#include "Clothes.h"
#include "IPod.h"
#include "ShanZhaiCorp.h"

void DoNewRun1(){
    cout<<"---------房地产公司是这样运行的-------"<<endl;
    CHouse house;
    CNewHouseCorp newHouseCorp(&house);
    newHouseCorp.MakeMoney();
    cout<<endl;

    cout<<"--------山寨公司是这样运行的----------"<<endl;
    CCLothes clothes;
    CShanZhaiCorp shanZhaiCorp(&clothes);
    shanZhaiCorp.MakeMoney();
    cout<<endl;
}

void DoNewRun2(){
    cout<<"----------房地产公司是这样运行的-------"<<endl;
    CHouse house;
    CNewHouseCorp newHouseCorp(&house);
    newHouseCorp.MakeMoney();
    cout<<endl;

    cout<<"----------山寨公司是这样运行的--------"<<endl;
    CIPod ipod;
    CShanZhaiCorp shanZhaiCorp(&ipod);
    shanZhaiCorp.MakeMoney();
    cout<<endl;
}

int main(){
    DoNewRun1();

    DoNewRun2();

    return 0;
}

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
#include "BMWModel.h"

CBMWModel::CBMWModel(void){
    
}

CBMWModel::~CBMWModel(void){
    
}

void CBMWModel::Start(){
    cout<<"宝马发动...."<<endl;
}

void CBMWModel::Stop(){
    cout<<"宝马停车...."<<endl;
}

void CBMWModel::Alarm(){
    cout<<"宝马鸣笛..."<<endl;
}

void CBMWModel::EngineBoom(){
    cout<<"宝马引擎声音是这样...."<<endl;
}

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
#include "BenzModel.h"

CBenzModel::CBenzModel(void){
    
}

CBenzModel::~CBenzModel(void){
    
}

void CBenzModel::Start(){
    cout<<"奔驰发动..."<<endl;    
}

void CBenzModel::Stop(){
    cout<<"奔驰停车...."<<endl;
}

void CBenzModel::Alarm(){
    cout<<"奔驰鸣笛..."<<endl;
}

void CBenzModel::EngineBoom(){
    cout<<"奔驰引擎声音是这样...."<<endl;
}


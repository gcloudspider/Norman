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

#include "ZhouSiObserver.h"
#include <iostream>
using namespace std;
CZhouSiObserver::CZhouSiObserver(void):IObserver("周斯"){

}

CZhouSiObserver::~CZhouSiObserver(void){

}

void CZhouSiObserver::Update(string context){
    cout<<"周斯:观察到韩非子活动,自已也开始活动了"<<endl;
    this->Cry(context);
    cout<<"周斯:真真的哭了...."<<endl;
}

void CZhouSiObserver::Cry(string report){
    cout<<"周斯:为因"<<report.c_str()<<"-----所以悲伤呀"<<endl;
}

string CZhouSiObserver::GetName(){
    return m_name;
}

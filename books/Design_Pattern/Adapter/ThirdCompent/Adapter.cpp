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
#include "Adapter.h"
#include <iostream>
using namespace std;

Target::Target(){
    
}

Target::~Target(){
    
}

void Target::Request(){
    cout<<"Target:Request()"<<endl;
}

Adaptee::Adaptee(){
    
}

Adaptee::~Adaptee(){
    
}

void Adaptee::SpecificRequest(){
    cout<<"Adaptee::SpecificRequest()"<<endl;
}

Adapter::Adapter(){
    
}

Adapter::~Adapter(){
    
}
void Adapter::Request(){
    cout<<"Adapter::Request()"<<endl;
    this->SpecificRequest();
    cout<<"----------------------"<<endl;
}

Adapter1::Adapter1():_adaptee(new Adaptee){
    
}

Adapter1::Adapter1(Adaptee* _adaptee){
    this->_adaptee = _adaptee;
}

Adapter1::~Adapter1(){
    
}

void Adapter1::Request(){
    cout<<"Adapter1::Request()"<<endl;
    this->_adaptee->SpecificRequest();
    cout<<"-----------------------"<<endl;
}

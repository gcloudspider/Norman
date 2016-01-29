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
#include "Originator.h"

Originator::Originator(){
    
}

Originator::Originator(const string& state){
    this->_state = state;
}

Originator::~Originator(){
    
}

string Originator::GetState(){
    return this->_state;
}

void Originator::show(){
    cout<<this->_state<<endl;
}

void Originator::SetState(const string& state){
    this->_state = state;
}

Memento* Originator::CreateMemento(){
    return new Memento(this->_state);
}

void Originator::RestoreToMemento(Memento* pMemento){
    this->_state = pMemento->GetState();
}

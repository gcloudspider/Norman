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

#include "Blog.h"

Blog::Blog(){

}

Blog::~Blog(){

}

void Blog::Attach(Observer *observer){
    m_observers.push_back(observer);
}

void Blog::Remove(Observer *observer){
    m_observers.remove(observer);
}

void Blog::Notify(){
    list<Observer*>::iterator iter = m_observers.begin();
    for(;iter != m_observers.end();++iter){
        (*iter)->Update();
    }
}

void Blog::SetStatus(string s){
    m_status = s;
}

string Blog::GetStatus(){
    return m_status;
}

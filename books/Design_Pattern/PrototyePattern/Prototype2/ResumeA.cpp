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
#include "ResumeA.h"

ResumeA::ResumeA(const char* str){
    if(str == NULL){
        name = new char[1];
        name[0] = '\0';
    } else {
        name = new char[strlen(str)+1];
        strcpy(name,str);
    }
}

ResumeA::~ResumeA(){delete[] name;}

ResumeA::ResumeA(const ResumeA &r){
    name = new char[strlen(r.name)+1];
    strcpy(name,r.name);
}

ResumeA* ResumeA::Clone(){
    return new ResumeA(*this);
}

void ResumeA::Show(){
    cout<<"ResumeA name: "<<name<<endl;
}

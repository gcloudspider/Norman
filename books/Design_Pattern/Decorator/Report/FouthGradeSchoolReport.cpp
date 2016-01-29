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
#include "FouthGradeSchoolReport.h"
CFouthGradeSchoolReport::CFouthGradeSchoolReport(void){
    
}

CFouthGradeSchoolReport::~CFouthGradeSchoolReport(void){
    
}

void CFouthGradeSchoolReport::Report(){
    cout<<"尊敬的XXX家长:"<<endl;
    cout<<"......"<<endl;
    cout<<"语文62 数学65 体育98 自然63"<<endl;
    cout<<"......"<<endl;
    cout<<"       家长签名:"<<endl;
}

void CFouthGradeSchoolReport::Sign(string name){
    cout<<"家长签名为: "<<name.c_str()<<endl;
}

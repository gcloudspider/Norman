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
#include "SortDecorator.h"

CSortDecorator::CSortDecorator(ISchoolReport *psr)
:CReportDecorator(psr){
    
}

CSortDecorator::~CSortDecorator(void){
    
}

void CSortDecorator::ReportSort(){
    cout<<"我是排名第38名...."<<endl;
}

void CSortDecorator::Report(){
    this->CReportDecorator::Report();
    this->ReportSort();
}

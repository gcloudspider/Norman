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
#include "HighScoreDecorator.h"


CHighScoreDecorator::CHighScoreDecorator(ISchoolReport *psr)
:CReportDecorator(psr){
    
}

CHighScoreDecorator::~CHighScoreDecorator(void){
    
}

void CHighScoreDecorator::Report(){
    this->ReportHighScore();
    this->CReportDecorator::Report();
}

void CHighScoreDecorator::ReportHighScore(){
    cout<<"这次考试语文最高是75 数学是78 自然是80"<<endl;
}

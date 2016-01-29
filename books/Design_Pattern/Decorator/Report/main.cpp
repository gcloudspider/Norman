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
#include "ISchoolReport.h"
#include "FouthGradeSchoolReport.h"
#include "HighScoreDecorator.h"
#include "SortDecorator.h"
#include <iostream>
using namespace std;


void DoIt(){
    //ISchoolReport *psr = new CSugarFouthGradeSchoolReport();
    //psr->Report();
    //psr->Sign("老三");
    //delete psr;
}

void DoNew(){
    cout<<"------分部分进行装饰-------"<<endl;
    ISchoolReport *psr = new CFouthGradeSchoolReport();

    ISchoolReport *pssr = new CSortDecorator(psr);
    ISchoolReport *phsr = new CHighScoreDecorator(pssr);
    phsr->Report();
    phsr->Sign("老三");

    delete pssr;
    delete phsr;
    delete psr;
}

int main(){
    //DoIt();

    DoNew();

    return 0;
}

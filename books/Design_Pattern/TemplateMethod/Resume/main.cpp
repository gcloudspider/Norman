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
#include "Resume.h"
#include "ResumeA.h"
#include "ResumeB.h"

int main(){
    Resume *r1;
    r1 = new ResumeA();
    r1->FillResume();
    delete r1;

    r1 = new ResumeB();
    r1->FillResume();
    delete r1;
    r1 = NULL;

    return 0;
}

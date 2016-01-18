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

#include <stdio.h>
#include "Resume.h"
#include "ResumeA.h"
#include "ResumeB.h"

int main(){
    Resume *r1 = new ResumeA("A");
    Resume *r2 = new ResumeB("B");
    Resume *r3 = r1->Clone();
    Resume *r4 = r2->Clone();
    printf("r1:");
    r1->Show();
    printf("r2:");
    r2->Show();
    delete r1;
    delete r2;
    r1 = r2 = NULL;
    printf("r3:");
    r3->Show();
    printf("r4:");
    r4->Show();
    delete r3;
    delete r4;
    r3 = r4 = NULL;
}

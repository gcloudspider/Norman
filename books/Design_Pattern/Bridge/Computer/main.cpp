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

#include "OS.h"
#include "Computer.h"
#include "AppleComputer.h"
#include "WindowOS.h"
#include "LinuxOS.h"

int main(){
    OS *os1 = new WindowOS();
    OS *os2 = new LinuxOS();
    Computer* computer1 = new AppleComputer();
    computer1->InstallOS(os1);
    computer1->InstallOS(os2);
}

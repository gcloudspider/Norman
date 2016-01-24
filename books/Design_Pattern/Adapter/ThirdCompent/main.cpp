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
#include "Adapter.h"

int main(){
    //类模式
    Target* pTarget = new Adapter();
    pTarget->Request();

    //对象模式1
    Adaptee* ade = new Adaptee();
    Target* pTarget1 = new Adapter1(ade);
    pTarget1->Request();

    //对象模式2
    Target* pTarget2 = new Adapter1();
    pTarget2->Request();

    return 0;
}

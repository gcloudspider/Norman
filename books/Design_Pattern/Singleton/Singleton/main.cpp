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

#include "Singleton.h"
#include <iostream>

int main(){
    Singleton* ps = Singleton::Instance();      //通过全局访问点获取实例
    Singleton::Destroy();
    return 0;
}


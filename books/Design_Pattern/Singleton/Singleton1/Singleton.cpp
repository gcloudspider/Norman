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
#include <stdlib.h>
#include <string.h>
#include "Singleton.h"
#include "SingletonA.h"
#include "SingletonB.h"

Singleton* Singleton::singleton = NULL;

Singleton* Singleton::GetInstance(const char* name){
    if(singleton == NULL){
        if(strcmp(name,"SingletonA")==0){
            singleton = new SingletonA();
        } else if(strcmp(name,"SingletonB")==0){
            singleton = new SingletonB();
        } else {
            singleton = new Singleton();
        }
    }
    return singleton;
}

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
using namespace std;

Singleton* Singleton::pInstance = NULL;

Singleton::Singleton(){
    cout <<"Singleton...."<<endl;
}

Singleton* Singleton::Instance(){
    //boost::mutex mutex;
    if(NULL == pInstance){  //多线程时，双重锁
       // mutex.lock();     //C++没有直接的Lock操作,使用其它库Lock 如Boost
       // if( NULL == pInstance){
            pInstance = new Singleton();
       // }
       // mutex.unlock();
    }
    return pInstance;
}

void Singleton::Destroy(){
    if(pInstance != NULL){      //销毁前判断实例化是否空
        delete pInstance;
        pInstance = NULL;
        cout<<"Destroy..."<<endl;
    }
}

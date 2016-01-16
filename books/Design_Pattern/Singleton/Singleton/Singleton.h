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
#ifndef _SINGLETON_H_
#define _SINGLETON_H_
class Singleton{
private:
    static Singleton* pInstance;   //静态成员,保存对象的唯一实例
    Singleton();                    //私有化构造函数,使其无法在类外实例化
public:
    static Singleton* Instance();
    static void Destroy();
};

#endif

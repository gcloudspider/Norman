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
#include <iostream>
using namespace std;

class Singleton{
public:
    static Singleton& instance(){
        static Singleton singleton;
        //静态变量 可以将该实例的创建延迟到实例访问函数被调用时才执行,以提高程序启动速度
        return singleton;
    }
private:
    Singleton();        //构造函数非通公有限制其类型有且只有一个.
};

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
#include "TemplateDemo.h"

//在类模板的外部定义类中的成员时template 后的形参表应省略默认的形参类型
template<class T1,class T2>
int CeilDemo<T1,T2>::ceil(T1 a,T2 b){
    return a>>b;
}

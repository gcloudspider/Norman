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


template<typename T>
int CompareDemo<T>::compare(const T& a,const T& b){
    if((a-b)>0)
        return 1;
    else if((a-b)<0)
        return -1;
    else 
        return 0;
}

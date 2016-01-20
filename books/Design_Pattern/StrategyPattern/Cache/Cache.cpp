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
#include "Cache.h"
//直接通过参数指定,传入一个特定算法的指针:
//此方法将算法暴露在外
//
Cache::Cache(ReplaceAlgorithm *ra){
    m_ra = ra;
}

Cache::~Cache(){
    delete m_ra;
}

void Cache::Replace(){
    m_ra->Replace();
}

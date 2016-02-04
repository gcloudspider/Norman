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
#ifndef _CACHE_H_
#define _CACHE_H_
//也是通过参数指定,只不过不是传入指针,而是一个标签
//这种方式将简单工厂模式与策略模式结合在一起
enum RA {LRU,FIFO,RANDOM};

#include "ReplaceAlgorithm.h"
#include "LRU_ReplaceAlgorithm.h"
#include "FIFO_ReplaceAlgorithm.h"
#include "Random_ReplaceAlgorithm.h"
class Cache{
private:
    ReplaceAlgorithm *m_ra;
public:
    Cache(enum RA ra);
    ~Cache();
    void Replace();

};
#endif

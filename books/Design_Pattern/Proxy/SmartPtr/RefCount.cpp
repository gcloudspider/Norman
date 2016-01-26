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
/*
*原子操作:该操作绝不会在执行完毕前被任何其他任务或事件打断。---最小执行单位
*原子实际是使用了物理学里物质微粒的概念
* */
#include "RefCount.h"
//#include </usr/src/linux-headers-3.13.0-74/include/asm-generic/atomic.h>
//atomic_inc 是内核级汇编实现
#include <stdlib.h>

//gcc 从4.1.2提供__sync_*系列的built-in函数.用于提供加减和逻辑运算的原子操作

KRefCount::KRefCount()
:m_nCount(0){
    
}

unsigned KRefCount::AddRef(){
    //atomic_inc(&v)对变量 V用锁定总线的单指令进行不可分解的"原子"级增量操作
    //避免V的值由于中断或多处理器同时操作造成不确定状态
    __sync_fetch_and_add(&m_nCount,1);
    //return atomic_inc(&m_nCount);
    //return InterlockedIncrement(&m_nCount);
    //InterlockedIncrement Windows 实现原子级操作
}

unsigned KRefCount::Release(){
    __sync_fetch_and_add(&m_nCount,1);
    
    //return atomic_inc(&m_nCount);
    //return InterlockedIncrement(&m_nCount);
}

void KRefCount::Reset(){
    m_nCount = 0;
}

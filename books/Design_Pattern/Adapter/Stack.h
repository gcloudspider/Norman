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
#ifndef _STACK_H_
#define _STACK_H_
#include "Sequence.h"
#include "Deque.h"
class Stack:public Sequence{
public:  
    void push(int x);
    void pop();
private:
    Deque deque;
};
#endif

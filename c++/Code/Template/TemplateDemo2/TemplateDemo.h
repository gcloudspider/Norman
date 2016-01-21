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
#ifndef _TEMPLATEDEMO_H_
#define _TEMPLATEDEMO_H_
#include<iostream>
using namespace std;

template<class T,int MAXSIZE> class Stack{
private:
    T elems[MAXSIZE];                       //包含元素的数组
    int numElems;                           //总元素个数
public:
    Stack();                                //构造函数
    void push(T const&);                    //压栈
    void pop();                             //弹栈
    T top() const;                          //返回栈顶元素
    bool empty() const;                     //返回栈是否为空
    bool full() const;                      //返回栈是否已満
};
#endif

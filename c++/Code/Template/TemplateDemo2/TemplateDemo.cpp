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
#include <stdexcept>
template <class T,int MAXSIZE>
Stack<T,MAXSIZE>::Stack()
    :numElems(0){
}

template <class T,int MAXSIZE>
void Stack<T,MAXSIZE>::push(T const& elem){
    if(numElems == MAXSIZE){
        throw std::out_of_range("Stack<>::push(): stack is full");
    }
    elems[numElems] = elem;                 //附加元素
    ++numElems;                             //增加元素的个数
}

template<class T,int MAXSIZE>
void Stack<T,MAXSIZE>::pop(){
    if(numElems <= 0){
        throw std::out_of_range("Stack<>::pop():empty stack");
    }
    --numElems;                             //减少元素个数
}

template<class T,int MAXSIZE>
T Stack<T,MAXSIZE>::top()const{
    if(numElems <=0){
        throw std::out_of_range("Stack<>::top():empty stack");
    }
    return elems[numElems -1];              //返回最后一个元素
}

template<class T,int MAXSIZE>
bool Stack<T,MAXSIZE>::empty()const{
    return numElems == 0;                   //返回为空
}

template<class T,int MAXSIZE>
bool Stack<T,MAXSIZE>::full()const {
    return numElems == MAXSIZE;             //返回栈満
}

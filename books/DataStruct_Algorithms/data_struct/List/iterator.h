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
#ifndef _ITERATOR_H_
#define _ITERATOR_H_
class iterator{
    //迭代器:向前迭代
public:
    iterator(chainNode<T>* theNode = NULL){node = theNode;}

    T& operator*() const {return node->element;}
    T* operator->() const {return &node->element;}

    //迭代器加法
    iterator& operator++(){node = node->next; return *this;}
    iterator operator++(int){iterator old= *this; node= node->next;return old;}

    bool operator!=(const iterator right) const{return node != right.node;}
    bool operator==(const iterator right) const{return node == right.node;}

protected:
    chainNode<T>* node;
};
#endif

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
#ifndef _CHAIN_H_
#define _CHAIN_H_
#include "linearList.h"
template<class T>
class chain:public linearList<T>{
public:
    chain(int initialCapacity =10 );
    chain(const chain<T>&);
    ~chain();

    bool empty() const {return listSize == 0;}
    int size() const{return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex,const T& theElement);
    void output(ostream& out) const;
protected:
    void checkIndex(int theIndex) const;
    chainNode<T>* firstNode;
    int listSize;
}
#endif

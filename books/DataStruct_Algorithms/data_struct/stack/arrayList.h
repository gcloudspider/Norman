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
#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_
#include "linearList.h"
template<class T>
class arrayList:public linearList<T>{
public:
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T>&);
    ~arrayList(){delete [] element;}

    //ADT
    bool empty() const{return listSize == 0;}
    int size() const{return listSize;}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex,const T& theElement);
    void output(ostream& out)const;

    int capacity()const{return arrayLength;}

protected:
    void checkIndex(int theIndex) const;
    T* element;
    int arrayLength;
    int listSize;
};
#endif

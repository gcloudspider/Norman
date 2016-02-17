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
#ifndef _VECTORLIST_H_
#define _VECTORLIST_H_
#include "linearList.h"

template<class T>
class vectorList:public linearList<T>{
public:
    vectorList(int initialCapacity = 10);
    vectorList(const vectorList<T>&);
    ~vectorList(){delete element;}

    bool empty()const {return element->empty();}
    int size() const {return (int) element->size();}
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex,const T& theElement);
    void output(ostream& out)const;

    //增加方法:
    int capacity()const {return (int) element->capacity();}

    typedef typename vector<T>::iterator iterator;
    iterator begin(){return element->begin();}
    iterator end(){return element->end();}

protected:
    void checkIndex(int theIndex) const;
    vector<T>* element;
}
#endif

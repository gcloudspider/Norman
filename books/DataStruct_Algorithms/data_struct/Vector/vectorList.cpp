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
#include "vectorList.h"

template<class T>
vectorList<T>::vectorList(int initialCapacity){
    if(initialCapacity < 1){
        ostringstream s;
        s << "Inital capacity = "<<initialCapacity<<"Must be > 0";
        throw illegallParameterValue(s.str());
    }

    element = new vector<T>;
    element->reserve(initialCapacity);
}

template<class T>
vectorList<T>::vectorList(const vectorList<T>& theList){
    element = new vector<T>(*theList.element);
}

template<class T>
void vectorList<T>::erase(int theIndex){
    checkIndex(theIndex);
    element->erase(begin()+theIndex);
}

template<class T>
void vectorList<T>::insert(int theIndex,const T& theElement){
    if(theIndex < 0|| theIndex > size()){
        ostringstream s;
        s<<"index = "<<theIndex<<" size = "<<size();
        throw illegalIndex(s.str());
    }
    element->insert(element->begin()+theIndex,theElement);
}

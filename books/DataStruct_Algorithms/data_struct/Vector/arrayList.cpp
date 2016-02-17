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
#include "arrayList.h"
template<class T>
arrayList<T>::arrayList(int initialCapacity){
    //构造函数
    if(initialCapacity < 1){
        ostringstream s;
        s<<"Initial Capacity = "<<initialCapacity<<"Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList){
    //拷贝构造函数
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element,theList.element + listSize,element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const{
    if(theIndex < 0 || theIndex >= listSize){
        ostringstream s;
        s<<"index = "<<theIndex<<"size = "<<listSize;
        throw illegalIndex(s.str());
    }
}

template<class T>
T& arrayList<T>::get(int theIndex) const{
    checkIndex(theIndex);
    return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const{
    //查找元素
    int theIndex = (int) (find(element,element + listSize,theElement)-element);

    if(theIndex == listSize){
        return -1;
    }else {
        return theIndex;
    }
}

template<class T>
void arrayList<T>::erase(int theIndex){
    checkIndex(theIndex);

    copy(element + theIndex +1,element + listSize,element+ theIndex);
    element[--listSize].~T();   //调用析构函数
}

template<class T>
void arrayList<T>::insert(int theIndex,const T& theElement){
    if(theIndex < 0|| theIndex > listSize){
        ostringstream s;
        s<<"index = "<< theIndex << "size = "<<listSize;
        throw illegalParameterValue(s.str());
    }

    if(listSize == arrayLength){
        changeLegthID(element,arrayLength,2*arrayLength);
        arrayLength *= 2;
    }

    copy_backward(element + theIndex,element + listSize, element+listSize +1);
    element[theIndex] = theElement;
    listSize++;
}

template<class T>
void arrayList<T>::output(cout->out) const{
    copy(element, element + listSize,ostream_iterator<T>(cout," "));
}
//重载<<操作符
template<class T>
ostream& operator<<(ostream& out,const arrayList<T>& x){
    x.output(out);
    return out;
}

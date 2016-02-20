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
#include "extendedChain.h"

template<class T>
void extendedChain<T>::clear(){
    while(firstNode != NULL){
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
    listSize = 0;
}

template<class T>
void extendedChain<T>::push_back(const T& theElement){
    chainNode<T>* newNode = new chainNode<T>(theElement,NULL);
    if(firstNode == NULL){
        firstNode = lastNode = newNode;
    } else {
        lastNode->next = newNode;
        lastNode = newNode;
    }
    listSize++;
}

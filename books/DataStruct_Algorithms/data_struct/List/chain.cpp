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
#include "chain.h"
template<class T>
chain<T>::chain(int initialCapacity){
    if(initialCapacity < 1){
        ostringstream s;
        s<<"Initial capacity ="<<initialCapacity <<"Must be > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = NULL;
    listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& theList){
    listSize = theList.listSize;
    if(listSize == 0){
        firstNode = NULL;
        return ;
    }

    chainNode<T>* sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element);
    sourceNode = sourceNode->next;
    chainNode<T>* targetNode = firstNode;
    while(sourceNode != NULL){
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = NULL;
}

template<class T>
chain<T>::~chain(){
    while(firstNode != NULL){
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

template<class T>
T& chain<T>::get(int theIndex) const{
    checkIndex(theIndex);

    chainNode<T>* currentNode = firstNode;
    for(int i=0;i<theIndex;i++){
        currentNode = currentNode->next;
    }
    return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const{
    chainNode<T>* currentNode = firstNode;
    int index = 0;
    while(currentNode != NULL && currentNode->element != theElement){
        currentNode = currentNode->next;
        index++;
    }

    if(currentNode == NULL){
        return -1;
    } else {
        return index;
    }
}

template<class T>
void chain<T>::erase(int theIndex){
    checkIndex(theIndex);
    chainNode<T>* deleteNode;

    if(theIndex == 0){
        deleteNode = firstNode;
        firstNode = firstNode->next;
    } else {
        chainNode<T>* p = firstNode;
        for(int i=0;i< theIndex -1;i++){
            p = p->next;
        }
        deleteNode = p->next;
        p->next = p->next->next;
    }
    listSize --;
    delete deleteNode;
}

//插入
template<class T>
void chain<T>::insert(int theIndex,const T& theElement){
    if(theIndex < 0|| theIndex > listSize){
        ostringstream s;
        s <<"index = "<<theIndex << "size = "<<listSize;
        throw illegalIndex(s.str());
    }
    //插入到头
    if(theIndex == 0){
        firstNode = new chainNode<T>(theElement,firstNode);
    }else{
        chainNode<T>* p = firstNode;
        for(int i =0;i<theIndex -1; i++){
            p = p->next;
        }
        p->next = new chainNode<T>(theElement,p->next);
    }
    listSize++;
}

template<class T>
void chain<T>::output(ostream& out) const{
    for(chainNode<T>* currentNode = firstNode;
       currentNode != NULL;
       currentNode = currentNode->next)
    
    out<<currentNode->element << " ";
}

//重载<<
template<class T>
ostream& operator<<(ostream& out,const chain<T>& x){
    x.output(out);
    return out;
}

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
#include "JTList.h"
#include "JTListIterator.h"

int main(){
    JTList *pJTList = new JTList;
    pJTList->Append(10);
    pJTList->Append(20);
    pJTList->Append(30);
    pJTList->Append(40);
    pJTList->Append(50);
    pJTList->Append(60);
    pJTList->Append(70);
    pJTList->Append(80);
    pJTList->Append(90);
    pJTList->Append(100);

    Iterator *pIterator = new JTListIterator(pJTList);

    for(pIterator->First(); !pIterator->IsDone();pIterator->Next()){
        cout<<pIterator->CurrentItem()->value<<"->";
    }
    cout<<"NULL"<<endl;

    Node *pDeleteNode = NULL;
    for(pIterator->First(); !pIterator->IsDone();pIterator->Next()){
        pDeleteNode = pIterator->CurrentItem();
        if(pDeleteNode->value == 100){
            pJTList->Remove(pDeleteNode);
            break;
        }
    }

    for(pIterator->First();!pIterator->IsDone();pIterator->Next()){
        cout<<pIterator->CurrentItem()->value<<"->";
    }
    cout<<"NULL"<<endl;

    delete pIterator;
    delete pJTList;
    return 0;
}

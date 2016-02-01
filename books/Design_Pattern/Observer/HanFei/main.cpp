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

#include "LiSiObserver.h"
#include "IObserver.h"
#include "ZhouSiObserver.h"
#include "HanFeiziObservable.h"

void DoNew(){
    
}

void DoNewNew(){
    cout<<"------用更新方法再试试-----"<<endl;

    IObserver *pLiSi = new CLiSiObserver();
    IObserver *pZhouSi = new CZhouSiObserver();

    CHanFeiziObservable *pHanFeiZi = new CHanFeiziObservable();

    pHanFeiZi->AddObserver(pLiSi);
    pHanFeiZi->AddObserver(pZhouSi);

    pHanFeiZi->HaveBreakfast();

    delete pLiSi;
    pLiSi = NULL;
    delete pHanFeiZi;
    pHanFeiZi= NULL;
}

int main(){
    DoNewNew();


    return 0;
}

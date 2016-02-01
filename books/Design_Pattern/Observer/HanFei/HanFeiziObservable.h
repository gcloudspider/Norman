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
#ifndef _HANFEIZIOBSERVABLE_H_
#define _HANFEIZIOBSERVALBE_H_
#pragma once
#include "IObservable.h"
#include <vector>
class CHanFeiziObservable:public IObservable{
public:
    CHanFeiziObservable(void);
    ~CHanFeiziObservable(void);

    void AddObserver(IObserver *pObserver);
    void DeleteObserver(IObserver *pObserver);
    void NotifyObservers(string context);
    void HaveBreakfast();
    void HaveFun();

private:
    vector<IObserver* >m_observerList;
    typedef vector<IObserver *>::const_iterator ObserverList_C_iterator;

};

#endif

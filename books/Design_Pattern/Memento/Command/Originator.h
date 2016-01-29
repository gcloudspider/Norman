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

#ifndef _ORIGINATOR_H_
#define _ORIGINATOR_H_
#include <iostream>
using namespace std;
#include "Memento.h"
class Originator{
public:
    Originator();
    Originator(const string& state);
    ~Originator();

    void RestoreToMemento(Memento* pMemento);
    Memento* CreateMemento();

    void SetState(const string& state);
    string GetState();
    void show();
private:
    string _state;
};
#endif

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
#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>
using namespace std;
#include "Mediator.h"
class Mediator;

class Person{
protected:
    Mediator *m_mediator;
public:
    virtual void SetMediator(Mediator *mediator);
    virtual void SendMessage(string message);
    virtual void GetMessage(string message);
};

#endif

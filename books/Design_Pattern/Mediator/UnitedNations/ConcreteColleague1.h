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

#ifndef _CONCRETECOLLEAGUE1_H_
#define _CONCRETECOLLEAGUE1_H_
#include "Colleague.h"

class ConcreteColleague1:public Colleague{
public:
    ConcreteColleague1(Mediator *pMediator);
    void Send(wchar_t *message);
    void Notify(wchar_t *message);
};
#endif

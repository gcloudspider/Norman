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
#ifndef _CONCRETEMEDIATOR_H_
#define _CONCRETEMEDIATOR_H_
#include "Mediator.h"
#include "ConcreteColleague1.h"
#include "ConcreteColleague2.h"

class ConcreteMediator:public Mediator{
public:
    void Send(wchar_t *message,Colleague *pColleague);

    void SetColleague1(Colleague *pColleague);
    
    void SetColleague2(Colleague *pColleague);
private:
    ConcreteColleague1 *m_pColleague1;
    ConcreteColleague2 *m_pColleague2;
};

#endif

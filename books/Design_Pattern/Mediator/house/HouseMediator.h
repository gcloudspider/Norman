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
#ifndef _HOUSEMEDIATOR_H_
#define _HOUSEMEDIATOR_H_
#include "Mediator.h"
class HouseMediator:public Mediator{
private:
    Person *m_A;        //租房者
    Person *m_B;        //房东
public:
    HouseMediator();
    void SetA(Person *A);
    void SetB(Person *B);
    void Send(string message,Person *person);
};
#endif

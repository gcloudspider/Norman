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

#ifndef _MEDIATOR_H_
#define _MEDIATOR_H_
#include <iostream>
using namespace std;

class Mediator{
public:
    virtual void Send(string message,Person *person);
    virtual void SetA(Person *A);
    virtual void SetB(Person *B);
};
#endif

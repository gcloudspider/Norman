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

#ifndef _LANDLORD_H_
#define _LANDLORD_H_
#include "Person.h"
class Landlord:public Person{
public:
    void SetMediator(Mediator *mediator);
    void SendMessage(string message);
    void GetMessage(string message);
};
#endif

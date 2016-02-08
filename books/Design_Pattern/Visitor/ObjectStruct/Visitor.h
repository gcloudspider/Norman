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
#ifndef _VISITOR_H_
#define _VISITOR_H_


#include <iostream>
using namespace std;
#include <vector>
#include "ConcreteElementA.h"
#include "ConcreteElementB.h"
class ConcreteElementA;
class ConcreteElementB;

class Visitor{
public:
    virtual void VisitConcreteElementA(ConcreteElementA *pElementA) = 0;
    virtual void VisitConcreteElementB(ConcreteElementB *pElementB) = 0;
};

#endif

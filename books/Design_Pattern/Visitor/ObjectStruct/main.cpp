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
#include "ObjectStructure.h"
#include "ConcreteElementA.h"
#include "ConcreteElementB.h"
#include "ConcreteVisitor1.h"
#include "ConcreteVisitor2.h"

int main(){
    ObjectStructure *pObject = new ObjectStructure;

    ConcreteElementA *pElementA = new ConcreteElementA;
    ConcreteElementB *pElementB = new ConcreteElementB;

    pObject->Attach(pElementA);
    pObject->Attach(pElementB);

    ConcreteVisitor1 *pVisitor1 = new ConcreteVisitor1;
    ConcreteVisitor2 *pVisitor2 = new ConcreteVisitor2;

    pObject->Attach(pVisitor1);
    pObject->Accept(pVisitor2);

    if(pVisitor2) delete pVisitor2;
    if(pVisitor1) delete pVisitor1;
    if(pElementB) delete pElementB;
    if(pElementA) delete pElementA;

    if(pObject) delete pObject;

    return 0;
}

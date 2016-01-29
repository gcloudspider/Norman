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
#include "Originator.h"
#include "Caretaker.h"

int main(){
    Originator* o = new Originator("Old");
    o->show();


    Caretaker* pTaker = new Caretaker();
    pTaker->SetMemento(o->CreateMemento());

    o->SetState("New");
    o->show();

    o->RestoreToMemento(pTaker->GetMemento());
    o->show();

    return 0;
}

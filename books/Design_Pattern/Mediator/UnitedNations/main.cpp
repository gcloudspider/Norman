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
#include "Mediator.h"
#include "ConcreteMediator.h"
#include "ConcreteColleague1.h"
#include "ConcreteColleague2.h"
#include "Colleague.h"

int main(){
    Mediator *pMediator = new ConcreteMediator();

    Colleague *pColleague1 = new ConcreteColleague1(pMediator);
    Colleague *pColleague2 = new ConcreteColleague2(pMediator);

    ConcreteMediator *pConcreteMediator = dynamic_cast<ConcreteMediator *>(pMediator);
    pConcreteMediator->SetColleague1(pColleague1);
    pConcreteMediator->SetColleague2(pColleague2);

    wchar_t message[260] = L"where are you from?";
    pColleague1->Send(message);

    return 0;
}

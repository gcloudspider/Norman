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
#include "ConcreteMediator.h"

void ConcreteMediator::Sent(wchar_t *message, Colleague *pColleague){
    ConcreteColleague1 *pConcreteColleague1 = dynamic_cast<ConcreteColleague1 *>(pColleague);
    if(pConcreteColleague1){
        cout<<"The message is from ConcreteColleague1 Now mediator forward it to ConcreteColleague2"<<endl;

        if(m_pColleague2){
            m_pColleague2->Notify(message);
        }
    }else {
        if(m_pColleague1){
            m_pColleague1->Notify(message);
        }
    }
}

void ConcreteMediator::SetColleague1(Colleague *pColleague){
    m_pColleague1 = dynamic_cast<ConcreteColleague1 *>(pColleague);
}

void ConcreteMediator::SetColleague2(Colleague *pColleague){
    m_pColleague2 = dynamic_cast<ConcreteColleague2 *>(pColleague);
}

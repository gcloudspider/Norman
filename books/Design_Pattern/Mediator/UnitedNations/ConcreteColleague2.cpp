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
#include "ConcreteColleague2.h"

ConcreteColleague2::ConcreteColleague2(Mediator *pMediator)
    :Colleague(pMediator){
    
}

void ConcreteColleague2::Notify(wchar_t *message){
    cout<<"ConcreteColleague2 is handling the message."<<endl;
    cout<<message<<endl;
}

void ConcreteColleague2::Send(wchar_t *message){
    m_pMediator->Sent(message,this);
}

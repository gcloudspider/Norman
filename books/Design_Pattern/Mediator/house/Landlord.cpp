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
#include "Landlord.h"

void Landlord::SetMediator(Mediator *mediator){
    m_mediator = mediator;
}

void Landlord::SendMessage(string message){
    m_mediator->Send(message,this);
}

void Landlord::GetMessage(string message){
    cout<<"房东收到信息"<<message;
}

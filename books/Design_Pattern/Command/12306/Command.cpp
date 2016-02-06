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
#include "Command.h"

Command::Command(Customer *pCustomer)
    :m_pCustomer(pCustomer){
    
}

void Command::SetTicket(CTicket *pTicket){
    m_pTicket = pTicket;
}

Customer *Command::GetCustomer(){
    return m_pCustomer;
}

CBuyTicketCommand::CBuyTicketCommand(Customer *pCustomer)
:Command(pCustomer){
    
}

void CBuyTicketCommand::Execute(){
    m_pTicket->SellTicket();
}

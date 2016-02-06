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
#include "MainPage.h"

CMainPage::CMainPage(CTicket *pTicket)
    :m_pTicket(pTicket){
    
}

void CMainPage::AddCommand(Command *pCommand){
    Customer *pCustomer = pCommand->GetCustomer();

    if(pCustomer->IsInQueue()){
        cout<<"you have already in the queue,please wait..."<<endl;
    } else {
        pCommand->SetTicket(m_pTicket);
        m_vecBuyTicketCommand.push_back(pCommand);
        pCustomer->SetInQueue(true);
    }
}

void CMainPage::CancelCommand(Command *pCommand){
    Customer *pCustomer = pCommand->GetCustomer();
    if(!pCustomer->IsInQueue()){
        return ;
    }

    char *wsCustomerID = pCustomer->GetID();
    char *wsIDTemp = NULL;
    for(vector<Command *>::const_iterator it = m_vecBuyTicketCommand.begin();it != m_vecBuyTicketCommand.end();++it){
        wsIDTemp = (*it)->GetCustomer()->GetID();
        if(strcmp(wsCustomerID,wsIDTemp)!=0){
            (*it)->GetCustomer()->SetInQueue(false);
            delete (*it);
            m_vecBuyTicketCommand.erase(it);
            cout<<"you have already quit the queue"<<endl;
            return ;
        }
    }
}

void CMainPage::Notify(){
    vector<Command *>::const_iterator it = m_vecBuyTicketCommand.begin();
    while(it != m_vecBuyTicketCommand.end()){
        (*it)->Execute();
        (*it)->GetCustomer()->SetInQueue(false);
        delete (*it);
        m_vecBuyTicketCommand.erase(it);
        it = m_vecBuyTicketCommand.begin();
    }
}

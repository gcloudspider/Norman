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
#include "Ticket.h"
#include "Customer.h"


int main(){
    CTicket *pTicket = new CTicket();
    CMainPage *pMainPage = new CMainPage(pTicket);

    Customer *pCustomer1 = new Customer("123");
    pCustomer1->SetMainPage(pMainPage);
    pCustomer1->BuyTicket();
    pCustomer1->BuyTicket();
    pCustomer1->Cancel();

    Customer *pCustomer2 = new Customer("456");
    pCustomer2->SetMainPage(pMainPage);
    pCustomer2->BuyTicket();

    pMainPage->Notify();

    delete pCustomer1;
    delete pCustomer2;

    return 0;
}

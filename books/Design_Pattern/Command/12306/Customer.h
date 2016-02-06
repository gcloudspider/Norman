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
#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
class CMainPage;
class Command;

class Customer{
public:
    Customer(char *ID);
    void SetMainPage(CMainPage *pMainPage);
    void BuyTicket();
    void Cancel();
    char *GetID();
    bool IsInQueue();
    void SetInQueue(bool bInQueue);

private:
    bool m_bInQueue;
    char *m_wsID;
    CMainPage *m_pMainPage;
    Command *m_pCommand;
};

#endif

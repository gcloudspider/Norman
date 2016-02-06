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
#ifndef _MAINPAGE_H_
#define _MAINPAGE_H_
#include <iostream>
#include "Ticket.h"
#include "Command.h"
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

class CMainPage{
public:
    CMainPage(CTicket *pTicket);

    void AddCommand(Command *pCommand);

    void CancelCommand(Command *pCommand);

    void Notify();

private:
    vector<Command *> m_vecBuyTicketCommand;
    CTicket *m_pTicket;

};
#endif

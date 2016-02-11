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
#ifndef _CONCRETECOMMAND_H_
#define _CONCRETECOMMAND_H_
#include "Command.h"
#include "Receiver.h"
class ConcreteCommand:public Command{
public:
    ConcreteCommand(Receiver *pReceiver);
    void Execute();
private:
    Receiver *m_pReceiver;
};

#endif
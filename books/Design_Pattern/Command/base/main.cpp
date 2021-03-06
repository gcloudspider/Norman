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

#include "Receiver.h"
#include "ConcreteCommand.h"
#include "Invoker.h"

int main(){
    Receiver *pReceiver = new Receiver();
    Command *pCommand = new ConcreteCommand(pReceiver);
    Invoker *pInvoker = new Invoker(pCommand);

    pInvoker->Invoke();

    SAFE_DELETE(pInvoker);
    SAFE_DELETE(pCommand);
    SAFE_DELETE(pReceiver);

    return 0;
}

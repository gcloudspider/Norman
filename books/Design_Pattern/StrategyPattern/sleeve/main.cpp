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
#include "Context.h"
#include "BackDoor.h"
#include "GivenGreenLight.h"
#include "BlockEnemy.h"
#include <iostream>
using namespace std;

int main(int argc,char* argv[]){
    CContext *pContext;

    cout<<"\14\n\n\n\n\17"<<endl;
    cout<<"--------------"<<endl;
    pContext = new CContext(new CBackDoor());
    pContext->Operate();
    delete pContext;

    cout<<"--------------"<<endl;
    pContext = new CContext(new CGivenGreenLight());
    pContext->Operate();
    delete pContext;

    cout<<"---------------"<<endl;
    pContext = new CContext(new CBlockEnemy());
    pContext->Operate();
    delete pContext;

    //_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_EF|_CRTDBG_ALLOC_MEM_DF);
    //_CrtDumpMemoryLeaks();
    return 0;
}

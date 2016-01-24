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
#include "IOuterUser.h"
#include "IUserInfo.h"
#include "UserInfo.h"
#include "OuterUserInfo.h"

void DoIt(){
    IUserInfo *pYourGirl = new CUserInfo();
    for(int i=0;i<101;i+=20){
        pYourGirl->GetMobileNumber();
    }
    delete pYourGirl;
}

void NowDoIt(){
    IUserInfo* pYourGirl = new COuterUserInfo();
    for(int i=0;i<101;i+= 20){
        pYourGirl->GetMobileNumber();
    }
    delete pYourGirl;
}

int main(int argc,char* argv[]){
    DoIt();
    NowDoIt();
    
    //_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF|_CRTDBG_ALLOC_MEM_DF);
    //_CrtDumpMemoryLeaks();
    return 0;
}

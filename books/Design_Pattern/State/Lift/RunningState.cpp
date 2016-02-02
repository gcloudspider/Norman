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
#include "RunningState.h"
#include "Context.h"

CRunningState::CRunningState(){

}

CRunningState::~CRunningState(){

}

void CRunningState::Open(){

}

void CRunningState::Close(){

}

void CRunningState::Run(){
    cout<<"电梯上下跑...."<<endl;
}

void CRunningState::Stop(){
    this->CLiftState::m_pContext->SetLiftState(CContext::pStoppingState);
    this->CLiftState::m_pContext->GetLiftState()->Stop();
}



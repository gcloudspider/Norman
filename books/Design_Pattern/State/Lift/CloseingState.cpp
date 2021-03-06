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
#include "CloseingState.h"
#include "Context.h"

CCloseingState::CCloseingState(){

}

CCloseingState::~CCloseingState(){

}

void CCloseingState::Open(){
    this->CLiftState::m_pContext->SetLiftState(CContext::pOpenningState);
    this->CLiftState::m_pContext->GetLiftState()->Open();
}

void CCloseingState::Close(){
    cout<<"电梯门关闭...."<<endl;
}

void CCloseingState::Run(){
    this->CLiftState::m_pContext->SetLiftState(CContext::pRunningState);
    this->CLiftState::m_pContext->GetLiftState()->Run();
}

void CCloseingState::Stop(){
    this->CLiftState::m_pContext->SetLiftState(CContext::pStoppingState);
    this->CLiftState::m_pContext->GetLiftState()->Stop();
}

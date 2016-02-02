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

COpenningState * CContext::pOpenningState = NULL;
CCloseingState * CContext::pCloseingState = NULL;
CRunningState * CContext::pRunningState = NULL;
CStoppingState * CContext::pStoppingState = NULL;

CContext::CContext(){
    m_pLiftState = NULL;
    pOpenningState = new COpenningState();
    pCloseingState = new CCloseingState();
    pRunningState = new CRunningState();
    pStoppingState = new CStoppingState();
}

CContext::~CContext(){
    delete pOpenningState;
    pOpenningState = NULL;
    delete pCloseingState;
    pCloseingState = NULL;
    delete pRunningState;
    pRunningState = NULL;
    delete pStoppingState;
    pStoppingState = NULL;
}

CLiftState * CContext::GetLiftState(){
    return m_pLiftState;
}

void CContext::SetLiftState(CLiftState *pLiftState){
    this->m_pLiftState = pLiftState;
    this->m_pLiftState->SetContext(this);
}

void CContext::Open(){
    this->m_pLiftState->Open();
}

void CContext::Close(){
    this->m_pLiftState->Close();
}

void CContext::Run(){
    this->m_pLiftState->Run();
}

void CContext::Stop(){
    this->m_pLiftState->Stop();
}

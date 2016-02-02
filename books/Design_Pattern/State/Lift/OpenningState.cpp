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
#include "OpenningState.h"
#include "Context.h"

COpenningState::COpenningState(){

}

COpenningState::~COpenningState(){

}

void COpenningState::Open(){
    cout<<"电梯门开启...."<<endl;
}

void COpenningState::Close(){
    this->CLiftState::m_pContext->SetLiftState(CContext::pCloseingState);
    this->CLiftState::m_pContext->GetLiftState()->Close();
}

void COpenningState::Run(){

}

void COpenningState::Stop(){

}



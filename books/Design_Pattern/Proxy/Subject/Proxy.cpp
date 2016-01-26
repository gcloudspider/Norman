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
#include "Proxy.h"

CProxy::CProxy()
:m_pRealSubject(NULL){
    
}

CProxy::~CProxy(){
    SAFE_DELETE(m_pRealSubject);    
}

void CProxy::Request(){
    if(NULL == m_pRealSubject){
        m_pRealSubject = new CRealSubject();
    }
    cout<<"CProxy Request"<<endl;
    m_pRealSubject->Request();
}



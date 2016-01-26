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
#include "ConcreteCompany.h"

CConcreteCompany::CConcreteCompany(string name)
    :CCompany(name){
    
}

CConcreteCompany::~CConcreteCompany(){
    
}

void CConcreteCompany::Add(CCompany *pCom){
    m_listCompany.push_back(pCom);
}

void CConcreteCompany::Show(int depth){
    for(int i=0;i<depth;i++)
        cout<<"-";
    cout<<m_name<<endl;
    list<CCompany *>::iterator iter=m_listCompany.begin();
    for(;iter != m_listCompany.end();++iter)
    (*iter)->Show(depth +2);
}

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

#include "CommonManager.h"

CommonManager::CommonManager(Manager *manager,string name)
:Manager(manager,name){

}

void CommonManager::DealWithRequest(string name,int num){
    if(num < 500){
        cout<<"经理"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl;
    } else {
        cout<<"经理"<<m_name<<"无法处理,交由总监处理"<<endl;
        m_manager->DealWithRequest(name,num);
    }
}

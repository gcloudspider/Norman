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

#include "GeneralManager.h"

GeneralManager::GeneralManager(Manager *manager,string name)
:Manager(manager,name){

}

void GeneralManager::DealWithRequest(string name,int num){
    cout<<"总经理"<<m_name<<"批准"<<name<<"加薪"<<num<<"元"<<endl;
}

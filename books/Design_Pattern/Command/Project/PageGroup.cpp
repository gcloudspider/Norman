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
#include "PageGroup.h"

CPageGroup::CPageGroup(void){

}

CPageGroup::~CPageGroup(void){

}

void CPageGroup::Find(){
    cout<<"找到美工组..."<<endl;
}

void CPageGroup::Add(){
    cout<<"客户要求增加一个页面"<<endl;
}

void CPageGroup::Delete(){
    cout<<"客户要求删除一个页面"<<endl;
}

void CPageGroup::Change(){
    cout<<"客户要求修改一个页面"<<endl;
}

void CPageGroup::Plan(){
    cout<<"客户要求页面变更计划"<<endl;
}

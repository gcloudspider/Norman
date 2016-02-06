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
#include "RequirementGroup.h"

CRequirementGroup::CRequirementGroup(void){

}

CRequirementGroup::~CRequirementGroup(void){

}

void CRequirementGroup::Find(){
    cout<<"找到需求组...."<<endl;
}

void CRequirementGroup::Add(){
    cout<<"客户要求增加一项需求..."<<endl;
}

void CRequirementGroup::Delete(){
    cout<<"要求删除一项需求...."<<endl;
}

void CRequirementGroup::Change(){
    cout<<"客户要求修改一项需求..."<<endl;
}

void CRequirementGroup::Plan(){
    cout<<"客户要求需求变更计划..."<<endl;
}

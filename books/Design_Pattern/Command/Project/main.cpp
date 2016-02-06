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

#include "IGroup.h"
#include "CodeGroup.h"
#include "PageGroup.h"
#include "RequirementGroup.h"
#include "Invoker.h"
#include "AddRequirementCommand.h"
#include "DeletePageCommand.h"

void DoIt(){
    cout<<"---------客户想增加一个需求---------"<<endl;
    IGroup *rg = new CRequirementGroup();
    rg->Find();
    rg->Add();
    rg->Plan();
    delete rg;
    cout<<endl;

    cout<<"---------客户又想修改一个页面-------"<<endl;
    IGroup *pg = new CPageGroup();
    pg->Find();
    pg->Add();
    pg->Plan();
    delete pg;
    cout<<endl;

    cout<<"--------客户又想删除一个功能-------"<<endl;
    IGroup *cg = new CCodeGroup();
    cg->Find();
    cg->Add();
    cg->Plan();
    delete cg;
    cout<<endl;
}

void DoNew(){
    cout<<"----------------------客户得烦了,希望只找一个人,并告诉他要做什么-----------"<<endl;
    cout<<"----------------------客户要求增中一项需求--------------------------------"<<endl;

    CInvoker gary;
    ICommand *pCommand = new CAddRequirementCommand();
    gary.SetCommand(pCommand);
    gary.Action();
    delete pCommand;
    cout<<endl;

    //客户想要改动需求只需找Invoker就可以
    cout<<"-----------------------客户要求删除一个页面--------------------"<<endl;
    CInvoker ricky;
    ICommand *pCommand2 = new CDeletePageCommand();
    ricky.SetCommand(pCommand2);
    ricky.Action();
    delete pCommand2;
    cout<<endl;
}


int main(){
    DoIt();

    DoNew();

    return 0;
}

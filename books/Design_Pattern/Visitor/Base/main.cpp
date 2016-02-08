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
#include "Manager.h"
#include "BaseVisitor.h"
#include "Employee.h"
#include "CommonEmployee.h"

void MockEmployee(vector<CEmployee*> *pvce){
    CCommonEmployee *pZhangSan = new CCommonEmployee();
    pZhangSan->SetJob("编写Java程序,绝对蓝领,苦工加搬运工");
    pZhangSan->SetName("张三");
    pZhangSan->SetSalary(1800);
    pZhangSan->SetSex(CEmployee::MALE);
    pvce->push_back(pZhangSan);

    CCommonEmployee *pLiSi = new CCommonEmployee();
    pLiSi->SetJob("页面美工,审美素质太不流行了!");
    pLiSi->SetName("李四");
    pLiSi->SetSalary(1900);
    pLiSi->SetSex(CEmployee::FEMALE);
    pvce->push_back(pLiSi);

    CManager *pWangWu = new CManager();
    pWangWu->SetPerformance("基本上是负值,但是我会拍马屁呀!");
    pWangWu->SetName("王五");
    pWangWu->SetSalary(1900);
    pWangWu->SetSex(CEmployee::FEMALE);
    pvce->push_back(pWangWu);
}

void DoIt(){
    vector<CEmployee*> vce;
    MockEmployee(&vce);
    vector<CEmployee*>::const_iterator readIt = vec.begin();

    CBaseVisitor visitor;
    for(;readIt !=vce.end();readIt++){
        (*readIt)->Accept(&visitor);
    }
    cout<<"本公司的月工资总额是:"<<CConvert::ToString(visitor.GetTotalSalary()).c_str()<<endl;

    vector<CEmploy*>::reverse_iterator delIt = vce.rbegin();
    for(; delIt != vce.rend();delIt++){
        delete (*delIt);
        (*delIt) = NULL;
    }
    vce.clear();
}

int main(){
    DoIt();
    return 0;
}

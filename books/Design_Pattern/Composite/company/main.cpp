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
#include "Company.h"
#include "ConcreteCompany.h"
#include "FinanceDepartment.h"
#include "HrDepartment.h"

int main(){
    CCompany *root = new CConcreteCompany("总公司");
    CCompany *leaf1 = new CFinanceDepartment("财务部");
    CCompany *leaf2 = new CHRDepartment("人力资源部");
    root->Add(leaf1);
    root->Add(leaf2);

    //分公司
    CCompany *mid1 = new CConcreteCompany("分公司A");
    CCompany *leaf3 = new CFinanceDepartment("财务部");
    CCompany *leaf4 = new CHRDepartment("人力资源部");
    mid1->Add(leaf3);
    mid1->Add(leaf4);
    root->Add(mid1);


    //分公司B
    CCompany *mid2 = new CConcreteCompany("分公司B");
    CFinanceDepartment *leaf5 = new CFinanceDepartment("财务部");
    CHRDepartment *leaf6 = new CHRDepartment("人力资源部");
    mid2->Add(leaf5);
    mid2->Add(leaf6);
    root->Add(mid2);
    root->Show(0);

    delete leaf1;
    delete leaf2;
    delete leaf3;
    delete leaf4;
    delete leaf5;
    delete leaf6;
    delete mid1;
    delete mid2;
    delete root;
    return 0;

}

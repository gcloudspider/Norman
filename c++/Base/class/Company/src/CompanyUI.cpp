/**
* Create Date:2016年03月12日星期六 08:13:12
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#include<iostream>
using namespace std;
#include "../include/CompanyUI.h"

CompanyUI::CompanyUI(){

}

CompanyUI::~CompanyUI(){

}

void CompanyUI::welcomInfo() {
    system("clear");
    cout << "################欢迎使用员工管理系统#############" << endl;
    cout << "                1.显示员工信息                   " << endl;
    cout << "                2.添加员工信息                   " << endl;
    cout << "                3.修改员工信息                   " << endl;
    cout << "                4.计算员工当月工资               " << endl;
    cout << "                5.退出                           " << endl;
    cout << "#################################################" << endl;
    cout << " " << endl;
    cout << "请选择:" <<endl;
}

void CompanyUI::showEmployeeInfo(EmployeeInfo_t& userInfo) {
    system("clear");
    cout << "################欢迎使用员工管理系统#############" << endl;
    cout << "工号\t姓名\t年龄\t性别\t职位" << endl;
    for (auto user : userInfo) {
        cout << user.id << "\t" ;
        cout << user.name << "\t";
        cout << user.age << "\t";
        cout << user.sex << "\t";
        cout << user.post <<endl;
    }
}


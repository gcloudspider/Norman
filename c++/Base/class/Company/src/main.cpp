/**
* Create Date:2016年03月10日星期四 16:33:26
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include <unistd.h>
#include<iostream>
using namespace std;
#include "../include/Company.h"
#include "../include/Common.h"

int CEmployee::m_id = 1000;

Node* packUserNode(int id,const char* name,int age,const char* sex,int type,const char* post,int level) {
    Node* userNode = new Node;
    userNode->id = id;
    strcpy(userNode->name,name);
    userNode->age = age;
    strcpy(userNode->sex,sex);
    userNode->type = type;
    strcpy(userNode->post,post);
    userNode->level = level;
    userNode->basePay = 0;
    userNode->status = 1;
    return userNode;
}

int main() {
    //初始化数据库
    DBManage db;
    db.readDatabase(FILE_STORAGE_PATH);
   //显示欢迎界面
    CompanyUI ui;
    int ch;
    while(1){
        ui.welcomInfo();
        cin>> ch;
        switch(ch) {
            case static_cast<int>(FEATURE::EMPLOYEEINFO): {
                EmployeeInfo_t userInfo;
                if(db.queryUserInfo(userInfo)){
                    ui.showEmployeeInfo(userInfo);
                }
                sleep(3);
                break;
            }
            case static_cast<int>(FEATURE::ADDEMPLOYEE):{
                ui.addUserInfo();
                cin>>ch;
                switch(ch) {
                    case static_cast<int>(POST::SALESMAN): {
                        EmployeeInfo_s saleInfo;
                        ui.addEmployee(saleInfo,ch);
                        CSalesman sale{saleInfo.name,saleInfo.age,saleInfo.sex,1,EMPLOYEE_TITLE_SALESMAN,1};
                        if(db.checkUserExist(sale.getId())){
                            cout << "用户已存在!" << endl;
                        } else {
                            Node* userNode;
                            userNode = packUserNode(sale.getId(),saleInfo.name,saleInfo.age,saleInfo.sex,1,EMPLOYEE_TITLE_SALESMAN,1);
                            if(db.addUserInfo(userNode)) {
                                cout << "添加成功" << endl;
                            }
                            db.writeDatabase(FILE_STORAGE_PATH);
                        }
                        sleep(3);
                        break;
                    }
                    case static_cast<int>(POST::SALEMANAGER): {
                        EmployeeInfo_s saleManagerInfo;
                        ui.addEmployee(saleManagerInfo,ch);
                        CSaleManager saleManager{saleManagerInfo.name,saleManagerInfo.age,saleManagerInfo.sex,1,EMPLOYEE_TITLE_SALEMANAGER,1};
                        if(db.checkUserExist(saleManager.getId())){
                            cout << "用户已存在!" << endl;
                        } else {
                            Node* userNode;
                            userNode = packUserNode(saleManager.getId(),saleManagerInfo.name,saleManagerInfo.age,saleManagerInfo.sex,1,EMPLOYEE_TITLE_SALEMANAGER,3);
                            if(db.addUserInfo(userNode)) {
                                cout << "添加成功" << endl;
                            }
                            db.writeDatabase(FILE_STORAGE_PATH);
                        }
                        sleep(3);
                        break;
                    }
                    case static_cast<int>(POST::TECHNICIAN): {
                        EmployeeInfo_s techInfo;
                        ui.addEmployee(techInfo,ch);
                        CTechnician tech{techInfo.name,techInfo.age,techInfo.sex,1,EMPLOYEE_TITLE_TECHNICIAN,1};
                        if(db.checkUserExist(tech.getId())){
                            cout << "用户已存在!" << endl;
                        } else {
                            Node* userNode;
                            userNode = packUserNode(tech.getId(),techInfo.name,techInfo.age,techInfo.sex,1,EMPLOYEE_TITLE_TECHNICIAN,3);
                            if(db.addUserInfo(userNode)) {
                                cout << "添加成功" << endl;
                            }
                            db.writeDatabase(FILE_STORAGE_PATH);
                        }
                        sleep(3);   
                        break;
                    }
                    case static_cast<int>(POST::MANAGER): {
                        EmployeeInfo_s managerInfo;
                        ui.addEmployee(managerInfo,ch);
                        CManager manager{managerInfo.name,managerInfo.age,managerInfo.sex,1,EMPLOYEE_TITLE_MANAGER,1};
                        if(db.checkUserExist(manager.getId())){
                            cout << "用户已存在!" << endl;
                        } else {
                            Node* userNode;
                            userNode = packUserNode(manager.getId(),managerInfo.name,managerInfo.age,managerInfo.sex,1,EMPLOYEE_TITLE_MANAGER,4);
                            if(db.addUserInfo(userNode)) {
                                cout << "添加成功" << endl;
                            }
                            db.writeDatabase(FILE_STORAGE_PATH);
                        }
                        sleep(3);
                        break;
                    }
                    default:
                        break;
                }
                break;
            }
            case static_cast<int>(FEATURE::MODEMPLOYEE): {
                ui.modifyEmployee();
                unsigned int jobNum;
                cin >> jobNum;
                if(!db.checkUserExist(jobNum)) {
                    cout << "此工号没有用户,请确认!" << endl;
                } else {
                    EmployeeInfo_s userInfo;
                    if(db.queryUserInfo(userInfo,jobNum)){
                        ui.showEmployeeInfo(userInfo);
                    }
                }
                sleep(3);
                break;
            }
            case static_cast<int>(FEATURE::COUNTSALARY):
                break;
            case static_cast<int>(FEATURE::QUIT):
                exit(0);
                break;
            default:
                break;
        }
    }
    return 0;
}

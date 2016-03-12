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

int main() {
    //初始化数据库
    DBManage db;
    db.readDatabase(FILE_STORAGE_PATH);
   //显示欢迎界面
    CompanyUI ui;
    char ch;
    while(1){
        ui.welcomInfo();
        ch = getchar();
        switch(ch) {
            case '1': {
                EmployeeInfo_t userInfo;
                if(db.queryUserInfo(userInfo)){
                    ui.showEmployeeInfo(userInfo);
                }
                sleep(3);
                break;
            }
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                exit(0);
                break;
            default:
                break;
        }
    }
    return 0;
}

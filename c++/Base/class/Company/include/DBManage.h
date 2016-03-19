/**
* Create Date:2016年03月10日星期四 10:03:51
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _DBMANAGE_H
#define _DBMANAGE_H
#include "Common.h"
#include <iostream>
using namespace std;
#include <string>

class DBManage {
public:
    DBManage();
    ~DBManage();

    bool readDatabase(const string& fileName);
    bool writeDatabase(const string& fileName);
    bool addUserInfo(Node*& userNode);
    bool modifyUserInfo();
    bool queryUserInfo(EmployeeInfo_t& userInfo);
    bool queryUserInfo(EmployeeInfo_s& userInfo,unsigned int jobNum);
    bool checkUserExist(unsigned int id);
    void show();

    Node* getHead();
    Node* getTail();

private:
    Node* head;
    Node* tail;
    int size;
};

#endif

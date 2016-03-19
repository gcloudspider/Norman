/**
* Create Date:2016年03月10日星期四 10:27:22
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
#include "../include/Company.h"

int main() {
    DBManage db;
    db.readDatabase(FILE_STORAGE_PATH);
    db.show();
    db.writeDatabase(FILE_STORAGE_PATH);
    return 0;
}

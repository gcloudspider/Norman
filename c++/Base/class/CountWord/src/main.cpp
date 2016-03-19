/**
* Create Date:2016年03月14日星期一 16:20:16
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
#include "../include/Comman.h"
#include "../include/FileManage.h"
int main() {
    CFileManage* file = new CFileManage();
    file->readFileToTree(FILE_STORAGE_PATH);
    file->show();
    return 0;
}

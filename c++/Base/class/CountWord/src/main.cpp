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
    Map_t map_file;
    Tuple_t tuple_file;

    CFileManage* file = new CFileManage();
    //file->readFileToMap(FILE_STORAGE_PATH,tuple_file);
    file->readFileToMap(FILE_STORAGE_PATH,map_file);
    file->printMap(map_file);

    return 0;
}

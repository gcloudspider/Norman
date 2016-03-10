/**
* Create Date:2016年03月10日星期四 13:37:26
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _STRUCT_H
#define _STRUCT_H

#define FILE_STORAGE_PATH "../db/employee.txt"

enum pType {
    FULLTIME,
    PARTTIME
};

enum jobStatus {
    ONJOB,
    RESIGN
};

struct Node {
    unsigned long id;
    char name[20];
    int age;
    char sex[4];
    int type;
    char post[20];
    int level;
    float basePay;
    int status;
    Node* next;
    Node* pre;
};

#endif

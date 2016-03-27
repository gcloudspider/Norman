/**
* Create Date:2016年03月26日 20:23:11
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _LISTSTRUCT_H
#define _LISTSTRUCT_H
struct Node {
    int data;
    Node* next;
};

void createList(Node* p);

int isEmpty(Node* head);

#endif

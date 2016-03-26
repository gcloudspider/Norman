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
typedef struct Node *pNode;
typedef int Item;

typedef struct Node {
    Item data;
    pNode next;
}node;

typedef pNode Pos;
typedef pNode List;

List createList(List);

int isEmpty(List);

List makeList();

List invert(List);

int islast(int pos);

int length(List);

void traverseList(List);
#endif

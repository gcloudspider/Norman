/**
* Create Date:2016年03月 7日星期一 08:28:01
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _SLINKLIST_H
#define _SLINKLIST_H
typedef struct Node* pNode;
typedef int Item;

typedef struct Node {
	Item data;
	pNode next;
}node;

typedef pNode Position;
typedef pNode List;

//创建空链表*并返回链表指针**/

List create_slinklist();
#endif

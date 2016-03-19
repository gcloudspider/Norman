/**
* Create Date:2016年03月14日星期一 16:14:31
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _COMMAN_H
#define _COMMAN_H
#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;
#define FILE_STORAGE_PATH  "../db/file.txt"

struct Node {
    string word;
    int cout;
    string line;
    Node* left;
    Node* right;
};

using Node_t  = Node;
using Vector_t = vector<int>;

#endif

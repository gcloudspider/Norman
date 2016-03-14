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
    map<string,int> word_map;
    vector<int> word_vector;
    Node* left;
    Node* right;
};

using Tuple_t = tuple<map<string,int>,vector<int>>;
using Map_t = map<string,int>;

#endif

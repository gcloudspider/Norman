/**
* Create Date:2016年03月14日星期一 16:12:16
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#ifndef _FILEMANAGE_H
#define _FILEMANAGE_H
#include "Comman.h"

class CFileManage {
public:
    CFileManage();
    ~CFileManage();
    
    void readFileToTree(const char* filename);
    
    void toLower(string& s);
    string intToString(int i);

    Node& Add(string word,string line);
    
    Node* Push(Node* p,string word,string line);
    
    int getCount();
    void Destory(Node* p);
    void show();
    void Print(Node* p);
private:
    Node* root_;
    int count_;

};

#endif

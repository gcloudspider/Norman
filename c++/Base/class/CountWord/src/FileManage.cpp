/**
* Create Date:2016年03月14日星期一 16:18:02
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
#include "../include/FileManage.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <algorithm>

CFileManage::CFileManage():
    root_(nullptr),count_(0){
}

CFileManage::~CFileManage() {
    Destory(root_);
    root_ = nullptr;
}

void CFileManage::toLower(string& s) {
    transform(s.begin(),s.end(),s.begin(),::tolower);
}

string CFileManage::intToString(int i) {
    stringstream ss;
    string lines;
    ss << i;
    ss >> lines;
    return lines;
}

Node& CFileManage::Add(string word,string line) {
    root_ = Push(root_,word,line);
    return *this->root_;
}

Node* CFileManage::Push(Node* p,string word,string line) {
    if(p == nullptr) {
        p = new Node{word,1,line,nullptr,nullptr};
        count_++;
    } else {
        if((p->word.compare(word))>0){
            p->left = Push(p->left,word,line);             
        } else if ((p->word.compare(word))<0) {
            p->right = Push(p->right,word,line);
        } else {
            p->cout++;
            p->line.append(",");
            p->line.append(line);
            count_++;
        }
    }
    return p;
}

void CFileManage::readFileToTree(const char* filename) {
    ifstream FileStream;
    int i = 1;
    string Line,Word;
    FileStream.open(filename);

    if (!FileStream)
        cout << "Open File Stream Failed!" << endl;

    while (getline(FileStream, Line)) {
        //cout << "Line: "<< i << endl;
        istringstream instream(Line);
        while(instream >> Word) {
            toLower(Word);
            Add(Word,intToString(i));
        }
        i++;
    }
    
    FileStream.close();
}

void CFileManage::Destory(Node* p) {
    if (p != nullptr) {
        Destory(p->left);
        Destory(p->right);
        delete p;
    }
}

int CFileManage::getCount() {
    return count_;
}

void CFileManage::show() {
    cout << "Word\t" << "Count\t" << "Lines" << endl;
    cout << "----------------------" << endl;
    Print(root_);
    cout << "Total\t" << getCount() << endl;
}

void CFileManage::Print(Node* p) {
    if(p != nullptr) {
        Print(p->left);
        cout << p->word <<"\t" << p->cout << "\t" << p->line << endl;
        Print(p->right);
    }
}

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

CFileManage::CFileManage() {

}

CFileManage::~CFileManage() {

}

void CFileManage::readFileToMap(const char* filename,Map_t& map_file) {
    ifstream FileStream;
    string Line, Word;
    FileStream.open(filename);
    int i = 1;

    if (!FileStream)
        cout << "Open File Stream Failed!" << endl;

    while (getline(FileStream, Line)) {
        istringstream instream(Line);
        while(instream >> Word) {
            auto it = map_file.find(Word);
            if(it != map_file.end()) {
                map_file[Word] = i++;                                   
            }
            map_file[Word] = i;
         //   cout << Word << endl;
        }
    }
    
    FileStream.close();
}

void CFileManage::readFileToMap(const char* filename,Tuple_t& tuple_file) {
    ifstream FileStream;
    string Line, Word;
    FileStream.open(filename);
    int i = 1;

    if (!FileStream)
        cout << "Open File Stream Failed!" << endl;

    while (getline(FileStream, Line)) {
        istringstream instream(Line);
        while(instream >> Word) {
            cout << Word << endl;
        }
    }
    
    FileStream.close();
}

void CFileManage::printMap(Map_t& map_file) {

    cout << "Word\t" << "Count\t" << "Lines" << endl;
    cout << "------------------------------" << endl;
    for ( auto it = map_file.begin(); it != map_file.end(); ++it) {
        cout << it->first << "\t" << it->second << endl;
    }

    cout << "Total\t" << endl;
}

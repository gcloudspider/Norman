/**
* Create Date:2016年03月15日星期二 14:57:22
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include <fstream>
#include<iostream>
using namespace std;


int main(int argc,char* argv[]) {
    if (argc <3 ) return -1;

    fstream ifs(argv[1],ios::in);

    if (!ifs.is_open()) {
        perror("fstream:");
        return -1;
    }

    ifs.seekg(0,ios::end);
    unsigned long total = ifs.tellg();
    ifs.seekg(0,ios::beg);

    for (auto i = 2;i<argc;++i) {
        fstream ofs(argv[i],ios::out);
        char buf[4];
        int readNum = 0;
        int size = 0;
        while(readNum < total) {
            ifs.read(buf,4);
            size = ifs.gcount();
            readNum += size;
            ofs.write(buf,size);
        }
        ifs.seekg(0,ios::beg);
    }
}

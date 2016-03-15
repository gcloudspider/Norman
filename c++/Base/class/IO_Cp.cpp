/**
* Create Date:2016年03月15日星期二 11:18:38
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
#include <fstream>

int main(int argc,char* argv[]) {
    if(argc != 3) return -1;

    fstream ifs(argv[1],ios::in);
    if(!ifs.is_open()) {
        cout << "Open file failed!" << endl;
    }
    
    fstream ofs(argv[2],ios::out);
    char c;
    while(!ifs.eof()){
        ifs.read(&c,1);
        ofs.write(&c,1);
    }
    return 0;
}

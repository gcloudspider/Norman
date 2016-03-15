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
    ifs.seekg(0,ios::end);              //去到文件末尾
    unsigned long total = ifs.tellg();  //获取文件当前位置
    ifs.seekg(0,ios::beg);              //回到文件开头

    
    char buf[4];
    int readNum = 0;                    //读取总数
    int size = 0;                       //当前读取多少个字符

    while(readNum < total){
        ifs.read(buf,4);
        size = ifs.gcount();
        readNum += size;

        ofs.write(buf,size);
    }
    return 0;
}

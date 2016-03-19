/**
* Create Date:2016年03月15日星期二 11:07:10
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include<fstream>
#include<iostream>
using namespace std;

//ifstream  写文件
//ofstream  读文件
//
//fstream   读写文件 
//
//mode如下:
//ios::in   以读的方式打开文件
//ios::out  以写的方式打开文件(会清空文件内容,若文件不存在则创建)
//ios::app  追加
//ios::binary 二进制
//ios::trunc    清空文件
//ios::ate  打开一个已存在的文件,并定位到文件末尾
//
//ios::beg      开始位置
//ios::cur      当前位置
//ios::end      位置
//
//tellp()       获取写文件指针当前的位置
//tellg()       获取读文件指针当前的位置
//
//seekp(off,from)   设置写文件指针的位置
//seekg(off,from)   设置读文件指针的位置
//
int main() {
    char buf[1024]={'\0'};
    fstream fs("t.txt",ios::in);
    fstream os("g.txt",ios::out);
    os.put('a');
    os.write("hello",5);
    os.seekp(1);
    os.put('b');
    os.seekp(0,ios::end);
    os.put('v');

    int off = os.tellp();
    cout << "off = " << off << endl;

    bool b = fs.is_open();
    cout << "b = " << b << endl;

    char c = fs.get();
    cout << "c=" << c << endl;

    fs.getline(buf,1024);
    cout << "buf = " << buf << endl;

    fs.read(buf,1024);
    cout << "buf=" << buf << endl;
    cout << "eof=" << fs.eof() <<endl;  //不到末尾为0 读到末尾为1
    //fs.write("hello",5);
    //fs.write(" world",6);
    fs.close();
}

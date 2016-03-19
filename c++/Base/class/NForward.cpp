/**
* Create Date:2016年03月18日星期五 09:57:42
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

void printValue(int& i) {
    cout << "left value:" << i << endl;
}

void printValue(int&& i) {
    cout << "right value:" <<i << endl;
}

void forward(int&& i) {
    printValue(i);          //编译器将已命名的右值引用视为左值
}

int main() {
    int k = 0;
    printValue(k);
    printValue(6);
    forward(2);
    return 0;
}

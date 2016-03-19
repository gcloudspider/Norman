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

template<typename T>
void printValue(T& i) {
    cout << "left value:" << i << endl;
}

template<typename T>
void printValue(T&& i) {
    cout << "right value:" <<i << endl;
}

template<typename T>
void forw(T&& i) {
    printValue(i);                      //编译器将已命名的右值引用视为左值
    printValue(move(i));
    printValue(forward<T>(i));          //传进来的为左值 或右值 完美转发成左值或右值
}

template<typename T>
void ggg(T&& i) {

}

int main() {
    int k = 333;
    forw(1);
    forw(k);
    return 0;
}

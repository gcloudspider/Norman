/**
* Create Date:2016年03月 9日星期三 14:58:17
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

//编译器合成的函数:
//  1.无参构造函数(如果类没有任何构造函数)
//  2.拷贝构造函数
//  3.赋值运算符重载函数

#include<iostream>
using namespace std;

class Base {
public:
    Base() = default;               //要求编译器合成无参构造函数
    Base(const Base& b) = delete;   //禁止编译器合成拷贝构造函数
    Base& operator=(const Base& b) = delete;    //禁止编译器合成赋值运算符重载函数
    Base(int n):m(n) {}
private:
    int m;
};

int main() {
    Base a;
    //Base b(a);  //Base b = a;
    Base c;
    //c = b;
}

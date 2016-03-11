/**
* Create Date:2016年03月11日星期五 09:06:45
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//通过访问虚函数表访问非公有的虚函数
#include<iostream>
using namespace std;

class Base {
    private:
        virtual void f() {cout << "Base::f()" << endl;}
        virtual void g() {cout << "Base::g()" << endl;}
        virtual void h() {cout << "Base::h()" << endl;}
};

class Derive: public Base {

};

typedef void(*Fun)(void);

int main() {
    Derive d;
    Fun pFun = (Fun)*((int*)*(int*)(&d)+0);
    Fun gFun = (Fun)*((int*)*(int*)(&d)+1);
    Fun hFun = (Fun)*((int*)*(int*)(&d)+2);
    pFun();
    gFun();
    hFun();
}




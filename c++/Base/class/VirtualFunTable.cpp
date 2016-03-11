/**
* Create Date:2016年03月10日星期四 20:48:41
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

class Base {
public:
    virtual void f() {cout << "Base::f" << endl;}
    virtual void g() {cout << "Base::g" << endl;}
    virtual void h() {cout << "Base::h" << endl;}
};

typedef void(*Fun)(void);

int main() {

    Base b;
    Fun pFun = NULL;
    Fun gFun = NULL;
    Fun hFun = NULL;
    //强行将&b转换为int* 取得虚函数表的地址
    cout << "虚函数表地址: " << (int*)(&b) << endl;
    //
    cout << "虚函数表 -- 第一个函数地址:" << (int*)*(int*)(&b) << endl;

    pFun = (Fun)*((int*)*(int*)(&b));
    pFun();

    gFun = (Fun)*((int*)*(int*)(&b)+1);
    gFun();

    hFun = (Fun)*((int*)*(int*)(&b)+2);
    hFun();
    
    return 0;
}

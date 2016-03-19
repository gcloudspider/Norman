/**
* Create Date:2016年03月 9日星期三 17:20:26
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//纯虚函数也有实现函数体
//原因:希望基类不能产生对象,但又希望将公用代码放在基类
//
//解决方法:可以使用纯虚函数,并为纯虚函数定义函数体


//不能为纯虚函数类(抽象类) 定义对象

#include<iostream>
using namespace std;

class Base {
public:
    virtual void v() const = 0;
    virtual void f() const = 0;
};

void Base::v() const {
    cout << "Base::v()" << endl;
}

void Base::f() const {
    cout << "Base::f()" << endl;
}

class Derived: public Base {
public:
    void v() const {
        Base::v();
    }

    void f() const {
        Base::f();
    }
};

int main() {
    Derived D;
    D.v();
    D.f();

    //Base b;

    return 0;
}


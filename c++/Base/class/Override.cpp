/**
* Create Date:2016年03月 9日星期三 14:41:11
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//Override与final区别:
//final放在函数禁止后面继承重写函数
//final放在类禁止被继承

#include<iostream>
using namespace std;


class A {
public:
    A(int x):x_(x) {}
    virtual void show() {cout << "x=" << x_ << endl;}

protected:
    int x_;
};

class B final:public A{
public:
    B(int x,int y):A(x),y_(y) {}

    void show() final {
        cout << "x = " << x_ << endl;
        cout << "y = " << y_ << endl;
    }
protected:
    int y_;
};
/*
class C : public B {
public:
    C(int x ,int y,int z) : B(x,y),z_(z) {}

    void show() override {
        cout << "x = " << x_ << endl;
        cout << "y = " << y_ << endl;
        cout << "z = " << z_ << endl;
    }


protected:
    int z_;
};
*/

int main() {
    auto p1 = new B(1,2);
    p1->show();
    delete p1;
}

/**
* Create Date:2016年03月13日星期日 21:26:36
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

//类声明或继承了一个或多个Virtual 函数
//虚函数,编译器会在编译期间发生如下操作:
//1.虚函数表会被编译器产生而来,用于存放为类的virtual函数地址
//2.在每一个类的对象内,一个额外的指针成员会被编译器合成出来,这个指针就是指向虚函数表的指针(vptr)
//3.编译器改写虚函数的调用
//
//编译器合成默认构造函数会为类安插一个vptr 并指定其初值,使其指向该类的虚函数表.
//若该类已经定义了构造函数.编译会为每个构造函数安插代码来做同样的事情(vptr 并设定初始值)
//
//意义:使virtual 函数机制(多态)可以正确地生效
#include<iostream>
using namespace std;

class X {
public:
    virtual ~X(){
        cout << "X::~X()" << endl;
    }

    virtual void print() {
        cout << "X::print()" << endl;
    }
    int mData;
};


class XX:public X {
public:
    virtual ~XX(){
        cout << "XX::~XX()" << endl;
    }

    virtual void print() {
        cout << "XX::print()" << endl;
    }

    int mN;
};

int main(){
    X *x = new XX;
    x->print();
    delete x;

    //改写如下:
    //X *x = malloc(sizeof(XX));
    //x->vptr = XX::vtbl;
    //(x->vptr[1])(x);  //1为print函数在vtbl中索引
    //(x->vptr[0])(x);  //0为析构函数在vtbl的索引
    //
    //free(x);
    return 0;
}

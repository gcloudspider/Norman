/**
* Create Date:2016年03月17日星期四 10:12:15
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//智能指针缺陷:
//  1.不要用原始指针初始化智能指针
//  2.不要用智能指针做函数参数
//  3.不要通过shared_from_this()返回this指针
//  4.不要循环引用
//
#include <memory>
#include<iostream>
using namespace std;

struct B;

struct A {
    A() {cout << "Create A" <<endl;}
    ~A() {cout << "Destory A" << endl;}

    shared_ptr<B> pb;
};

struct B{
    B() {cout << "Create B" << endl;}
    ~B() {cout << "Destory B" << endl;}

    //   shared_ptr<A> pa;      //解决循环引用
    weak_ptr<A> pa;
};

int main() {
    shared_ptr<A> a(new A);
    shared_ptr<B> b(new B);
    a->pb = b;
    b->pa = a;
    
}

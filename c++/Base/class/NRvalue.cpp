/**
* Create Date:2016年03月18日星期五 09:19:08
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//左值:
//
//右值:
//  1.将亡值
//  2.纯右值
//
//区分左值和右值的方法:
//1.若可对表达式用&符取地址,则为左值
//2.

//int&& i =0;       i为0的别名 --- &&右值引用符
//
//右值的特征:
//1.右值不具有名字
//2.只能通过引用的方式找到右值
//3.右值引用只是右值的别名
//4.通过右值引用声明,右值临时变量的生命周期将变长
//                   和左值的生命周期一样

#include<iostream>
using namespace std;

struct A {
    A(int m) {cout << "Create A" << endl;}
    A(const A& a) {cout << "XXX Create" << endl;}
    ~A() {cout << "Destory " << endl;}
};

A func() {
    return A(4);
}

void fun(string s) {
    cout << s << endl;
}

int main() {
    int i = 0;                      //i为左值  0为右值
    int j = i;                      //j为右值 
    fun(string("hello"));           //string("hello")为右值
    //func(A(4));
    A&& y =  func();
}

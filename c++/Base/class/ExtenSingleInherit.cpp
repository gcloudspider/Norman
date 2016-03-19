/**
* Create Date:2016年03月11日星期五 11:04:22
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
//单一继承
//
class Parent {
public:
    int iparent;
    Parent():iparent(10) {}
    virtual void f() {cout << "Parent::f()" << endl;}
    virtual void g() {cout << "Parent::g()" << endl;}
    virtual void h() {cout << "Parent::h()" << endl;}
};

class Child: public Parent {
public:
    int ichild;
    Child():ichild(100) {}
    virtual void f() {cout << "Child::f()" << endl;}
    virtual void g_child() {cout << "Child::g_child()" << endl;}
    virtual void h_child() {cout << "Child::h_child()" << endl;}
};

class GrandChild : public Child {
public:
    int igrandchild;
    GrandChild():igrandchild(1000) {}
    virtual void f() {cout << "GrandChild::f()" << endl;}
    virtual void g_child() {cout << "GrandChild::g_child()" << endl;}
    virtual void h_grandchild() {cout << "GrandChild::h_grandchild()" << endl;}
};

typedef void(*Fun)(void);

int main() {
    GrandChild gc;
    int** pVtab = (int**)&gc;
    
    cout << "[0] GrandChild::_vptr->" << endl;

    for(int i=0;(Fun)pVtab[0][i] != NULL;i++) {
        Fun pFun = (Fun)pVtab[0][i];
        cout << " ["<<i<<"] ";
        pFun();
    }

    cout << "[1] Parent.iparent = " << (int)pVtab[1] <<endl;
    cout << "[2] Child.ichild = " << (int)pVtab[2] << endl;
    cout << "[3] GrandChild.igrandchild = " << (int)pVtab[3] << endl;
    return 0;
}

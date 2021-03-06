/**
* Create Date:2016年03月11日星期五 09:11:47
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//多重继承的虚函数表访问的例子:

#include<iostream>
using namespace std;
/*      Vtab
 *          Base1 
 *              Derive::f()     Base1::g()  Base1::h()  
 *          Base2
 *              Derive::f()     Base2::g()  Base2::h()
 *          Base3
 *              Derive::f()     Base3::g()  Base3::h()
 * */

class Base1 {
public:
    virtual void f() {cout << "Base1::f()" << endl;}
    virtual void g() {cout << "Base1::g()" << endl;}
    virtual void h() {cout << "Base1::h()" << endl;}
};


class Base2 {
public:
    virtual void f() {cout << "Base2::f()" << endl;}
    virtual void g() {cout << "Base2::g()" << endl;}
    virtual void h() {cout << "Base2::h()" << endl;}
};

class Base3 {
public:
    virtual void f() {cout << "Base3::f()" << endl;}
    virtual void g() {cout << "Base3::g()" << endl;}
    virtual void h() {cout << "Base3::h()" << endl;}
};

class Derive :public Base1,public Base2,public Base3 {
public:
    virtual void f() {cout << "Derive::f()" << endl;}
    virtual void g1() {cout << "Derive::g1()" << endl;}
};

typedef void(*Fun)(void);

int main() {
    Fun pFun = nullptr;

    Derive d;
    int** pVtab = (int**)&d;

    //Base1's vtable
    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+0);
    pFun = (Fun)pVtab[0][0];
    pFun();

    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+1);
    pFun = (Fun)pVtab[0][1];
    pFun();

    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+2);
    pFun = (Fun)pVtab[0][2];
    pFun();

    //Derive's vtable
    //违反C++语义访问未覆盖父类的成员函数g1()
    //pFun = (Fun)*((int*)*(int*)((int*)&d+0)+3);
    pFun = (Fun)pVtab[0][3];
    pFun();
    //虚表的最后一个节点是否为1或是为0
    //为1表示还有下一个虚表
    //The tail of the vtable
    pFun = (Fun)pVtab[0][4];
    cout << pFun << endl;

    //Base2's vtable
    //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);
    pFun = (Fun)pVtab[1][0];
    pFun();

    //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);
    pFun = (Fun)pVtab[1][1];
    pFun();

    pFun = (Fun)pVtab[1][2];
    pFun();

    //The tail of the vtable
    pFun = (Fun)pVtab[1][3];
    cout << pFun << endl;

    //Base3's vtable
    //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+0);
    pFun = (Fun)pVtab[2][0];
    pFun();

    //pFun = (Fun)*((int*)*(int*)((int*)&d+1)+1);
    pFun = (Fun)pVtab[2][1];
    pFun();

    pFun = (Fun)pVtab[2][2];
    pFun();

    //The tail of the vtable
    pFun = (Fun)pVtab[2][3];
    cout << pFun << endl;

    

    return 0;
}

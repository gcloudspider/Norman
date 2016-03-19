/**
* Create Date:2016年03月17日星期四 11:08:05
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//Shared_ptr 智能指针循环释放缺陷:
//
#include<iostream>
#include <memory>
using namespace std;
/*
struct A {
    A() {cout << "Create A" << endl;}
    ~A() {cout << "Destory A" << endl;}
    
    share_ptr<A> getSelf() {
        shared_ptr<A>(this);
        return p;
    }
};
*/

//enable_shared_from_this内部使用弱引用智能指针
struct A : public enable_shared_from_this<A>{
    A(){ cout << "Create A" << endl;}
    ~A() {cout << "Destory A" << endl;}

    shared_ptr<A> getSelf() {
        return shared_from_this();
    }
};

int main() {
    shared_ptr<A> sp1(new A);
    shared_ptr<A> sp2 = sp1->getSelf();
}


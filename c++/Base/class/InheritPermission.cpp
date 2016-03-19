/**
* Create Date:2016年03月 9日星期三 10:44:30
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

// 0    不可访问    (内部和外部都不能直接访问)
// 1    private     (内部可访问,外部不可访问)
// 2    protected   (内部可访问,外部不可访问)
// 3    public      (内部和外部都能直接访问)
//
// 派生类访问性 = min(基类访问性,继承方式)
//  例子:
//  派生类访问是private (1) = min(基类是private (1),继承方式是public (3) )

/*
 *特殊点: 基类是私有的(private) 派生类里永远是不可访问的
 * */


/*
 *注意:如果基类是私有的不能使用 ----- using 重新定义权限
 * */
#include<iostream>
using namespace std;

class Base {
public:
    Base(int n): n_(n) {}

protected:
    int n_;
};

class Derived :public Base {
public:
    Derived(int n) : Base(n) {}
    void show(){
        cout << "n=" << n_ << endl;
    }
    using Base::n_;
};

int main() {
    Derived a(3);
    a.show();
}

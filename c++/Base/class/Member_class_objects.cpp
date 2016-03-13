/**
* Create Date:2016年03月13日星期日 08:44:08
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//类含有成员类对象(member class objects)
//一个类没有任何构造函数,但它的成员变是一个有默认构造函数的类的变量
//此时编译器合成默认构造函数
#include<iostream>
using namespace std;

class X {
    public:
        X(){
            mData = 0;
            cout << "X::X()" << endl;
        }
        int mData;
};

class Xs {
public:
    /*
     *inline Xs::Xs(){mX.X::X()};
     * */

    X mX;           //成员变量mx是类型X 且X类拥有一个默认构造函数
                    //此时合成默认构造函数,调用X的构造函数为成员变量mX进行初始化
    int mN;         //没有为mN进行初始化
};

int main() {
    Xs xs;
    cout << xs.mX.mData << endl;
    cout << xs.mN << endl;
    return 0;
}


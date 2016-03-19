/**
* Create Date:2016年03月13日星期日 21:39:51
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

//类派生自一个继承串链,其中有一个或更多的Virtual 基类
//
//virtual 基类的实现方法，不同编译器实现有差异
//但每一种实现共同点是必须使virtual 基类在其每一个派生类对象中位置,能够在执行期间准备妥当

//编译器会为我们定义的构造函数安插必要的代码来实现Virtual基类机制,若类没有声明任何构造函数,编译器必须合成一个默认构造函数来完成相同操作
//注意:若基类X中有virtual函数 则还会安插一个X::vptr 

#include<iostream>
using namespace std;

class X {
public:
    X() {mData = 100;}
    int mData;
};

class X1 : virtual public X{
public:
    X1() {mX1 = 101;}
    int mX1;
};

class X2 : virtual public X {
public:
    X2() {mX2 = 102;}
    int mX2;
};

class XX: public X1,public X2{
public:
    XX() {mXX = 103;}
    int mXX;
};

int main() {
    cout << "sizeof(XX): " << sizeof(XX) << endl;

    XX xx;
    int *p = (int*)&xx;
    for(int i=0;i<sizeof(XX)/sizeof(int);++i,++p){
        cout << *p << endl;
    }

    return 0;
}


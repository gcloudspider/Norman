/**
* Create Date:2016年03月17日星期四 13:41:27
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//强制类型转换
//
//
#include<iostream>
using namespace std;
class Base {
public:
    virtual void  show() {
        cout << "Base" << endl;
    }
};

class Derivde : public Base{
public:
    void show() override {
        cout << "Derivde" << endl;
    }
};

int main() {
    Derivde a;
    Base* bp = &a;
    //Derivde* dp = bp;   
    Derivde* dp = dynamic_cast<Derivde*>(bp);   //1.用于基于继承关系 2.基类有虚函数
    
    double PI = 3.14;
    int d = static_cast<int>(PI);

    int i = 4;
    const int*p = &i;
    int* r = const_cast<int*>(p);       //去掉底层的const 不能去掉顶层const

    int x = 4;
    int* y = &x;
    long z = reinterpret_cast<long>(y);     //跨类型转换()
    cout << z << endl;
}

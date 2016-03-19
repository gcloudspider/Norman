/**
* Create Date:2016年03月14日星期一 08:45:43
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//注意:Base 要有虚函数否则dynamic_cast报错
//static_cast则没有这个限制
//
//dynamic_cast转换符只能用于指针或引用 
//dynamic_cast转换符只能用于含有虚函数的类
//dynamic_cast操作符在执行类型转换时首先将检查能否成功转换
//  如果成功转换则转换
//  如果转换失败,如果是指针则返回一个0值,如果转换是引用,则抛出一个bad_cast异常,所以在使用dynamic_cast转换之间应使用if语句对其转换成功与否进行测试


//dynamic_cast能将基类类型指针或引用安全地转换为派生类型的指针或引用(通过运行时类型识别(RTTI)---程序能够使用基类的指针或引用来检索这些指针或引用所指对象的实际派生类型)

#include<iostream>
using namespace std;

class Base {
public:
    virtual void print(){
        cout << "I am base virtual print" << endl;
    }
    int n;
};

class Derive : public Base {
public:
    void print() {
        cout << "I am Derive virtual print" << endl;
    }

    void print_non_vir() {
        cout << "I am Derive no virtual print " << endl;
    }
};

int main() {
    Base b;
    Derive d;
    Base* pbb  = &b;
    Base* pbd = &d;
    pbd->print();
    //pbd->print_non_vir();  基类访问派生类函数
    dynamic_cast<Derive*>(pbd)->print_non_vir();

    //dynamic_cast<Derive*>(pbb)->n = 2;

    static_cast<Derive*>(pbd)->print_non_vir();
    return 0;
}


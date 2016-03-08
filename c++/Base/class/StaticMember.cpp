/**
* Create Date:2016年03月 8日星期二 10:39:46
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

class Person {
public:
    Person(int id,string name):id_(id),name_(name) {
        num++;
    }

    static int getNum() {                                   //静态成员函数不能访问非静态成员(可以访问静态成员)
        return num;                                         //静态成员函数没有this指针
    }

private:
    int id_;
    string name_;
    static int num;                                         //静态成员变量所有对象共享
};

int Person::num = 0;                                        //静态成员要在类外进行初始化

int main() {
    Person a(1,"Anni");
    Person b(2,"Tom");

    cout << "a.num=" << a.getNum() << endl;
    cout << "b.num=" << b.getNum() << endl;                      //对象方式访问
    cout << "Person::num=" << Person::getNum() << endl;     //类方式访问(作用域)
    return 0;
}

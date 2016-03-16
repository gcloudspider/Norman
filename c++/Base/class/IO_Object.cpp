/**
* Create Date:2016年03月15日星期二 17:12:42
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
    Person();
    Person(int i,string name):id_(i),name_(name) {}
    ~Person(){}
private:
    int id_;
    string name_;
};


int main(){
    Person a(1,"");
    Person b(2,"");

    Person c;
    Person d;


}

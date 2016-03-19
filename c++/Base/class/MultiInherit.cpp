/**
* Create Date:2016年03月 9日星期三 15:10:02
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

//虚继承:忽略第二次继承NoId

#include<iostream>
using namespace std;

class NoId {
public:
    NoId(int id) : id_(id){}
    int id_;
};

class Person : virtual public NoId {                //virtual 虚继承
public:
    Person(int id,string name,int age):
        NoId(id),
        name_(name),
        age_(age) {
        
    }

    string name_;
    int age_;
};

class Teacher : virtual public NoId {                   //virtual 虚继承
public:
    Teacher(int id,string school,string specialty):
        NoId(id),
        school_(school),
        specialty_(specialty) {
        
    }

    string school_;
    string specialty_;
};

class Professor : public Person,public Teacher {
public:
    Professor(int id,string name,int age,string sc,string sp,string title):
        NoId(id),
        Person(id,name,age),
        Teacher(id,sc,sp),
        title_(title) {
        
    }

    string title_;
}; 

int main() {
    Professor pa(10001,"李教授",34,"北大","化学","");
    
    return 0;
}

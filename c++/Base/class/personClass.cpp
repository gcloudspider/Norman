/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include <iostream>
using namespace std;


class Person {
//class默认是private
public: 
    //构造函数(无返回值,函数名与类名一致)：
    //初始化列表
    Person (int id,string name,int age):
        id_(id),
        name_(name),
        age_(age) {
    }

    //拷贝构造函数
    Person(const Person& p) :
        id_(p.id_),
        name_(p.name_),
        age_(p.age_) {
        
    }

    //explicit 禁止该构造函数发生隐式转换
    //explicit 只能作用于一个参数的构造函数上
    //explicit Person(const char* s) : name_(s) {
    Person(const char* s) : name_(s) {

    }

    //委托构造函数
    Person(int id) : Person(id,"unkown",32) {
    //explicit Person(int id) : Person(id,"unkown",32) {
        
    }

    void show() {
        cout << "id :" << id_ << endl;
        cout << "name :" << name_ << endl;
        cout << "age :" << age_ << endl;
    }
protected:
    int id_;
    string name_;
    int age_;

};

int main() {
    Person tonny(1,"tonny",30);
    tonny.show();
    
    cout << "--------------" << endl;
    //Person norman(tonny);
    Person norman = tonny;
    norman.show();
    
    cout << "--------------" << endl;
    Person norman1("norman");
    norman1.show();

    cout << "--------------" << endl;
    Person norman2 = "hello";           
    //隐匿类型转换:
    //1.生成匿名临时对象tmp Person tmp("hello")
    //2.再进行拷贝构造函数  Person norman2 = tmp;
    norman2.show();
    
    cout << "--------------" << endl;
    Person norman3(3);
    norman3.show();
    cout << "--------------" << endl;
    Person norman4 = 5;
    norman4.show();
    return 0;
}

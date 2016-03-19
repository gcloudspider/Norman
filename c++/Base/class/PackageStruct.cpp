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

struct Person {
    int id_;
    string name_;
    int age_;
    int salary_ = 100;
    void show() {
        cout << "in show fun" << endl;
    }
    
    void show(Person& p) {
        cout << "id = " << p.id_ << endl;
        cout << "name = " << p.name_ << endl;
        cout << "salary = " << p.salary_ << endl;
        cout << "age = " << p.age_ << endl;
    }
    //在结构体中编译器默认添加this
    //void showPerson(Person* const this)
    void showPerson() {
        cout << "id = " << this->id_ << endl;
        //编译器添加this->name_
        cout << "name = " << name_ << endl;
        cout << "salary = " << this->salary_ << endl;
        cout << "age = " << this->age_ << endl;
    }


    int getSalary() {
        return salary_;
    }

    int getAge() {
        return age_;
    }
};

int main(){
    Person tonny;
    tonny.id_ = 1;
    tonny.name_ = "Tonny";
    tonny.age_ = 20;
    cout << "salary = " << tonny.salary_ << endl;

    tonny.show();
    cout << "getSalary= " << tonny.getSalary() << endl;
    cout << "getAge= " << tonny.getAge() << endl;

    cout << "--------------tonny------------" << endl;
    tonny.show(tonny);

    cout << "--------------tonny this-------" << endl;
    //调用时编译器默认传递对象tonny
    //tonny.showPerson(&tonny) 编译器默认添加
    tonny.showPerson();
}

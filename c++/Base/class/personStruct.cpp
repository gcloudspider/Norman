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
//默认是public
    void init(int id,string name,int age) {
        id_ = id;
        name_ = name;
        age_ = age;
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
    Person tonny;
    tonny.init(1,"tonny",30);
    tonny.show();
    return 0;
}

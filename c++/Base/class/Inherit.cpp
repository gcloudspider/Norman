/**
* Create Date:2016年03月 8日星期二 15:48:06
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

class Base {
public:
    Base() { cout << "Create A Object" << endl;}
    ~Base() { cout << "Destory A Object" << endl;}
    int get() {return i;};
    void set(int n) {i=n;}
    void show() {cout << "i= " << i << endl;}
protected:
    int i;
};

class Derived :public Base {
public:
    Derived() {cout << "Create Der Object"<< endl;}
    ~Derived() {cout << "Destory Der Object" << endl;}
    void fun() {
        j = i*2+5;
    }
    void showJ(){
        cout << "j= " << j << endl;
    }
protected:
    int j;
};

int main() {
    Derived a;
    a.set(10);
    a.show();
    a.fun();
    a.showJ();
    return 0;
}

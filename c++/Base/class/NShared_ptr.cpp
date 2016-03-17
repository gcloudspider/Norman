/**
* Create Date:2016年03月17日星期四 09:28:30
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include<memory>
#include<iostream>
using namespace std;

/*
 *一个对象可以被多个智能指针引用,智能指针维护一个计数器
 *如果某个智能指针过期,计数器会减一,直到计数器为0 智能指针指向的对象就会被释放
 * */

class Data {
public:
    Data(int n):m(n) {cout << "Create Data" << endl;}
    ~Data(){ cout << "Destory Data" << endl;}
    void show(){cout << "m=" << m << endl;}

private:
    int m;
};

int main() {
    shared_ptr<Data> p(new Data(3));
    shared_ptr<Data> p1 = make_shared<Data>(3);
    shared_ptr<Data> p2 = p1;

    cout << "p1 use = " << p1.use_count() << endl;
    
    cout << "p use = " << p.use_count() << endl;
    shared_ptr<Data> t = p;
    cout << "p use = " << p.use_count() << endl;
    cout << p.get() << endl;
    cout << t.get() << endl;
    t->show();

    p1.reset();
    shared_ptr<Data> p3 = p1;
    cout << "p1 use = " << p1.use_count() << endl;

    return 0;
}

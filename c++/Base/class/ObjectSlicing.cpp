/**
* Create Date:2016年03月 9日星期三 16:23:13
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
/*
 *当多态处理对象时,传地址与传值有明显不同
 如果使用对象而不是地址或引用进行向上映射,对象会被"切片"
 * */

#include<iostream>
using namespace std;

class Base {
public:
    Base(int i=0):i_(i){}
    virtual int sum() const {
        return i_;
    }

private:
    int i_;
};


class Derived : public Base {
public:
    Derived(int i=0, int j=0):
        Base(i),
        j_(j) {
        
    }
    
    int sum() const {
        return Base::sum() + j_;
    }

private:
    int j_;
};
//call函数只接收Base对象 
//调用call将Base 大小相同的对象压栈,并在调用后清除
//如果一个Base派生类对象传给call 编译器接受他,但只拷贝这个对象对应于Base的部分,切除这个对象的派生类部分
//
void call(Base b) {
    cout << "sum= "<< b.sum() << endl;
}

int main() {
    Base b(10);
    Derived d(10,17);
    call(b);
    call(d);

    system("pause");
    return 0;
}


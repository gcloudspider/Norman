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
#include <stdlib.h>
using namespace std;

class Integer {
public:
    //explicit 关键字不允许该构造函数进行隐式类型转换
    //explicit Integer(int v) {
    Integer(int v) {
        value = new int(v);
    }
    
    //拷贝构造函数
    Integer(const Integer& t) {
        value = new int(*t.value);
    }

    ~Integer() {
        cout << "destory" << endl;
        delete value;
    }

    //所有成员函数都有this指针
    //int get() const
    //     |
    //     V
    //int get(const Integer* const this)
    //const 修改函数里成员不可改变
    int get() const {
        //*value
        //  |
        //  V
        //*(this->value)
        return *value;
    }
private:
    int* value;
};

int main() {
    //Integer a(5);
    Integer a = 7;  //隐式类型转换---->调用Integer(int v)构造函数
    Integer b(a);
    cout << "a= " << a.get() << endl;
    cout << "b= " << b.get() << endl;

    Integer* p1 = (Integer*)malloc(sizeof(Integer));
    free(p1);

    Integer* p2 = new Integer(5);
    delete p2;

    return 0;
}

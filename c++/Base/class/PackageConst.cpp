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

class Integer {
public:
    Integer(int value):num(value),sum(0) {  }
    //int get(Integer* const this)
    int get() const {return num;}
    //int sum(const Integer* const this)
    int sun() const {
        sum = num + 2;
        //this->sum = this->num +2;
        return sum;
    }

private:
    const int num;
    //sum所属的对象是常量 sum仍然可改变
    mutable int sum;
};


int main() {
    const Integer a(5);
    //a.sug(&a);   编译器默认生成
    cout << "sum= " << a.sun() << endl;
    cout << "a= " << a.get() << endl;
    return 0;
}

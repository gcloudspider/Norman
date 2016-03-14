/**
* Create Date:2016年03月13日星期日 09:01:15
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//类的基类带有默认构造函数:
//一个没有任何构造函数的类派生自一个带有默认构造函数的类
#include<iostream>
using namespace std;

class X {
public:
    X() {
        mData = 0;
        cout << "X::X()" << endl;
    }

    int mData;
};
//XX没有任何构造函数,但其基类X存在一个默认构造函数
//类有多个构造函数,提供构造函数并不显式调用基类构造函数
//编译器会扩张派生类的每一个现在自定义的构造函数.将要调用必要默认构造函数代码插进去 ----- 确保类的基类子对象得到初始化
//由于已经存在用户自定义的构造函数,所以编译器不再合成新的构造函数
class XX : public X {
    public:
        XX() {
            mN = 1;
        }
        XX(int n){
            mN = n;
        }
        int mN;
};

class XXX: public XX {

};

int main() {
    XX xx1;
    XX xx2(2);
    return 0;
}

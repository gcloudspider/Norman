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
class XX : public X {
    public:
        int mN;
};

class XXX: public XX {

};

int main() {
    XX xx;
    cout << xx.mData << endl;
    cout << xx.mN << endl;

    XXX xxx;
    return 0;
}

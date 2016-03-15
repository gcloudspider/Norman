/**
* Create Date:2016年03月14日星期一 08:28:51
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

class Test {
public:
    Test(int m_=0):m(m_) {}
public:
    int m;
};

int main(){
    const Test t1;
    //转换为指针类型
    Test* t2 = const_cast<Test*>(&t1);

    //转换为引用类型
    Test& t3 = const_cast<Test&>(t1);

    t2->m = 2;
    cout << "t1.m = " << t1.m << endl;

    t3.m = 3;
    cout << "t1.m = " << t1.m << endl;

}

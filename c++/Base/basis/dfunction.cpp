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
//函数默认参数
#include <iostream>
using namespace std;

void fun1(int a,int b) {
    cout << a + b << endl;
}

void fun2(int a,int b=4) {
    cout << a + b << endl;
}

int compareNum(int x,int y,int z =-217300000) {
    int m = x > y ? x : y;
    int w = m > z ? m : z;
    return w;
}

int main() {
    fun1(3,2);
    fun2(6);
    fun2(6,5);

    cout << "较大的数为: " << compareNum(2,4) << endl;
    cout << "较大的数为: " << compareNum(2,4,6) << endl;
}

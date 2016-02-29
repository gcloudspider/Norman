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
//using 别名函数指针
using Functor = int(*)(int);

//阶乘1
int factor1(int n) {
    int s = 1;
    if (n>1) {
        s=factor1(n-1);
        s *= n;
    }
    return s;
}

int factor2(int n) {
    if (n<=1){
        return 1;
    } else {
        return n* factor2(n-1);
    }
}

int factor3(int n) {
    if (n<=1){
        return 1;
    } else {
        return n+ factor3(n-1);
    }
}

int buset(int n,Functor fun) {
    int s ;
    s = fun(n);
    return s;
}

int main(){
    //定义变量pfun
    Functor pfun = factor1;
    cout << pfun(6) << endl;

    cout << factor1(10) << endl;
    cout << factor2(10) << endl;

    cout << buset(5,factor2) << endl;
    cout << buset(6,factor3) << endl;
}

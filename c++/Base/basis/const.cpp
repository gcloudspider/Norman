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
#include<iostream>
using namespace std;

int main(){
    int a = 8;
    int b = 6;
    const int* p1 = &a;          //p指向地址可变,p所指向的空间内容不可变
    //*p = 5;  错误
    p1 = &b;

    int* const p2 = &a;          //p指向地址不可变,p所指向的空间内容可变
    *p2 = 6;
    //p = &b;  错误
    
    //底层const  顶层const
    //  |        |
    //  V        V
    const int* const p3 = &a;    //p指向地址和p指向空间内容都不可变
    //*p = 6;  错误
    //p = &b;  错误
    
    int x = 6;
    int* p4 = &x;
    int*& p5 = p4;

    *p5 = 8;
    cout << "a=" << a << endl;

    int ival = 100;
    //int& rval1 = 101;   //别名赋初始值 101是int型

    //整数既可为内容也可以为地址
    const int& rval2 = 201;
    int const& rvalc = 301;


    int* pi = &ival;   //引用的地址赋值给指针是正常
    //int& rval4 = pi; //指针地址不能给引用

    int*& prval1 = pi; //指针赋值给指针引用
    int& rval5 = *pi;  //指针的指针 赋值给引用 (二级指针的引用)

    //int& rval3 = &ival; //&ival为int* 指针不能给引用
    //const int& rvalp = &ival;  

    //const int*& prval3 = &ival;
    int* const& prval2 = &ival;
}

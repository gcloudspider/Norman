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
/*
 * POD类型:具有static成员,成员typedef 嵌套struct/class定义和成员函数/方法
 *
*C++98/03对象初始化方法:
*    1.拷贝初始化
*    2.直接初始化
*    3.列表初始化

*c++98/03初始化与C++11统一初始化区别:
*    统一初始化:可以直接在变量名后面跟上初始化列表,来进行对象的初始化(用一对大括号表示)
*
* */


#include <iostream>
using namespace std;

int main(){
    char g;
    int num = 0;        //拷贝初始化
    int sum(1);         //直接初始化
    int kum = {3};      //列表初始化
    int bum{4};         //列表初始化

    double PI = 3.14;
    int a = PI;
    cout<<a<<endl;
    int b = {PI};       //列表初始化时不能丢失数据(此为错误)
    cout<<b<<endl;

    int buf1[3] = {1,2,3};
    int buf2[3]{1,2,3};
    int buf3[3] = {0};
    int buf4[3] = {};

    //auto不能用于数组自动推导
    //错误auto buf6[] = {1,2,3,4};
    //C++11可自动推导
    int buf6[] = {1,2,3,4};
    int buf7[]{1,2,3,4};
    
    for (auto i:buf1) {
        cout <<"buf1: "<<i<<endl;
    }

    for (auto i:buf2) {
        cout<<"buf2:"<<i<<endl;
    }

}

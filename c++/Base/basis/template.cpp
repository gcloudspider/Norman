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
####模板改进:
    1.模板右尖括号:
        C++98/03中模板实例化连续两个右尖括号会被编译器解释成右移操作符,而不是模板参数表的结束
        C++11中使用()括号解决:
            Foo<(100 >> 2)>xx;

    2.模板别名:
        C++98/03: typedef 重定义一个类型
        C++11: using别名

    3.函数模板的默认模板参数:
        C++98/03: 允许类模板可以有默认模板参数/不允许函数的默认模板参数
        C++11: 可以直接使用函数模板参数
*/
#include<iostream>
using namespace std;

template<typename R=int,typename U>
R func(U val){
    return val;
}

int main(){
    func(123);
    return 0;
}

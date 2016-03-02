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
/*
* C++11 之前不支持auto
*/
//C++11 不支持自动推导返回类型
//C++11 推荐使用decltype解决返回类型问题
/*
####decltype关键字新特性:
    decltype与auto区别:
        1.auto修饰的变量必须初始化,编译器通过初始化确定auto代表类型
        2.编译时推导出一个表达式的类型

####C++14与C++11 decltype关键字:
    C++11 新增decltype(a+b)
    C++14 取消了decltype

auto add(int a,int b)->decltype(a+b){
    int i = a+b;
    return i;
}
*/

//C++14已支持
auto add(int a,int b){
    int i = a+b;
    return i;
}


int main(int argc,char **argv){
    int a = 0;
    const int b = 1;
    int& c = a;

    decltype(a) k = a*2;
    decltype(b) y = b+1; //能处理顶层const
    //y = 9; 编译错误
    decltype(c) x = c;  //能处理引用

    x = 80;
    cout << "C=" << c << endl;
    cout << "a=" << a << endl;

    try{
        std::cout<<add(1,2)<<std::endl;
    }catch(std::exception const &e){
        std::cerr << e.what()<<std::endl;
    }
}

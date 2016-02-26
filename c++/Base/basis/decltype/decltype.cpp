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
/*
* C++11 之前不支持auto
*/
//C++11 不支持自动推导返回类型
//C++11 推荐使用decltype解决返回类型问题
/*
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
    try{
        std::cout<<add(1,2)<<std::endl;
    }catch(std::exception const &e){
        std::cerr << e.what()<<std::endl;
    }
}

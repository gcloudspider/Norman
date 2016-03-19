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

//与inline区别:
//  inline是将代码拷贝到调用处并未执行运算
//  constexpr 在编译期间进行运算得到结果
//
constexpr int fac(int n) {
    return 3*n;
}


int main() {
    int s = fac(5);
}

/**
* Create Date:2016年03月18日星期五 10:13:50
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//调用move意味着:
//  1.除了对i赋值或销毁外,将不再使用它
//  2.可以重新给i赋值,但不能再使用i原来的值了
//
#include<iostream>
using namespace std;

int main() {
    int i =7;
    int&& j = move(i);
    int k = i;
    cout << "k = " << k << endl;
}

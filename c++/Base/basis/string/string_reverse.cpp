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

//深入解密C++宽字符
//1.字符到整数:char所能表示字符在C/C++中都是整数类型
//2.本地化策略集(locale):
//  将ASCII范围内的编码与char的整数值对应起来(特定系统和特定编译器制定)
//3.C/C++编译策略:
//  windows 使用L 说明是宽字符,编译器根据locale来翻译，硬编码到程序文件中
//  Linux 
//  C/C++编译策略:硬编码 (程序源码经编译器编译后成相对应ASCII码,要与在内存中表示一致)
#include<iostream>
#include<string>
#include <stdio.h>
#include <string.h>
using namespace std;


int main(){
    string s1;
    string s2;
    getline(cin,s1);
    s2.resize(s1.size());

    int n = s1.size();
    for (int i = 0; i<n; i++) {
        if (s1[i] > 0 && s1[i] < 127) {
            s2[n-i-1] = s1[i];
        } else {
            s2[n-i-3] = s1[i];
            s2[n-i-2] = s1[i+1];
            s2[n-i-1] = s1[i+2];
            i += 2;
        }
    }

    cout << "s1=" << s1 << endl;
    cout << "s2=" << s2 << endl;
    return 0;
}

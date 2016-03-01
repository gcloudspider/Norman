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

//函数重载
#include <iostream>
#include <string.h>
using namespace std;

int comNum(int a,int b) {
    return a>b?a:b;
}

double comNum(double a,double b) {
    return a>b?a:b;
}

string comNum(string a, string b) {
    return a>b?a:b;
}


//函数模板
template<typename T>
T comNum1(T a,T b) {
    return a>b?a:b;
}

int main() {
    cout << comNum(2,4) << endl;
    cout << comNum(2.3,4.0) << endl;
    cout << comNum("bbb","ccc") << endl;


    cout << comNum1<string>("aaa","bbb") << endl;
    cout << comNum1<double>(2.3,2.4) << endl;
    cout << comNum1<int>(12,19) << endl;

    //模板参数自动推导
    //string 推导为char* (跟编译器有关)
    cout << comNum1("aaa","bbb") << endl;
    cout << comNum1<string>("aaa","bbb") << endl;
    cout << comNum1(2.3,2.4) << endl;
    cout << comNum1(12,19) << endl;
    
    return 0;
}

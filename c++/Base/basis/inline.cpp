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
#define MAX1(a,b) (a)>(b)?(a):(b)

int MAX2(int a,int b){
    return a > b ? a : b;
}

inline int MAX3(int a,int b){
    return a > b ? a : b;
}

int main(){

    int x = 3;
    int y = 4;
    int s = MAX1(x++,++y);
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    cout << "s=" << s << endl;

    int a = 3;
    int b = 4;

    int c = MAX2(a++,++b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;

    
    int h = 3;
    int i = 4;
    int j = MAX3(h++,++i);
    cout << "h=" << h << endl;
    cout << "i=" << i << endl;
    cout << "j=" << j << endl;
}

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
#include <functional>
#include <numeric>

int myfunction(int x,int y) {return x+2*y;}

struct myclass {
    int operator()(int x, int y) {return x+3*y;}
}myobject;

int main() {
    int init = 100;
    int numbers[] = {10,20,30};

    //默认
    cout << "using default accumulate: ";
    cout << accumulate(numbers,numbers+3,init);
    cout << endl;

    //
    cout << "using functional's minus: ";
    cout << accumulate(numbers,numbers+3,init,minus<int>());
    cout << endl;
    //自定义函数
    cout << "usingng custom function: ";
    cout << accumulate(numbers,numbers+3,init,myfunction);
    cout << endl;

    cout << "using custom object: ";
    cout << accumulate(numbers,numbers+3,init,myobject);
    cout << endl;

    return 0;
}

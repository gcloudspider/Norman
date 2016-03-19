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

int myop(int x,int y) {return x+y+1;}

int main() {
    int val[] = {1,2,3,4,5};
    int result[5];

    partial_sum(val,val+5,result);
    cout << "using default partial_sum: ";
    for(int i = 0; i< 5;i++) cout << result[i] << ' ';
    cout << endl;

    partial_sum(val,val+5,result,multiplies<int>());
    cout << "using functional operation multiplies: ";
    for(int i=0;i<5;i++) cout << result[i] << ' ';
    cout << endl;

    partial_sum(val,val+5,result,myop);
    cout << "using custom function: ";
    for(int i=0;i<5;i++) cout<< result[i] << ' ';
    cout << endl;
    return 0;
}

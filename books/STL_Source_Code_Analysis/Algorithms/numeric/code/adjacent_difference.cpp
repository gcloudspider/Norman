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
#include <functional>
#include <numeric>
using namespace std;

int myop(int x,int y) {return x+y;}

int main() {
    int val[]  = {1,2,3,5,9,11,12};
    int result[7];

    adjacent_difference(val,val+7,result);
    cout << "using default adjacent_difference: ";
    for(int i=0;i<7;i++) cout << result[i] << ' ';
    cout << endl;

    adjacent_difference(val,val+7,result,multiplies<int>());
    cout << "using functional operation multiplies: ";
    for(int i=0;i<7;i++) cout << result[i] << ' ';
    cout << endl;

    adjacent_difference(val,val+7,result,myop);
    cout << "using custom function: ";
    for(int i=0;i<7;i++) cout << result[i] << ' ';
    cout << endl;
    return 0;
}

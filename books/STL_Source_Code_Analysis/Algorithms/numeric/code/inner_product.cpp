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
#include <iostream>
#include <functional>
#include <numeric>

int myaccumulator(int x,int y) { return x - y; }
int myproduct(int x,int y) {return x+y;}

int main() {
    int init = 10;
    int series1[] = {10,20,30};
    int series2[] = {1,2,3};

    cout << "using default inner_product: ";
    cout << inner_product(series1,series1+3,series2,init);
    cout << endl;

    cout << "using functional operatorions: ";
    cout << inner_product(series1,series1+3,series2,init,minus<int>(),divides<int>());
    cout << endl;

    cout << "using custom functions: ";
    cout << inner_product(series1,series1+3,series2,init,myaccumulator,myproduct);
    cout << endl;
    return 0;
}

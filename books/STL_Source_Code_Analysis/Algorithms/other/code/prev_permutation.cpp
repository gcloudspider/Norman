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
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
/*
prev_permutation获得[first,last)区间所标示序列的上一个排列组合,若果没有上一个排列组合,则返回false 否则返回true
*/

int main() {
    int myints[] = {1,2,3};

    sort(myints,myints+3);
    reverse(myints,myints+3);

    cout << "the 3! possible permutations with 3 elements:"<< endl;
    do {
    	cout << myints[0] << ' ' <<myints[1] << ' ' << myints[2] << endl;
    }while(prev_permutation(myints,myints+3));

    cout << "After loop: "<< myints[0] << ' ' <<myints[1] << ' ' << myints[2] << ' ' << endl;
    return 0;
}

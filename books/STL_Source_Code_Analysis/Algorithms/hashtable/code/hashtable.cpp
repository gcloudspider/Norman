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
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int myints[] = {10,20,30,30,20,10,10,20};
    vector<int> v(myints,myints+8);

    sort(v.begin(),v.end());

    vector<int>::iterator low,up;
    low = lower_bound(v.begin(),v.end(),20);
    up = upper_bound(v.begin(),v.end(),20);

    cout << "lower_bound at position " << (low-v.begin()) << endl;
    cout << "upper_bound at position " << (up -v.begin()) << endl;
    return 0;
}

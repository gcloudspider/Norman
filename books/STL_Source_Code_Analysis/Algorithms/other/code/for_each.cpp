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
#include <vector>
using namespace std;

void myfunction(int i) {
    cout << " " << i;
}

struct myclass {
    void operator() (int i) {cout << " " << i;}
}myobject;

int main() {
    vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(20);
    myvector.push_back(30);

    cout << "myvector contains:";
    for_each(myvector.begin(),myvector.end(),myfunction);
    cout << endl;

    cout << "myvector contains: ";
    for_each(myvector.begin(),myvector.end(),myobject);
    cout << endl;

    return 0;
}

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

bool myfunction(int i, int j) {
    return (i==j);
}

int main() {
    int myints[] = {5,20,5,30,30,20,10,10,20};
    vector<int> myvector (myints,myints+8);
    vector<int>::iterator it;

    it = adjacent_find(myvector.begin(),myvector.end());

    if(it != myvector.end()) 
        cout << "the first pair of repeated elements are: " << *it << endl;

    it = adjacent_find(++it,myvector.end(),myfunction);

    if(it != myvector.end())
        cout << "the second pair of repeated elements are:" << *it << endl;

    return 0;
}

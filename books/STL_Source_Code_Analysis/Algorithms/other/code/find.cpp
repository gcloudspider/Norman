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
#include <algorithm>
#include <vector>

bool IsOdd(int i) {
    return ((i%2) == 1);
}

int main() {
    vector<int> myvector;
    myvector.push_back(10);
    myvector.push_back(25);
    myvector.push_back(40);
    myvector.push_back(55);

    vector<int>::iterator it = find_if(myvector.begin(),myvector.end(),10);
    cout << "The first odd value is " <<*it << endl;

    it = find(myvector.begin(),myvector.end(),40);
    if(it != myvector.end()) 
        cout << "Element found in myvector: " << *it << endl;
    else 
        cout << "Element not found in myints" << endl;

    return 0;
}

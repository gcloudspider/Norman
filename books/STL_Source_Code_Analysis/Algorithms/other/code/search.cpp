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

bool mypredicate(int i,int j) {
    return (i==j);
}

int main() {
    int myints[] = {10,20,30,20,20,10,10,20};
    vector<int> myvector(myints,myints+8);
    vector<int>::iterator it;

    it = search_n(myvector.begin(),myvector.end(),2,30);
    if(it != myvector.end())
        cout << " two 30s found at position " << (it-myvector.begin()) << endl;
    else 
        cout << "match not found" << endl;

    it = search_n(myvector.begin(),myvector.end(),2,10,mypredicate);
    if(it != myvector.end())
        cout << "two 10s found at position" << int(it-myvector.begin()) << endl;
    else 
        cout << "match not found" << endl;

    int needle1[] = {10,20};

    it = search(myvector.begin(),myvector.end(),needle1,needle1+2);
    if(it!=myvector.end())
        cout << "needle1 found at position " << (it-myvector.begin()) <<endl;
    else 
        cout << "needle1 not found"<< endl;

    int needle2[] = {30,20,10};
    it = search(myvector.begin(),myvector.end(),needle2,needle2+3,mypredicate);
    if(it != myvector.end())
        cout << "needle2 found at position " << (it-myvector.begin()) << endl;
    else 
        cout << "needle2 not found" << endl;

    return 0;
}

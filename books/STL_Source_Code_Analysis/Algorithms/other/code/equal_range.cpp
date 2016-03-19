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

bool mygreater(int i,int j) {return (i>j);}

int main() {
    int myints[] = {10,20,30,30,20,10,10,20};
    vector<int> v(myints,myints+8);
    
    pair<vector<int>::iterator,vector<int>::iterator> bounds;

    sort(v.begin(),v.end());
    bounds = equal_range(v.begin(),v.end(),20);

    cout << "bounds at positions " << (bounds.first - v.begin());
    cout << " and " << (bounds.second - v.begin()) << endl;

    sort(v.begin(),v.end(),mygreater);

    bounds = equal_range(v.begin(),v.end(),20,mygreater);

    cout << "bounds at positions " << (bounds.first - v.begin());
    cout << " and " << (bounds.second - v.begin()) << endl;

    return 0;
}

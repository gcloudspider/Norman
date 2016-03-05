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
#include<iostream>
using namespace std;
#include <map>

int main() {
    map<char,int> mymap;

    mymap['a'] = 10;
    mymap['b'] = 20;
    mymap['c'] = 30;
    
    pair<map<char,int>::iterator,map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');

    cout << "lower bound points to: ";
    cout << ret.first->first << " => " << ret.first->second << endl;

    cout << "upper bound points to: ";
    cout << ret.second->first << " => " << ret.second->second << endl;
    
    return 0;
}

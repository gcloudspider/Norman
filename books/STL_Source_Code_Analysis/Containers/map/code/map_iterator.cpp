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
#include <map>
using namespace std;

int main() {
    map<char,int> mymap;
    map<char,int>::iterator itlow,itup;

    mymap['a'] = 20;
    mymap['b'] = 40;
    mymap['c'] = 60;
    mymap['d'] = 80;
    mymap['e'] = 100;

    itlow = mymap.lower_bound('b');
    itup = mymap.upper_bound('d');

    mymap.erase(itlow,itup);

    for(map<char,int>::iterator it = mymap.begin(); it!= mymap.end();++it) {
        cout << it->first << "=>" << it->second << endl;
    }
    return 0;
}

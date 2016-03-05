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
#include <string>
using namespace std;

int main() {
    map<char,string> mymap;
    mymap['a'] = "an element";
    mymap['b'] = "another element";
    mymap['c'] = mymap['b'];

    cout << "mymap['a'] is " << mymap['a'] << endl;
    cout << "mymap['b'] is " << mymap['b'] << endl;
    cout << "mymap['c'] is " << mymap['c'] << endl;
    cout << "mymap['d'] is " << mymap['d'] << endl;

    cout << "mymap now contains " << mymap.size() << "element." << endl;
    
    return 0;
}

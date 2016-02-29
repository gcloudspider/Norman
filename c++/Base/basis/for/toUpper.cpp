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

string toUpper(string s) {
    for (auto& c : s) {
        if (c >= 'a' || c <='z') {
            c -= 32;
        }
    }
    return s;
}

int main() {
    string ret;
    string str = "this is a pig";
    ret = toUpper(str);
    cout << "s=" << ret << endl;
    return 0;
}

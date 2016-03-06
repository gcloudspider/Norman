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

int main() {
    vector<int> foo(5,10);
    vector<int> bar(5,33);

    swap_ranges(foo.begin()+1,foo.end(),bar.begin());

    cout << "foo contains:";
    for(vector<int>::iterator it=foo.begin();it != foo.end();++it)
        cout << ' ' << *it;
    cout << endl;

    cout << "bar contains:";
    for(vector<int>::iterator it=bar.begin();it != bar.end();++it)
        cout << ' ' << *it;
    cout << endl;

    return 0;
}

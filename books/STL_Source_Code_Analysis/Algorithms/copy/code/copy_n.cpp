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
    int myints[] = {10,20,30,40,50,60,70};
    vector<int> myvector;
    myvector.resize(7);

    copy_n(myints,7,myvector.begin());

    cout << "myvector contains:";
    for(vector<int>::iterator it = myvector.begin();
        it!= myvector.end();++it) {
        cout<< " " << *it;
        }
    cout << endl;
    return 0;
}

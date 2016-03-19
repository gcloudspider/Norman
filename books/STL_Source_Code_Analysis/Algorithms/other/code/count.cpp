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

bool IsOdd(int i) { return ((i%2)==1); }

int main() {
    int myints[] = {10,20,31,30,21,10,11,20};
    int mycount = count(myints,myints+8,10);
    cout << "10 appears " << mycount << " times" << endl;

    vector<int> myvector (myints,myints+8);
    mycount = count(myvector.begin(),myvector.end(),20);
    cout << "20 appears " << mycount << " times" << endl;

    mycount = count_if(myvector.begin(),myvector.end(),IsOdd);
    cout << "myvector contains " << mycount << " odd values" << endl;
    
    return 0;
}

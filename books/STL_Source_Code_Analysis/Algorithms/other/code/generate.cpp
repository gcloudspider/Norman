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
using namespace std;

int current = 0;
int UniqueNumber() {return ++current;}

int main() {
    int myarray[9];

    generate_n (myarray,9,UniqueNumber);
    
    cout << "myarray contains:";
    for(int i=0;i<9;++i)
    	cout << ' ' << myarray[i];
    cout << endl;
    cout << "the value of current: " << current;
    cout << endl;

    vector<int>myvector(6);
    generate (myvector.begin(),myvector.end(),UniqueNumber);

    cout << "myvector contains:";
    for(vector<int>::iterator it = myvector.begin(); it != myvector.end();++it)
    	cout << ' ' << *it;
    cout << endl;
 
    return 0;
}

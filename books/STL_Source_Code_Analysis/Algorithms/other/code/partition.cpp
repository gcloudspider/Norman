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

bool IsOdd(int i) {return (i%2)==1;}

int main() {
    vector<int> myvector;
    
    for(int i=1;i<10;++i) myvector.push_back(i);

    vector<int>::iterator bound;
    bound = partition(myvector.begin(),myvector.end(),IsOdd);
    
    cout << "odd elements:";
    for(vector<int>::iterator it = myvector.begin(); it!= bound;++it)
    	cout << ' ' << *it;
    cout << endl;

    cout << "even elements:";
    for(vector<int>::iterator it=bound; it != myvector.end(); ++it)
    	cout << ' ' << *it;
    cout << endl;

    return 0;
}

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
#include <functional>
#include <vector>
#include <cctype>
using namespace std;

bool myfunction(int i,int j) {
	return (i==j);
}

int main() {
    int myints[]  = {1,2,3,4,5,1,2,3,4,5};
    vector<int> haystack(myints,myints+10);

    int needle1[] = {1,2,3};

    vector<int>::iterator it;
    it = find_end(haystack.begin(),haystack.end(),needle1,needle1+3);

    if(it != haystack.end()) 
    	cout << "needle1 last found at position " << (it-haystack.begin()) << endl;

    int needle2[] = {4,5,1};

    it = find_end(haystack.begin(),haystack.end(),needle2,needle2+3,myfunction);

    if(it != haystack.end())
        cout << "needle2 last found at position " << (it-haystack.begin()) << endl;

    return 0;
}

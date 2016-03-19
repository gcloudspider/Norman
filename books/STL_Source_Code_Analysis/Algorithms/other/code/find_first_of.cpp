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

bool comp_case_insensitive(char c1,char c2) {
    return tolower(c1) == tolower(c2);
}

int main() {
    int mychars[] = {'a','b','c','A','B','C'};
    vector<char> haystack(mychars,mychars+6);
    vector<char>::iterator it;

    int needle[] = {'A','B','C'};

    it = find_first_of(haystack.begin(),haystack.end(),needle,needle+3);

    if(it != haystack.end()) 
    	cout <<"The first match is:" <<*it << endl;

    it = find_first_of(haystack.begin(),haystack.end(),needle,needle+3,comp_case_insensitive);

    if(it != haystack.end())
    	cout <<"the first match is: " <<*it << endl;

    return 0;
}

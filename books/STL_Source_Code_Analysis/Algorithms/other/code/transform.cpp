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
using namespace std;

int op_increase(int i) {return ++i;}

int main() {
    vector<int> foo;
    vector<int> bar;

    for(int i=1;i<6;i++)
    	foo.push_back(i*10);

    bar.resize(foo.size());

    transform(foo.begin(),foo.end(),bar.begin(),op_increase);

    cout << "bar contains:";
    for(vector<int>::iterator it=bar.begin();it!=bar.end();++it)
    	cout << ' ' << *it;
    cout << endl;

    transform(foo.begin(),foo.end(),bar.begin(),foo.begin(),plus<int>());

    cout << "foo contains:";
    for(vector<int>::iterator it=foo.begin();it!=foo.end();++it)
    	cout << ' '<< *it;
    cout << endl;

    return 0;
}

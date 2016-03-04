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
    int myints[] = {10,20,30,5,15};
    vector<int> v(myints,myints+5);

    make_heap(v.begin(),v.end());
    cout << "initial max heap :" << v.front() << endl;

    pop_heap(v.begin(),v.end());
    v.pop_back();
    cout << "max heap after pop: " << v.front() << endl;

    v.push_back(99);
    push_heap(v.begin(),v.end());
    cout << "max heap after push:" << v.front() << endl;

    sort_heap(v.begin(),v.end());

    cout << "final sorted range:";
    for(unsigned i=0;i<v.size();i++)
        cout << ' ' << v[i];

    cout << '\n';
    return 0;
}

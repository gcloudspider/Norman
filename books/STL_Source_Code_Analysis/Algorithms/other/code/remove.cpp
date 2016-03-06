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

bool IsOdd(int i) {return ((i%2)==1);}

int main() {
    int myints[] = {10,20,31,30,20,11,10,20};

    vector<int> myvector(8);
    remove_copy (myints,myints+8,myvector.begin(),20);
    cout << "myvector contains:";
    for(vector<int>::iterator it=myvector.begin(); it != myvector.end(); ++it)
    	cout << ' ' << *it;
    cout << endl;

    int* pbegin = myints;
    int* pend = myints+sizeof(myints)/sizeof(int);

    pend = remove(pbegin,pend,20);

    cout << "range contains:";

    for(int* p = pbegin;p!= pend;++p)
    	cout << ' '<< *p;
    cout << endl;

    vector<int> myvector2(7);
    remove_copy_if(myints,myints+7,myvector2.begin(),IsOdd);
    cout << "myvector2 contains:";

    for(vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); ++it)
    	cout << ' '<< *it;
    cout << endl;

    pend = remove_if(pbegin,pend,IsOdd);

    cout << "the range contains:";

    for(int* p=pbegin;p!=pend;++p)
    	cout << ' ' << *p;
    cout << endl;

    return 0;
}

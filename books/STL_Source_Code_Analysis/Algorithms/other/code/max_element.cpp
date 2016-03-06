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
using namespace std;
#include <algorithm>
#include <vector>
/*
*/

bool myfn(int i,int j) {return i<j;}

struct myclass {
    bool operator() (int i,int j) {return i<j;}
}myobj;


int main() {
    int myints[] = {3,7,2,5,6,4,9};

    cout <<"the smallest element is " << *min_element(myints,myints+7) << endl;

    cout << "the largest element is " << *max_element(myints,myints+7) << endl;

    cout << "The smallest element is " << *min_element(myints,myints+7,myfn) << endl;

    cout << "The largest element is " << *max_element(myints,myints+7,myfn) << endl;

    cout << "The smallest element is " << *min_element(myints,myints+7,myobj) << endl;

    cout << "The largest element is " << *max_element(myints,myints+7,myobj) << endl;

    return 0;
}

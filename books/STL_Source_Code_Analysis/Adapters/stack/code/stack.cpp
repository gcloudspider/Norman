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
#include<stack>
#include<vector>
#include <deque>
using namespace std;

int main() {
    deque<int> mydeque(3,100);
    vector<int> myvector(2,100);

    stack<int> first;
    stack<int> second (mydeque);

    stack<int,vector<int>> third;
    stack<int,vector<int>> fourth(myvector);

    cout << "size of first: " << first.size() << '\n';
    cout << "size of second: " << second.size() << '\n';
    cout << "size of third: " << third.size() << '\n';
    cout << "size of fourth: " << fourth.size() << '\n';

    second.push(2);
    cout << "The element at the top of stack second is." << second.top() << "." << endl;

    cout << "size of second: " << second.size() << '\n';

    return 0;
}

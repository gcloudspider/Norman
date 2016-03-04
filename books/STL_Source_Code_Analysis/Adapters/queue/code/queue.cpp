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
#include <deque>
#include <list>
#include <queue>

int main() {
    deque<int> mydeck(3,100);
    list<int> mylist(2,200);

    queue<int> first;
    queue<int> second(mydeck);

    queue<int,list<int>> third;
    queue<int,list<int>> fourth(mylist);

    cout << "size of first" << first.size() << '\n';
    cout << "size of second" << second.size() << endl;
    cout << "size of third: " << third.size() << endl;
    cout << "size of fourth: " << fourth.size() << endl;
    cout << "The element at the front of queue second is:" << second.front() << endl;
    second.push(10);

    cout << "the element at the back of queue second is:" << second.back() << endl;
    return 0;
}

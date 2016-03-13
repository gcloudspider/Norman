/**
* Create Date:2016年03月13日星期日 11:06:46
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#include<iostream>
using namespace std;
#include <list>

int main() {
    list<int> li;
    li.push_front(1);
    li.push_front(2);
    li.push_front(3);
    li.push_back(4);
    cout << "front : " << li.front() << endl;
    cout << "back : " << li.back() << endl;
    cout << "size: " << li.size() << endl;
    cout << "empty: " << li.empty() << endl;

    li.remove(2);
    cout << "size : " << li.size() << endl;

    li.sort();
    cout << "front : " << li.front() << endl;
    cout << "back : " << li.back() << endl;

    li.pop_front();
    li.pop_back();
    cout << "front : " << li.front() << endl;
    cout << "back : " << li.back() << endl;
    return 0;
}

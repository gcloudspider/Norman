/**
* Create Date:2016年03月13日星期日 09:43:11
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
#include <stack>

int main() {
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "size = " << s1.size() << endl;
    cout << "top = " << s1.top() << endl;
    s1.pop();
    cout << "top = " << s1.top() << endl;
}

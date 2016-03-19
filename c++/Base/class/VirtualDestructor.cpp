/**
* Create Date:2016年03月 9日星期三 19:53:56
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


class Base {
public:
    ~Base(){cout << "Base!" << endl;}
};

class Derive:public Base {
public:
    ~Derive(){cout << "Derive!" << endl;}
};

int main() {
    Derive d;
    return 0;
}

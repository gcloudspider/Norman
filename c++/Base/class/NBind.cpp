/**
* Create Date:2016年03月16日星期三 10:20:02
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#include<iostream>
#include<functional>
using namespace std;
using namespace std::placeholders;

void show(int a,int b,int c,int d) {
    cout << "-----------------------" << endl;
    cout << a << " " << b << " " << c << " " << d << endl;
}

int main() {
    show(1,2,3,4);
    auto f1 = bind(show,_1,_2,_3,_4);
    f1(1,2,3,4);

    auto f2 = bind(show,_1,_2,_3,8);
    f2(1,2,3);

    auto f3 = bind(show,_1,_2,9,_3);
    f3(1,2,3);

    auto f4 = bind(show,_1,6,_2,5);
    f4(1,2);

    auto f5 = bind(show,_3,_1,5,_2);
    f5(1,2,3);
    return 0;
}


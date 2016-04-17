/**
* Create Date:Sat 16 Apr 2016 10:08:00 AM CST
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
#include <boost/thread/thread.hpp>

void hello() {
    cout << "hello world, I'm a thread" << endl;
}

int main() {
    boost::thread thrd(&hello);
    thrd.join();
    return 0;
}

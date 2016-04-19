/**
* Create Date:Wed 20 Apr 2016 06:52:29 AM CST
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
#include <boost/thread/once.hpp>
int i=0;
boost::once_flag flag = BOOST_ONCE_INIT;

void init() {
    ++i;
}

void thread() {
    boost::call_once(&init,flag);
}

int main() {
    boost::thread thrd1(&thread);
    boost::thread thrd2(&thread);
    thrd1.join();
    thrd2.join();
    cout << i << endl;
    return 0;
}

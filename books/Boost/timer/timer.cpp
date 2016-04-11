/**
* Create Date:Mon 11 Apr 2016 06:05:06 PM CST
* -------------------------------
* Copyright (C) 2016-2016 by NiaoYun (@) 
* Report bugs and download new versions at https//niaoyun.com
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by NiaoYun
*/
#include <iostream>
#include <boost/timer.hpp>
using namespace boost;
using namespace std;

int main() {
    timer t;
    cout << "max timespan:" << t.elapsed_max()/3600 << "h" << endl;
    cout << "min timespan:" << t.elapsed_min() << "s" << endl;
    cout << "now time elapsed:" << t.elapsed() << "s" << endl;
}

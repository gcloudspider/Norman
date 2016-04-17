/**
* Create Date:Sun 17 Apr 2016 08:17:13 AM CST
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
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>

boost::mutex io_mutex;
void counter(int id) {
    for (int i = 0; i < 10; ++i) {
        boost::mutex::scoped_lock
            lock(io_mutex);
        cout << id << ": " << i << endl;
    }
}

int main() {
    boost::thread thrd1(boost::bind(&counter,1));
    boost::thread thrd2(boost::bind(&counter,2));
    thrd1.join();
    thrd2.join();
    return 0;
}

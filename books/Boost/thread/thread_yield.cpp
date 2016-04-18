/**
* Create Date:Tue 19 Apr 2016 06:37:14 AM CST
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
#include <boost/thread/xtime.hpp>

struct MyThreadFunc {
    void operator()() {
        //Do something long-running
    }
}threadFun;

int main() {
    boost::thread myThread(threadFun);

    //当前线程放弃余下的时间片
    boost::thread::yield();

    myThread.join();
}

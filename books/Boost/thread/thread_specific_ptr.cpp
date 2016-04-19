/**
* Create Date:Wed 20 Apr 2016 06:47:36 AM CST
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
#include <boost/thread/tss.hpp>

boost::mutex io_mutex;
boost::thread_specific_ptr<int> ptr;

struct counter {
    counter(int id):id(id) { }

    void operator()(){
        if(ptr.get() == 0)
            ptr.reset(new int(0));

        for (int i=0;i<10;++i) {
            (*ptr)++;
            boost::mutex::scoped_lock lock(io_mutex);
            std::cout << id << ": " << *ptr << std::endl;
        }
    }
    
    int id;
};

int main() {
    boost::thread thrd1(counter(1));
    boost::thread thrd2(counter(2));
    thrd1.join();
    thrd2.join();
    return 0;
}

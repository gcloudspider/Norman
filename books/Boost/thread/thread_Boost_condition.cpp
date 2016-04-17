/**
* Create Date:Sun 17 Apr 2016 08:20:59 AM CST
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
#include <boost/thread/condition.hpp>

const int BUF_SIZE = 10;
const int ITERS = 100;

boost::mutex io_mutex;
class buffer {
    public:
        typedef boost::mutex::scoped_lock scoped_lock;

    buffer():p(0),c(0),full(0) {
    
    }

    void put(int m) {
        scoped_lock lock(mutex);
        if(full == BUF_SIZE) {
            {
                boost::mutex::scoped_lock lock(io_mutex);
                cout << "Buffer is full.waiting..." << endl;
            }
            while (full == BUF_SIZE)
                cond.wait(lock);
        }
        buf[p] = m;
        p = (p+1)%BUF_SIZE;
        ++full;
        cond.notify_one();
    }

    int get() {
        scoped_lock lk(mutex);
        if(full == 0) {
            {
                boost::mutex::scoped_lock lock(io_mutex);
                cout << "Buffer is empty.Waiting..." << endl;
            }
            while(full == 0) 
                cond.wait(lk);
        }
        int i = buf[c];
        c = (c+1)%BUF_SIZE;
        --full;
        cond.notify_one();
        return i;
    }

private:
    boost::mutex mutex;
    boost::condition cond;
    unsigned int p,c,full;
    int buf[BUF_SIZE];
};

buffer buf;

void writer() {
    for (int n = 0; n< ITERS;++n) {
        {
            boost::mutex::scoped_lock lock(io_mutex);
            cout << "sending: " << n << endl;
        }
        buf.put(n);
    }
}

void reader() {
    for (int x = 0; x<ITERS;++x) {
        int n = buf.get();
        {
            boost::mutex::scoped_lock lock(io_mutex);
            cout << "received: " << n << endl;
        }
    }
}

int main(int argc,char* argv[]) {
    boost::thread thrd1(&reader);
    boost::thread thrd2(&writer);
    thrd1.join();
    thrd2.join();
    return 0;
} 

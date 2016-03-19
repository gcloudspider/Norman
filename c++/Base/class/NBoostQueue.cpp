/**
* Create Date:2016年03月17日星期四 19:41:51
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
#include<thread>
#include<mutex>
#include<condition_variable>
#include<array>
#include <boost/circular_buffer.hpp>

mutex m_mutex;
condition_variable full,empty;
boost::circular_buffer<int> Q(10);      //缓冲区大小为10 缓冲区数据为int

bool flag = true;

void put(int x) {
    for(auto i=0;i<x;i++) {
        unique_lock<mutex> locker(m_mutex);
        while(Q.full())
            empty.wait(locker);
        assert(!Q.full());

        Q.push_back(i);
        cout << "@ "<< i <<endl;
        full.notify_all();
    }
    flag = false;
}

void take() {
    while(flag) {
        unique_lock<mutex> locker(m_mutex);
        while(Q.empty())
            full.wait(locker);
        if(flag) {
            assert(!Q.empty());
            cout << "# " << Q.front() <<endl;
            Q.pop_front();
            empty.notify_all();
        }
    }
}

int main() {
    thread one(task);
    thread two(task);
    thread three(task);

    put(100);
    one.join();
    two.join();
    three.join();
    return 0;
}

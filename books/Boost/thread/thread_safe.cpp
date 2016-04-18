/**
* Create Date:Tue 19 Apr 2016 06:54:35 AM CST
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
#include <string>

template<typename T>
class Queue {
public:
    Queue() {}
    ~Queue() {}

    void enqueue(const T& x) {
        boost::mutex::scoped_lock lock(mutex_);
        list_push_back(x);
    }

    T dequeue() {
        boost::mutex::scoped_lock lock(mutex_);
        if(list_.empty()) {
            throw "empty!";
        }
        T tmp = list_.front();
        list_.pop_front();
        return (tmp);
    }

private:
    std::list<T> list_;
    boost::mutex mutex_;
};

Queue<std::string> queueOfStrings;

void sendSomething() {
    std::string s;
    for (int i=0;i<10;++i) {
        queueOfStrings.enqueue("Cyrus");
    }
}

void recvSomething() {
    std::string s;
    for (int i=0;i<10;++i) {
        try{s = queueOfStrings.dequeue();}
        catch(...) {}
    }
}

int main() {
    boost::thread thr1(sendSomething);
    boost::thread thr2(recvSomething);

    thr1.join();
    thr2.join();
}

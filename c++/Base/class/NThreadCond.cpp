/**
* Create Date:2016年03月17日星期四 15:49:34
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//条件变量:
//半同步半异步对象内存池
#include<iostream>
using namespace std;
#include <thread>
#include <mutex>
#include <chrono>
#include <list>
#include <condition_variable>
template<typename T>
class SyncQueue {
public:
    SyncQueue(int size):size_(size) {}

    void put(const T& x) {
        lock_guard<mutex> locker(mutex_);
        while(isFull()) {
            notFull_.wait(locker);          //满时等待
        }
        queue_.push_back(x);
        notEmpty_.notify_one();
    }

    void take(T& x) {
        lock_guard<mutex> locker(mutex_);
        while(isEmpty()) {
            notEmpty_.wait(locker);         //为空阻塞
        }
        x = queue_.front();
        queue_.pop_front();
        notFull_.notify_one();
    }

private:
    bool isFull() const {
        return queue_.size() >= size_;   
    }

    bool isEmpty() const {
        return queue_.empty();
    }

    mutex mutex_;
    list<T> queue_;
    int size_;
    condition_variable_any notFull_;
    condition_variable_any notEmpty_;
};

int main() {
    SyncQueue<int> q(5);   
    for(int i =0;i<10;i++) {

    }
    return 0;
}

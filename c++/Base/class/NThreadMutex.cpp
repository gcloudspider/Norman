/**
* Create Date:2016年03月17日星期四 13:30:05
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//C++11提供4种语义互斥量(mutex)
//1.mutex独占互斥量 不能递归使用
//2.timed_mutex带超时的独占互斥量,不能递归使用
//3.recurisive_mutex 递归互斥量,不带超时功能
//4.recurisive_timed_mutex 带超时的递归互斥量


#include<iostream>
using namespace std;
#include<thread>
#include<mutex>
#include<chrono>

mutex g_lock;
int i = 0;

void func(int n) {
    lock_guard<mutex> locker(g_lock);               //创建一个临时变量栈, 入栈上锁 变量出栈自动调用析构函数unlock
    //g_lock.lock();
    cout << "enterned thread" << this_thread::get_id() << endl;
    i++;
    cout << "i = " << i << endl;
    this_thread::sleep_for(chrono::seconds(n));
    cout << "leaving thread" << this_thread::get_id() << endl;
    //g_lock.unlock();
}

int main() {
    thread t1(func,4);
    thread t2(func,3);
    thread t3(func,2);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}

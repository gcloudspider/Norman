/**
* Create Date:2016年03月18日星期五 07:25:54
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//线程同步
//主线程中启动线程1 打印this is thread1 并将g_Flag设置为1
//主线程中启动线程2 打印this is thread2 并将g_Flag设置为2
//线程1需在线程2退出后才能退出
//主线程检测到g_Flag从1变为2 或从2变为1的时候退出
//
#include<iostream>
using namespace std;
#include<functional>
#include<thread>
#include<future>
#include<utility>
#include<chrono>
#include<atomic>
#include<pthread.h>

atomic<int> flag(0);            //采用原子操作保护g_Flag的读写

void worker1(future<int> fut) {
    printf("this is thread1\n");
    flag = 1;
    fut.get();
    printf("thread1 exit\n");
}

void worker2(promise<int> prom) {
    printf("this is thread2 \n");
    flag = 2;
    prom.set_value(10);
    printf("thread2 exit\n");
}

int main() {
    promise<int> prom;
    future<int> fut = prom.get_future();
    thread one(worker1,move(fut));
    thread two(worker2,move(prom));
    while(flag.load() == 0);
    one.detach();
    two.detach();

    pthread_exit(NULL);
    printf("main thread exit!\n");
    return 0;
}

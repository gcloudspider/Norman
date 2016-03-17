/**
* Create Date:2016年03月17日星期四 17:09:35
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
/*
 *  1.子线程循环10次
 *  2.主线程循环100次
 *  3.如此循环打印50次
 *
 * */
#include<iostream>
using namespace std;
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
mutex mutex_;

condition_variable cond;
int flag = 10;

void fun(int num) {
    for(auto i=0;i<50;i++) {
        unique_lock<mutex> locker(mutex_);
        while(flag != num)
            cond.wait(locker);
        for(int j=0;j<num;j++)
            cout << j << " ";
        cout << endl;
        flag=(num==10)?100:10;
        cond.notify_one();
    }
}

int main() {
    thread child(fun,10);
    fun(100);
    child.join();
    return 0;
}

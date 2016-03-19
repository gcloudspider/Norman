/**
* Create Date:2016年03月17日星期四 19:27:50
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
#include<mutex>
#include<condition_variable>
#include<thread>

#define LOOP 10
mutex m_mutex;
condition_variable cond;
int flag;

void fun(int num) {
    for(int i=0;i<LOOP;i++) {
        unique_lock<mutex> locker(m_mutex);
        while(flag != num)
            cond.wait(locker);
        cout << num+1<< " ";
        flag=(flag+1)%4;
        cond.notify_all();
    }
}


int main(int argc,char* argv[]) {
    flag = atoi(argv[1]);
    thread one(fun,1);
    thread two(fun,2);
    thread three(fun,3);
    fun(0);
    one.join();
    two.join();
    three.join();
    cout << endl;
    return 0;
}

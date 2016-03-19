/**
* Create Date:2016年03月17日星期四 17:57:26
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

//3个线程 ID分别为A B C 将每个线程ID打印10遍
//输出结果要求按ABC顺序显示

#include<iostream>
using namespace std;
#include <thread>
#include <mutex>
#include <condition_variable>

mutex m_mutex;
condition_variable cond;
int Loop = 10;
int flag = 0;

void fun(int id){
    for(int i=0;i<Loop;i++) {
        unique_lock<mutex> locker(m_mutex);
        while(id != flag)
            cond.wait(locker);
        cout << (char)('A'+id) << " ";
        flag = (flag +1)%3;
        cond.notify_all();
    }
}

int main() {
    thread B(fun,1);
    thread C(fun,2);
    fun(0);
    cout << endl;

    B.join();
    C.join();
    return 0;
}

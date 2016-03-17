/**
* Create Date:2016年03月17日星期四 13:23:40
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include<thread>
#include<iostream>
using namespace std;
//一个线程对象分离或阻塞只能调用一次

void func() {
    cout << "func" << endl;
}

void f() {
    //线程休眠
    this_thread::sleep_for(chrono::seconds(3));
    cout << "id =" <<this_thread::get_id() << endl;
    cout << "time out" << endl;
}

int main() {
    thread t(func);
    cout << "id= " << t.get_id() << endl;
    t.join();
    cout << "t joinable" << t.joinable() << endl;      //判断是否已经join
    cout << thread::hardware_concurrency() << endl;

    thread t1(f);
    t1.join();
    return 0;
}

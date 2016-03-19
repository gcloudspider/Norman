/**
* Create Date:2016年03月17日星期四 12:34:10
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//线程:
//1.join()      
//2.detach();   线程分离
//3.move()      移动线程对象
#include<iostream>
using namespace std;
#include <thread>
#include <vector>

vector<thread> g_list;
vector<shared_ptr<thread>> g_list2;

void fun() {
    cout << "func" << endl;
}

void func(int i,double d,const string& s) {
    cout << i << ", " << d << ", " << s << endl;
}

void CreateThread() {
    thread t(fun);
    g_list.push_back(move(t));
    g_list2.push_back(make_shared<thread>(fun));
}

int main(){
    thread t(fun);
    //t.join();           //fun运行于t对象中  join阻塞线程
    t.detach();             //线程和对象分离,线程后台运行
    
    thread p(func,1,2,"test");
    p.join();

//    thread t1(move(p));
//    t1.join();

    thread t2(bind(func,1,2,"test"));       //bind使用
    thread t3([](int i,double d,const string& s){},1,2,"test");     //lambda
    t2.join();
    t3.join();


    //将线程对象保存到一个容器中,保证线程对象的生命周期
    CreateThread();
    for(auto& thread: g_list) {
        thread.join();
    }
    for(auto& thread: g_list2) {
        thread->join();
    }
    return 0;
}

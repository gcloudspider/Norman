/**
* Create Date:2016年03月17日星期四 20:04:34
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
#include<memory>
#include<thread>
#include<vector>
#include<assert.h>

mutex m_mutex;
shared_ptr<vector<int>> ptr;

int loop = 100;

void read() {
    while(1) {
        //放在块内可以使临时对象得到及时析构
        shared_ptr<vector<int>> temp_ptr;
        {
            //读和读之间 读与写之间互斥 临界区很小
            unique_lock<mutex> locker(m_mutex);
            temp_ptr = ptr;         //引用计数加1
            assert(!temp_ptr.unique());
        }
        for(auto it = temp_ptr->begin();it!= temp_ptr->end();it++) 
            cout << *it << " " <<endl;
    }
}

void write() {
    for(int i=0;;i++) {
        unique_lock<mutex> locker(m_mutex);
        if(!ptr.unique()) {
            ptr.reset(new vector<int>(*ptr));
        }
        assert(ptr.unique());
        ptr->push_back(i);
    }
}

int main() {
    ptr.reset(new vector<int>);
    thread one(read);
    thread two(read);
    write();

    one.join();
    two.join();

    return 0;
}

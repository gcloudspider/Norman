/**
* Create Date:2016年03月17日星期四 10:27:30
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//弱指针
//
#include<iostream>
using namespace std;
#include <memory>

int main() {
    shared_ptr<int> sp(new int);
    weak_ptr<int> wp = sp;

    cout << "use = " << sp.use_count() << endl;
    
    if(wp.expired()) {
        cout << "资源不存在了"<< endl;
    } else {
        cout << "资源还在" << endl;
        shared_ptr<int> rp  = wp.lock();
        *rp = 8;
    }

}

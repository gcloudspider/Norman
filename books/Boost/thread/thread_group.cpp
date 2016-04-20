/**
* Create Date:Thu 21 Apr 2016 06:41:12 AM CST
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
#include <boost/thread/thread.hpp>
void threadFun() {
    cout << "threadfun" << endl;
}

int main() {
    boost::thread_group grp;
    boost::thread *p = new boost::thread(threadFun);
    grp.add_thread(p);

    grp.remove_thread(p);

    grp.create_thread(threadFun);
    grp.create_thread(threadFun);

    grp.join_all();
}

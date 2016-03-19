/**
* Create Date:2016年03月14日星期一 13:39:28
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
#include <queue>

int main(){
    queue<int> q;
    q.push(0);
    q.push(1);
    q.push(2);
    
    cout << "front : " << q.front() << endl;
    q.pop();
    q.pop();
    q.pop();
    cout << "front : " << q.front() << endl;
    cout << "back : " << q.back() << endl;
 
    cout << "size : " << q.size() << endl;
    cout << "empty : " << q.empty() << endl;
}

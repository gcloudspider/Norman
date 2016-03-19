/**
* Create Date:2016年03月17日星期四 11:23:38
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//独占型智能指针:
//
//
#include<iostream>
using namespace std;
#include <memory>

int main(){

    unique_ptr<int> up1(new int);
    int* p = up1.release();         //释放对象不再管理资源,返回裸指针
    
    cout << "p address:" << p << endl;
    return 0;
}

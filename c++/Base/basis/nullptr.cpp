/**
*  - version 1.0
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
#include <iostream>
#include <stdlib.h>
//nullptr:
//    1.代表空指针关键字

using namespace std;

int main(){
    int* p1 = NULL;
    int* p2 = nullptr;

    p1 = (int*)malloc(sizeof(int));         //不可以赋初始值
    free(p1);

    p2 = new int(6);                        //1.申请整型 可以赋值初始值
    cout << "*p2=" << *p2 << endl;
    delete p2;

    p2 = new int[3]{1,2,3};                 //2.申请数组 并赋初始化值
    delete[] p2;                            //删除数组指针方式

    auto p3 = new Data{1,31};               //3.申请结构体
    delete p3;
}

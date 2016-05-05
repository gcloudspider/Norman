/**
* Create Date:Wed 04 May 2016 05:22:57 PM CST
* -------------------------------
* Copyright (C) 2016-2016 by NiaoYun (@) 
* Report bugs and download new versions at https//niaoyun.com
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by NiaoYun
*/

#include<stdio.h>
#include <iostream>
using namespace std;
class filemo {
    public:
    int sum(const int& a,const int& b){
        return a+b;
    }
    int min(const int& a,const int& b){
        return a-b;
    }

}
   // int doSomething(const int& a,const int& b,int(*pf)(const int& a,const int& b)){
     
   int doSomething(const int& a,const int& b,void*(*func)(void*)){
    return func(a,b);
    }
}

int main(){
    cout << file_mo.doSomething(1,2,&file_mo.sum) << endl;
    cout << file_mo.doSomething(1,2,&file_mo.min) << endl;
    return 0;
}

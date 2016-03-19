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
#include<stdio.h>
#include<iostream>
using namespace std;
//函数返回
//1.返回值
template<class T>
T add(T x,T y){
    return x+y;
}

//2.返回引用
template<class R>
R& adb(R& x,R& y,R& result){
    result = x+y;
    return result;
}

//3.返回一个常量引用
template<class U>
const U& adc(const U& x,const U& y){
    return x+y;
}


int main(){
    printf("%d\n",add(2,3));
    printf("%f\n",add(2.3,3.5));
    
    int a=2,b=3,c;
    double x=2.3,y=3.5,z;
    printf("%d\n",adb(a,b,c));
    printf("%f\n",adb(x,y,z));

    int aa=2,bb=3;
    printf("%d\n",adc(aa,bb));
    return 0;
}

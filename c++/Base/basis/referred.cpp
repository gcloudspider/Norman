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
#include<iostream>
using namespace std;

//直接拷贝给变量a b
int swap(int a,int b){
    int c;
    c = a;
    a = b;
    b = c;
}

//拷贝指针地址给a b
int swap1(int *a,int *b){
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

//引用:直接使用a b 地址没有发生拷贝
int swap2(int& a,int& b){
    int c;
    c = a;
    a = b;
    b = c;
}

//没有使用引用
int swap3(int& a,int& b){
    int t = a;
    a = b;
    b = t;
    return a;
}
//使用引用
int& swap4(int& a, int& b){
    int t = a;
    a = b;
    b = t;
    return a;
}

int main(){
    int val = 3;
    int& var = val;             //引用必须同时赋初值
    
    printf("&val=%p\n", &val);
    printf("&var=%p\n", &var);

    var = 8;
    cout << "val=" << val << endl;
    int x = 3;
    int y = 4;
    swap(x,y);
    cout << "x= " << x << " y=" << y << endl;
    swap1(&x,&y);
    cout << "x= " << x << " y=" << y << endl;
    swap2(x,y);
    cout << "x= " << x << " y=" << y << endl;

    //左值
    int& r = swap4(x,y);
    cout << "x= " << x << " y=" << y << " r=" << r << endl;
    
    //右值
    swap4(x,y) = 9;
    cout << "x= " << x << " y=" << y << endl;
}

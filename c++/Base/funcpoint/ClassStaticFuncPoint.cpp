/**
* Create Date:Thu 05 May 2016 09:54:24 AM CST
* -------------------------------
* Copyright (C) 2016-2016 by Norman (@) 
* Report bugs and download new versions at https//niaoyun.com
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//静态函数
#include<stdio.h>
#include<iostream>
using namespace std;
class MyClass {
    public:
        static float plus(float a, float b){
            return a+b;
        }
};

int main() {
    float result,a=10.0,b=10.0;
    float (*p)(float,float);
    p = &MyClass::plus;
    result = p(a,b);
    printf("result=%f\n",result);
    return 0;
}

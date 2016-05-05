/**
* Create Date:Thu 05 May 2016 10:24:47 AM CST
* -------------------------------
* Copyright (C) 2016-2016 by Norman (@) 
* Report bugs and download new versions at https//niaoyun.com
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/

#include<iostream>
using namespace std;
#include <stdio.h>

float add(float a,float b){return a+b;}

float minuser(float a,float b){return a-b;}

float multiply(float a,float b){return a*b;}

float divide(float a,float b){return a/b;}

int main() {
    float(*func_pointers[4])(float,float) = {add,minuser,multiply,divide};
    int i=0;
    float a=10.0,b=5.0;
    for(i=0;i<4;i++){
        printf("result is %f\n",func_pointers[i](a,b));
    }
    return 0;
}

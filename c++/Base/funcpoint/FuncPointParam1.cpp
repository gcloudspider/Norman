/**
* Create Date:Thu 05 May 2016 10:00:54 AM CST
* -------------------------------
* Copyright (C) 2016-2016 by Norman (@) 
* Report bugs and download new versions at https//niaoyun.com
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//函数指针作为参数
#include<iostream>
using namespace std;

#include <stdio.h>
class nyInotify{
public:
    static float add(float a,float b){return a+b;}

    static float minuser(float a,float b){return a-b;}

    static float multiply(float a,float b){return a*b;}

    static float divide(float a,float b){return a/b;}
};

class nyrbTree{
public:
    int pass_func_pointer(float (*pFunction)(float a,float b)){
        float result = pFunction(10.0,12.0);
        printf("result=%f\n",result);
    }
};

int main(){
    nyrbTree rbtree;
    rbtree.pass_func_pointer(&nyInotify::add);
    rbtree.pass_func_pointer(&nyInotify::minuser);
    rbtree.pass_func_pointer(&nyInotify::multiply);
    rbtree.pass_func_pointer(&nyInotify::divide);
    return 0;
}


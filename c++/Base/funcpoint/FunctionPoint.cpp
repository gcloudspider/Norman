/**
* Create Date:Wed 04 May 2016 07:24:21 PM CST
* -------------------------------
* Copyright (C) 2016-2016 by NiaoYun (@) 
* Report bugs and download new versions at https//niaoyun.com
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by NiaoYun
*/

#include<iostream>
using namespace std;
#include <sys/time.h>
#include <stdio.h>
#define N 1000000
#define COE 1000000


float add(float a,float b){return a+b;}

float minuser(float a, float b){return a-b;}

float multiply(float a, float b){return a*b;}

float divide(float a,float b){return a/b;}

typedef float (*pf)(float,float);

void switch_impl(float a, float b,char op){
    float result = 0.0;
    switch(op){
        case '+':
            result = add(a,b);
            break;
        case '-':
            result = minuser(a,b);
            break;
        case '*':
            result = multiply(a,b);
            break;
        case '/':
            result = divide(a,b);
            break;
    }
}

void switch_fp_impl(float a,float b,pf p){
    float result = 0.0;
    result = p(a,b);
}

int conversion(struct timeval tmp_time) {
    return tmp_time.tv_sec * COE + tmp_time.tv_usec;
}

int main() {
    int i = 0;
    struct timeval start_point,end_point;
    gettimeofday(&start_point,NULL);

    for(i=0;i<N;i++){
        switch_impl(12.32,54.14,'-');
    }

    gettimeofday(&end_point,NULL);
    printf("check point 1:%d\n",conversion(end_point)-conversion(start_point));

    gettimeofday(&start_point,NULL);

    for(i=0;i<N;i++) {
        switch_fp_impl(12.32,54.14,minuser);
    }
    gettimeofday(&end_point,NULL);
    printf("check point 2:%d\n",conversion(end_point) - conversion(start_point));

    return 0;
}

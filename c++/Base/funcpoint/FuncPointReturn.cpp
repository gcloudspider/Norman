/**
* Create Date:Thu 05 May 2016 10:13:25 AM CST
* -------------------------------
* Copyright (C) 2016-2016 by Norman (@) 
* Report bugs and download new versions at https//niaoyun.com
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//函数指针作为返回值
#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float add(float a, float b){return a+b;}

float minuser(float a,float b){return a-b;}

float multiply(float a,float b){return a*b;}

float divide(float a,float b){return a/b;}

float (*FunctionMap(char op))(float,float) {
    switch(op){
        case '+':
            return add;
            break;
        case '-':
            return minuser;
            break;
        case '*':
            return multiply;
            break;
        case '\\':
            return divide;
            break;
        default:
            exit(1);
    }
}

int main() {
    float a=10,b =5;
    char ops[] = {'+','-','*','\\'};
    int len = strlen(ops);
    int i = 0;
    float (*returned_function_pointer)(float,float);
    for(i=0;i<len;i++){
        returned_function_pointer = FunctionMap(ops[i]);
        printf("the result caculated by the operator %c is %f\n",ops[i],returned_function_pointer(a,b));
    }
    return 0;
}



/**
* Create Date:Thu 05 May 2016 10:47:38 AM CST
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
#include <stdlib.h>
#include <string.h>

float add(float a,float b){return a+b;}

float minuser(float a,float b){return a-b;}

float multiply(float a,float b){return a*b;}

float divide(float a,float b){return a/b;}

typedef float(*pArithmeticOperations)(float,float);
typedef float ArithmeticOperations(float,float);

int main() {
    pArithmeticOperations pao = add;
    pArithmeticOperations paos[4] = {add,minuser,multiply,divide};

    ArithmeticOperations *ao = add;
    ArithmeticOperations *aos[4] = {add,minuser,multiply,divide};
    float a=10.0,b=5.0;
    float result = 0.0;
    int i = 0;
    result = pao(a,b);

    printf("the result of pao is %f\n",result);

    printf("the results of paos are:\n");
    for(i=0;i<4;i++){
        result = paos[i](a,b);
        printf("result=%f\n",result);
    }

    result = ao(a,b);
    printf("\n\nthe result of ao is:%f\n",result);

    printf("the results of aos are:\n");
    for(i=0;i<4;i++){
        result = aos[i](a,b);
        printf("result=%f\n",result);
    }
    return 0;
}

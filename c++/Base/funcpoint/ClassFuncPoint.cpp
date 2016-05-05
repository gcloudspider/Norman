/**
* Create Date:Thu 05 May 2016 09:40:11 AM CST
* -------------------------------
* Copyright (C) 2016-2016 by Norman (@) 
* Report bugs and download new versions at https//niaoyun.com
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//类函数指针与普通函数指针

#include<iostream>
using namespace std;
#include <stdio.h>

float func1(float f,char a,char b) {
    printf("func1\n");
    return f*a/b;
}

float func2(float f,char a,char b) {
    printf("func2\n");
    return f*a*b;
}

class MyClass {
    public:
        MyClass(float f) {
            factor = f;
        }

        float func1(float f,char a,char b) {
            printf("MyClass::func1\n");
            return f*a/b*factor;
        }

        float func2(float f,char a,char b) const {
            printf("MyClass::func2\n");
            return f*a*b*factor;
        }
    private:
        float factor;
};

int main() {
    float (*pFunction)(float,char,char) = NULL;
    float (MyClass::*pMemberFunction)(float,char,char) = NULL;
    float (MyClass::*pConstMemberFunction)(float,char,char) const = NULL;

    float f = 10.0;
    char a='a',b='b';
    float result;
    pFunction = func1;
    printf("pointer pFunction's address is:%x\n",pFunction);
    result = (*pFunction)(f,a,b);
    printf("result=%f\n",result);

    pFunction=&func2;
    printf("pointer pFunction's address is:%x\n",pFunction);

    result=pFunction(f,a,b);
    printf("result=%f\n",result);
    if(func1 != pFunction)
        printf("not equal.\n");

    pMemberFunction = &MyClass::func1;
    MyClass mc1(0.2);
    printf("pointer pMemberFunction's address is:%x\n",pMemberFunction);

    result = (mc1.*pMemberFunction)(f,a,b);
        printf("result=%f\n",result);
    pConstMemberFunction= &MyClass::func2;
    MyClass mc2(2);
    printf("pointer pConstMemberFunction's address is:%x\n",pConstMemberFunction);

    result = (mc2.*pConstMemberFunction)(f,a,b);
    printf("result=%f\n",result);

    return 0;
}

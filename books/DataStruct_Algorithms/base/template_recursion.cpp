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
#include <stdio.h>
#include <iostream>
using namespace std;

//基本递归函数(计算n!的递归函数)
int factorial(int n){
    if(n<=1) return 1;
    else return n*factorial(n-1);
}

//累加数组元素
template<class T>
T sum(T a[],int n){
    T theSum = 0;
    for(int i=0;i<n;i++){
        theSum += a[i];
    }
    return theSum;
}
//累加数组元素a[0:n-1]的递归
template<class T>
T rSum(T a[],int n){
    if(n>0)
        return rSum(a,n-1) + a[n-1];
    return 0;
}


int main(){
    printf("%d\n",factorial(3));

    int a[]={1,3,2,4,5};
    float b[] = {3.4,5.6,2.1,3.3,2.1};
    printf("%d\n",sum(a,5));
    printf("%f\n",sum(b,5));

    int c[]={1,2,3,4,5};
    double d[]={1.7,2.8,3.4,4.6,5.5};
    printf("%d\n",rSum(c,5));
    printf("%f\n",rSum(d,5));
}

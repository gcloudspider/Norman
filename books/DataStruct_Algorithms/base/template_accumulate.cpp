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
#include<numeric>
using namespace std;
//求和
//accumulate(a,a+n,initialValue)
template<class T>
T Sum(T a[],int n){
    T theSum = 0;
    return accumulate(a,a+n,theSum);
}

//乘积
//更通用
//accumulate(start,end,initialValue,operator)
template<class T>
T Product(T a[],int n){
    T theProduct = 1;
    return accumulate(a,a+n,theProduct,multiplies<T>());
}

int main(){
    int a[]={3,4,5,6,8};
    double b[]={3.6,4.3,5.1,6.9,8.0};
    printf("%d\n",Sum(a,5));
    printf("%f\n",Sum(b,5));

    printf("%d\n",Product(a,5));
    printf("%f\n",Product(b,5));
}

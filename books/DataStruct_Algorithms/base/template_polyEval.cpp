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
#include<stdio.h>

template<class T>
T polyEval(T coeff[],int n,const T& x){
    T y = 1,value = coeff[0];
    for(int i= 1;i<=n;i++){
        y *= x;
        value += y*coeff[i];
    }
    return value;
}

int main(){
    int a[] = {2,4,5,2,1};
    printf("%d\n",polyEval(a,4,3));

    return 0;
}

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
#include <iostream>
using namespace std;

using functor = bool(*)(int,int);

bool comNum(int src1,int src2){
    return src1 > src2;
}

//整数每个位相加比较
bool comSum(int src1,int src2) {
    int m = 0;
    int n = 0;
    while(src1 != 0 || src2 != 0){
        m += src1 % 10;
        n += src2 % 10;
        src1 /= 10;
        src2 /= 10;
    }
    return m > n;
}

void numSort(int src[],int len,functor fun){
    for(auto i = 0; i < len; ++i){
        for(auto j = 0; j< len-i-1; ++j){
            if(fun(src[j],src[j+1])){
                int t = src[j];
                src[j] = src[j+1];
                src[j+1] = t;
            }
        }
    }

}

int main(){
    int src[] = {2111,7,101,121,54};

    cout << "-----比较大小-----" << endl;
    numSort(src,5,comNum);
    for (auto i = 0; i < 5; ++i){
        cout << src[i] << endl;
    }

    cout << "-----位相加的和-----" << endl;
    numSort(src,5,comSum);
    for (auto i = 0; i < 5; ++i){
        cout << src[i] << endl;
    }

    return 0;
}

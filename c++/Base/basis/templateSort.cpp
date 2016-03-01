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

template<typename T>
void insertSort(T src[],int len) {
    T temp;
    int k;
    for(auto i=1;i<len;++i) {
        temp = src[i];
        k = i;
        for (auto j = i-1;j>=0;--j) {
            if (src[j] < temp) {
                break;
            }
            src[j+1] = temp;
            k = j;
        }
    }
}

int main() {
    int src[] = {13,21,29,19,20};
    string str[] = {"helo","you","world","welcome","nihao"};

    insertSort(src,5);
    for(auto i = 0; i < 5; ++i) {
        cout << src[i] << endl;
    }
/*
    insertSort(str,5);
    for(auto i = 0; i < 5; ++i) {
        cout << str[i] << endl;
    }   
*/
}

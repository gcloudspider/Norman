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
#include <string.h>

bool isNum(char s) {
    return ((s >= '0') && (s <= '9'))?true:false;
}

bool isStr(char s) {
    return ((s >= 'a') && (s <='z'))?true:false;
}

template<typename T>
void strSort(T str,int len) {
    int j=0;
    int num[]={};
    string character;
    for(auto i = 0; i < len; ++i) {
        if(isNum(str[i])) {
            if(isNum(str[i+1])) {
                number += str[i];
            } else {
                number += str[i];
                num[j] = atoi(number.c_str());
                j++;
            } 
        } else {
            character += str[i];
        }
    }
    int numlen = sizeof(num)/sizeof(num[0]);
    for(auto k=0;k<numlen;++k) {
        cout << num[k] << endl;    
    }

    cout << character << endl;
}

int main() {
    string str = "jie348h2cd91e7";
    int len = str.size();
    strSort(str,len);
    return 0;
}

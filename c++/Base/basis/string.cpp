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
//判断字母还是数字

#include <iostream>
using namespace std;

int main() {

    string a = "jie348h2cd91e7";
    int c[20]={0};
    string  b[20]={""};
    int j=0,m=0;
    bool b_str=false;
    bool b_int = false;
    for(int i=0;i<a.length();i++) {
        if(a[i]>='a' &&a[i]<= 'z') {
            if(b_str) {
                b[j] = b[j] +a[i] ;
            } else {
                b[j] = a[i];
                b_str = true;
            } 
            if(b_int) {
                ++m;
                b_int = false;
            }
        }
        else if(a[i] >= '0' && a[i]<= '9') {
            if(b_int) {
                c[m] = c[m]* 10 +a[i]-'0';
            } else {
                c[m] = a[i] -'0';
                b_int = true;
            } 
            if(b_str) {
                ++j; 
                b_str = false;
            }
        }
    }

    for(auto i = 0; i<4; ++i) {
        cout << c[i] << endl;
    }

    for(auto j=0; j<4; ++j) {
        cout << b[j] << endl;
    }

}

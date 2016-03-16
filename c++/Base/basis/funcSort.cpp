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

using Fun = bool(*)(string,string);

bool cmpLen(string str1,string str2) {
    return str1.size() > str2.size();
}

bool cmpDict(string str1,string str2) {
    return str1 > str2;
}

void stringSort(string str[],int len,Fun pfun) {
    for (auto i = 0; i < len; ++i) {
        for(int j=0;j< len-i-1;++j) {
            bool isTrue = pfun(str[j],str[j+1]);
            if (isTrue) {
                string t = str[j];
                str[j]  = str[j+1];
                str[j+1] = t;
            }   
        }   
    }
}

int main() {
    string str[] = {"hello","hi","welcome","haluo"};

    stringSort(str,4,cmpLen);
    cout << "-----按长度排序-----" << endl;
    for (auto i = 0; i< 4; ++i) {
        cout << str[i] << endl;
    }

    stringSort(str,4,cmpDict);
    cout << "-----字典序排序-----" << endl;
    for (auto i = 0; i< 4; ++i) {
        cout << str[i] << endl;
    }
}

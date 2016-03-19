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

inline bool isNum(char s) {
    return ((s >= '0') && (s <= '9'))?true:false;
}

inline bool isStr(char s) {
    return ((s >= 'a') && (s <='z'))?true:false;
}

template<typename T>
inline bool comStr(T a,T b) {
    return a<b?true:false;
}

//排序
template<typename T>
void insertSort(T src[],int len) {
    T temp;
    int k = 0;
    for (auto i=1; i<len; ++i) {
        temp = src[i];
        k = i;
        for (auto j=i-1;j>=0;--j) {
            if(comStr(src[j],temp)) {
                //k = j+1;
                break;
            }
            src[j+1] = src[j];
            k = j;
        }
        src[k] = temp;
    }
}

void show(int src[],int len) {
    for(auto i=0; i< len; ++i) {
        cout << src[i] << endl;
    }
}

//将字符串分割成2部分----数字和字母
template<typename T>
void strCategory(T str,int len) {
    int j=0;
    int num[4]={0};
    int charStr[4]={0};
    string character;
    bool b_int = false;
    for (auto i = 0; i < len; ++i) {
        if (isNum(str[i])) {
            if(b_int) {
                num[j] = num[j]*10+str[i]-'0';
            } else {
                num[j] = str[i] - '0';
                b_int = true;
            } 
        } else if(isStr(str[i])) {
            character += str[i];
            if(b_int) {
                ++j;
                b_int = false;
            }
        }
    }
    
    cout << "-----排序前-----" << endl;
    show(num,4);
    insertSort(num,4);
    cout << "-----排序后-----" << endl;
    show(num,4);
    int charlen = character.size();
    //insertSort(character,charlen);

}

int main() {
    string str = "jie348h2cd91e7";
    int len = str.size();
    strCategory(str,len);
    return 0;
}

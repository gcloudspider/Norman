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

string removeSymbol(string str){
    string ret;
    for (auto& c : str) {
        if((c >= 'A' && c <= 'z')|| (c >= '0' && c <= '9')){
            ret += c;
        } else if (c == 32) {       //空格
            ret += c;
        }
    }
    return ret;
}

int main(){
    string str = "eh! how are you!.lo&";
    string ret;
    ret = removeSymbol(str);
    cout << ret << endl;

    return 0;
}

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
#include<vector>
using namespace std;

/*
*C++98/03版本遍历:
for(auto it = arr.begin();it != arr.end();++it){
    cout << *it << endl;
    return 0;
}
####for循环新用法:
    C++98/03中:不同容器 数组 遍历方法不尽相同,写法不统一
    C++11 基于范围for循环统一 简洁方式来遍历容器和数组

####for 使用引用:
    当想要改变S的值需要将C做为每一个字符的引用
    for(auto& c: s){
        c = 'b';
    }

/////////////////////////////////////////////////
void do_cout(){
    cout << n << endl;
}

for_each(arr.begin(), arr.end(),do_cout);
* */

int main(){
    vector<int>arr = {1,2,3,4};

    string s = "this is a pig";

    for (auto n: arr) {
        cout << n << endl;
    }

    for(auto& c:s){
        c = 'b';    //使用引用改变s的值
        //cout << c << endl;
    }
    cout << "s=" << s << endl;
    return 0;
}

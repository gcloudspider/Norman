/**
* Create Date:2016年03月13日星期日 16:16:16
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
#include <vector>

int main() {
    vector<int> v = {90,80};
    v.push_back(10);
    v.push_back(40);
    v.push_back(50);
    v.push_back(30);
    v.push_back(20);
    v.push_back(70);
    v.push_back(60);
    //for循环遍历
    for (auto it=v.begin();it != v.end();++it) {
        cout << *it << " ";
    }
    cout << endl;

    v.pop_back();
    
    //范围for循环
    for(auto& m : v) {
        cout << m << " ";
    }
    cout << endl;

    for(auto it = v.begin();it != v.end();++it) {
        if(*it == 50) {
            v.erase(it);
            v.insert(it,55);
        }
    }

    //下标方式遍历
    for (int i =0;i<v.size();++i) {
        //重载了[]广括号
        cout << v[i] << " ";
    }
    cout << endl;

    //拷贝构造函数
    vector<int> w = v;
    
    //赋值运算符重载
    vector<int> z;
    z = v;

    for(auto& zm : v) {
        cout << zm << " ";
    }
    cout << endl;
}

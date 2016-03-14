/**
* Create Date:2016年03月14日星期一 14:52:47
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
#include<map>
/*
template <typename T, typename B>
struct Pair {
    Pair(){}
    Pair(T f,B s):first(f),second(s){}
    Pair(const Pairt<T>& data) {}

    T first;
    B second;
};
*/
//1.自动排序(按key 字典序排序)
//2.插入key元素相同时忽略插入
//
int main() {
    pair<string,string> a("norman","产品汪");

    map<string,string> addr;
    addr.insert(a);

    addr.insert(pair<string,string>("Danny","射鸡师"));
    addr.insert({"Tonny","程序猿"});
    addr.insert({"Tonny","程序媛"});
    addr.erase("Tonny");

    string v = addr["Danny"];           //引用返回
    addr["Danny"] = "码农";
    addr["evely211"] = "搬砖的";
    addr["cell390"] = "架构师";
    cout << v << endl;

    for (auto it = addr.begin(); it != addr.end();++it) {
        cout << it->first << ":" << it->second << endl;
    }

    map<string,string>::iterator it = addr.find("norman");
    if(it != addr.end()) {
        cout << "find : " << it->first << " : " << it->second << endl;
    }
    
    string tmpString;
    int i=1;
    map<char,int> num;
    cin >> tmpString;
    for (auto& tmp : tmpString) {
        auto it = num.find(tmp);
        if(it != num.end()) {
            int j = it->second;
            num[tmp] = ++j;
            cout << j << endl;
            cout << num[tmp] << endl;
        }
        num[tmp] = i;
    }

    for (auto it = num.begin();it != num.end();++it) {
        cout << it->first << ":" << it->second << endl;
    }
}

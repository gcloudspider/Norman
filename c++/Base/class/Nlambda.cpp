/**
* Create Date:2016年03月16日星期三 09:14:42
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
//优势:
//  1.作用域(函数全局访问,只能在函数体内访问)
//  2.lanbam表达式变量可直接赋值(处理变量)

using Fun = bool(*)(string,string);
/*
bool cmpLen(string str1,string str2) {
    return str1.size() > str2.size();
}

bool cmpDict(string str1,string str2) {
    return str1 > str2;
}
*/
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

//后置返回类型
auto fun(int a,int b) -> int
{
    return a + b;
}

int main(){
    //可省略返回类型使用自动推导
    //auto f = [](int a,int b) -> int { return a+b;};
    auto f = [](int a,int b){ return a+b;};
    auto g = f;                                         //可直接赋值
    int sum = g(3,4);
    cout << "sum = " << sum << endl;
    

    string str[] = {"hello","hi","welcome","haluo"};

    stringSort(str,4,[](string str1,string str2){return str1.size() > str2.size();});
    cout << "-----按长度排序-----" << endl;
    for (auto i = 0; i< 4; ++i) {
        cout << str[i] << endl;
    }

}

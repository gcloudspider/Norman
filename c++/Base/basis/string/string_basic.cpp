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

//string存储方式
//1.string变量中真正存储字符串的是_Ptr指针  它指向string所存储字符串首地址
//2.string变量被定义时,如果未初始化,_Ptr就是指向一个NULL指针
//3._Ptr像是const char*类型指针

//-----------------------------------------------------------------
//赋值:
//      1.检查ptr是否NULL 如果是分配足够动态内存
//      2.如果不为NULL 检查cap是否足够放下字符串,如果不足重新分配内存.调用std::copy或者strcpy之类函数,把字符串复制到ptr中

//1.string通过动态分配内存给_Ptr来存储字符串
//2.string只能分配必要内存
//3.string存储空间位于堆上
//4.string与vector不一样,一般不会为元素预留内存,不存在浪费
#include<iostream>

using namespace std;

int main(){
    string s1 = "hello";
    string s2 = " world";

    string s3 = s1+s2;
    cout<<"s3 ="<<s3<<endl;

    string s4 = "oh fuck";
    s4 += "you";
    cout<<"s4="<<s4<<endl;

    cout<<"size="<<s4.size()<<endl;

    if(s4.empty()){
        cout<<"s4 is empty"<<endl;
    }else {
        cout<<"S4 have something"<<endl;
    }
    s4.resize(5);
    cout<<"resize="<<s4<<endl;
    s4.resize(20);
    cout<<"resize="<<s4<<endl;
    cout<<"size="<<s4.size()<<endl;

    string s = "hello world";
    cout<<"s[4]="<<s[4]<<endl;
    cout<<"s[4]="<<s[13]<<endl;
}

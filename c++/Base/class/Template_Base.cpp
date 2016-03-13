/**
* Create Date:2016年03月13日星期日 09:15:41
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//类内定义的是内联函数 拷贝代码到调用处
//类外定义不是内联函数 发生调用,进栈出栈

#include<iostream>
using namespace std;
/*
class ArrayTp {
public:
    ArrayTp(int value) : 
        m_Value(value){
        
    }
    ArrayTp() = default;
    int get(){return m_Value;}  //代码较少直接写类内
    void set(int value) {m_Value = value;}

private:
    int m_Value;
};

class ValueTp {
public:
    ValueTp(string value) : 
        m_Value(value){
        
    }
    ValueTp() = default;
    string get(){return m_Value;}  //代码较少直接写类内
    void set(string value) {m_Value = value;}

private:
    string m_Value;
};
*/

template <typename T>
class ValueTp {
public:
    ValueTp(T value) : m_Value(value) {}
    ValueTp() = default;

    T get() {return m_Value;}
    void set(T value) {m_Value = value;}

private:
    T m_Value;
};

int main() {
    /*
    ArrayTp t(5);
    ValueTp g("hello");
    cout << "t = " << t.get() << endl;
    cout << "g = " << g.get() << endl;
    */

    ValueTp<int> x(5);
    ValueTp<string> y("hello");
    ValueTp<double> z(3.1415926);
    cout << "x = " << x.get() << endl;
    cout << "y = " << y.get() << endl;
    cout << "z = " << z.get() << endl;
}

/**
* Create Date:2016年03月13日星期日 08:44:08
* -------------------------------
* Copyright (C) 2016-2016 by Norman (none_lih@163.com) 
* Report bugs and download new versions at https//github.com/evely211
* 
* This library is distributed under the MIT License. See notice at the end of this file.
* This work is based on POSIX，which is:
* Copyright (C) 2016,by Norman
*/
//有默认构造函数与无默认构造函数区别
//
//
//编译器行为:
//1.类内含有一个或多个类成员对象,那么该类的每一个构造函数必须调用每一个类成员的默认构造函数(按成员声明顺序)
//2.编译器会扩张已存在的构造函数.在其中安插代码,使用户代码被执行前先调用必要的类成员默认构造函数
#include<iostream>
using namespace std;

class X {
    public:
        X(){
            mData = 0;
            cout << "X::X()" << endl;
        }
        int mData;
};

class Xs {
public:
    //编译器安插的伪代码
    /*
     *inline Xs::Xs(){
     *   mX.X::X();
     *   cout << "Xs::Xs()" << endl;
     *   mN = 1;
     *}
     * */
    //意义:使每个类成员变量都得到初始化

    Xs() {
        cout << "Xs::Xs()" <<endl;
        mN = 1;                     //只为成员变量mN进行初始化
    }

    X mX;          
    int mN;         
};

int main() {
    Xs xs;
    cout << xs.mX.mData << endl;
    cout << xs.mN << endl;
    return 0;
}


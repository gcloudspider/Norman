/**
* Create Date:2016年03月14日星期一 07:51:27
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

class X {
public:
    X(){
        mData = 100;
        cout << "X::X()" << endl;
    }

    X(const X& rhs) {
        mData = rhs.mData;
        cout << "X::X(const X& rhs)" << endl;
    }

    void setData(int n) {
        mData = n;
    }

    void print() {
        cout << "X::mData == " << mData << endl;
    }
private:
    int mData;
};

X func() {
    X xx;
    xx.setData(101);
    return xx;
}

/*编译优化fun函数
 *void func(X &__result) {
 *  X xx;
 *  xx.X::X();          //调用类x的默认构造函数
 *  xx.setData(101);
 *  __result.X::X(xx);  //调用类x的拷贝构造函数
 *  return ;
 * }
 * */

int main() {
    //X xx = func();
    /*编译器转换为:
     *  X xx    //不调用构造函数
     *  func(xx);
     * */

    func().print();
    /*编译器可能转换为
     *  { 
     *      X __temp;
     *      func(__temp);
     *      __temp.print();
     *  }
     * */
    return 0;
}

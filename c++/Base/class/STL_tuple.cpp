/**
* Create Date:2016年03月14日星期一 18:44:00
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
#include <tuple>
#include <functional>

int main(){
    int myint;
    char mychar;
    float myfloat;

    auto t1 = make_tuple(10,"Test",3.14); //创建元组

    cout << "The value of t1 is"
        << "(" << get<0>(t1) << "," << get<1>(t1)
        << "," << get<2>(t1) << ")\n";
    //get<>访问元组的元素

    int n = 1;
    auto t2 = make_tuple(ref(n),n); //ref表示引用

    n = 7;

    cout << "The value of t2 is" 
        << "(" << get<0>(t2) << "," << get<1>(t2) << ")\n";

    tuple<int,float,char> mytuple;
    mytuple = make_tuple(10,2.6,'a');

    //tie解包到元组
    tie(myint,myfloat,mychar)  = mytuple;

    cout << "myint contains:" << myint << endl;
    cout << "mychar contains:" << mychar <<endl;
    cout << "myfloat contains:" << myfloat << endl;
    //修改元组元素
    get<0>(mytuple) = 100;
    cout << "After assignment myint contains: " << get<0>(mytuple) << endl;

    tuple<float,string> my_tuple(3.14,"pi");
    pair<int,char> mypair(10,'a');
    //tuple_cat连接元组
    auto myauto = tuple_cat(my_tuple,mypair);

    cout << "myauto contains:" << endl;
    cout << get<0>(myauto) << endl;
    cout << get<1>(myauto) << endl;
    cout << get<2>(myauto) << endl;
    cout << get<3>(myauto) << endl;
    return 0;
}

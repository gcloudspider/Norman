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
/*
template <class T,class type>
void function(T iter,type u) {
    type temp;  //模板自动推导机制
}

template<class T>
void func(T iter) {
    function(iter, *iter);
}

*/
template <class T>
struct Iterator {
    typedef T value_type; //内嵌型别声明
};

template <class Iterator>
typename Iterator::value_type   //返回值类型
GetValue(Iterator iter) {
    return *iter;
}



int main() {
  //  int i = 12;
    //func(&i);

    Iterator<int> ite(new int(9));
    std::cout << GetValue(ite) << std::endl;
    return 0;
}

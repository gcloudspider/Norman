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
#include<type_traits>
using namespace std;

template<typename Type>
struct GetLeftSize: std::integral_constant<int,1> {
    
};

int main() {
    cout << "is_const:" << endl;
    cout << "int:" << std::is_const<int>::value << endl;
    cout << "const int: " << std::is_const<const int>::value << endl;
    cout << "const int&: " << std::is_const<const int&>::value << endl;
    cout << "const int*: " << std::is_const<const int*>::value << endl;
    cout << "int* const: " << std::is_const<int* const>::value << endl;
    return 0;
}

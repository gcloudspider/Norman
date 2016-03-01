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

int main(){
    int x = 0B1100;   //二进制
    int y = 011;      //八进制
    int z = 0x12;       //十六进制
    int w = 123;        //十进制

    cout << "x= " << x << endl;
    cout << "y= " << y << endl;
    cout << "z= " << z << endl;
    cout << "w= " << w << endl;
}

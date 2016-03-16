/**
* Create Date:2016年03月16日星期三 09:46:48
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

int main() {
    int a = 3;
    int b = 4;
    int x = 6;
    int y = 7;

    auto fun = [&x,y](int z1,int z2) ->int {
        x = 9;
        return z1 + z2 + x + y;
    };

    int sum = fun(a,b);
    cout << "x = " << x << endl;
    cout << "sum = " << sum << endl;

    for(auto i= 0;i<8;i++) {
        
        auto fy = [&y](){ 
                if(y ==0) {
                    return true;
                } else {
                    y--;
                    return false;
                }
            };
        cout << "y = " <<  fy() << endl;
    }
}

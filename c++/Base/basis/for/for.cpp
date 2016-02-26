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
#include<vector>
using namespace std;

/*
*C++98/03版本遍历:
for(auto it = arr.begin();it != arr.end();++it){
    cout << *it << endl;
    return 0;
}

/////////////////////////////////////////////////
void do_cout(){
    cout << n << endl;
}

for_each(arr.begin(), arr.end(),do_cout);
* */

int main(){
    vector<int>arr = {1,2,3,4};

    for (auto n: arr) {
        cout << n << endl;
    }
    return 0;
}

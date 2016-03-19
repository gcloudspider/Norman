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
#include <numeric>
using namespace std;

int main() {
    int numbers[10];
    iota(numbers,numbers+10,100);

    cout << "numbers: ";
    for(int& i: numbers) cout << " " << i;
    cout << endl;

    return 0;
}

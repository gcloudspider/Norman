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

//创建二维不规则数组
//
#include<iostream>
using namespace std;

int main(){
    int numberOfRows = 5;

    int length[5] = {6,3,4,2,7};

    int **irregularArray = new int* [numberOfRows];

    for(int i = 0;i<numberOfRows;i++)
        irregularArray[i]  = new int [length[i]];

    irregularArray[2][3] = 5;
    irregularArray[4][6] = irregularArray[2][3]+2;
    irregularArray[1][1] = 3;

    cout<<irregularArray[2][3]<<endl;
    cout<<irregularArray[4][6]<<endl;
    cout<<irregularArray[1][1]<<endl;

    return 0;
}

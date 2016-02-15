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
//动态分配内存创建二维数组

#include <iostream>
using namespace std;
#include <stdio.h>
#include<stdlib.h>

template<class T>
void make2dArray(T** &x,int numberOfRows,int numberOfColumns){
    x = new T* [numberOfRows];
    for(int i=0;i<numberOfRows;i++)
        x[i] = new T [numberOfColumns];
}
template<class T>
void delete2dArray(T** &x,int numberOfRows){
    for(int i=0;i<numberOfRows;i++){
        delete [] x[i];
    }
    delete []x;
    x= NULL;
}

int main(){
    char ** x;
    int r=3,c=5;
    try{
        make2dArray(x,r,c);
    }catch(bad_alloc){
        cout<<"could not create x"<<endl;
        exit(1);
    }
    cout<<"create x success!"<<endl;
    delete2dArray(x,r);
    cout<<"delete x success!"<<endl;

    return 0;
}

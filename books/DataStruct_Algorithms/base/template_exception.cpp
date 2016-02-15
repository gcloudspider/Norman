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
#include<stdio.h>
#include <iostream>
using namespace std;

//异常
//
template<class T>
T abc(T& a,T& b,T& c){
    if(a <=0 || b <=0 || c <=0){
        printf("error:\n");
        throw "All parameters should be > 0";
    }
    return a + b * c;
}


int main(){
    int a=2,b=0,c=4;
    try{cout<<abc(a,b,c)<<endl;}
    catch(char *e){
        cout<<"The parameters to abc were 2,0,and 4"<<endl;   
        cout<<"An exception has been thrown"<<endl;
        cout<<e<<endl;
        return 1;
    }
    return 0;
}

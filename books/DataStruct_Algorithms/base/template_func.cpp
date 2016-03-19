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

//形参值传递
template<class T>
T abc(T a,T b,T c){
    return a+b*c;
}

//引用传递
template<class R>
R abd(R& a,R& b,R& c){
    return a + b * c;
}

//常量引用参数(参数不能被函数修改)
template<class U>
U abb(const U& a, const U& b, const U& c){
    return a + b * c;
}


//更通用版本
//第一个形参与函数返回值类型相同
//其他形参可以是其他类型(不必相同数据类型)
template<class Ta,class Tb, class Tc>
Ta abe(const Ta& a, const Tb& b,const Tc& c){
    return a + b * c;
}

int main(){
    //模板函数
    printf("%d\n",abc(2,4,3));
    printf("%f\n",abc(2.9,3.2,2.2));
    

    int x=3,y=4,z=2;
    double xx=1.2,yy=2.1,zz=3.1;
    printf("%d\n",abd(x,y,z));
    printf("%f\n",abd(xx,yy,zz));

    
    printf("%d\n",abb(x,y,z));
    printf("%f\n",abb(xx,yy,zz));


    printf("%d\n",abe(4,2.3,4.0));
    return 0;
}

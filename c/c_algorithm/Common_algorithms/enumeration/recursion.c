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
//一个自然数被8除余1,所得商被8除也余1,再将第二次商被8除后余7 最后得到一个商为a 又知这个自然数被17除余4 所得商被17除余15最后得到一个商是a的2倍

#include<stdio.h>

int main(){
    int i;
    for(i=0;;i++){
        if((((i*8+7)*8)+1)*8+1==(34*i+15)*17+4){
            printf("the required number is:%d\n",(34*i+15)*17+4);
            break;
        }
    }
}

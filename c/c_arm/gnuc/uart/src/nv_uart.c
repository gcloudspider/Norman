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
#include "../include/nv_arm.h"

void init_uart0(){
    rULCON0 = 0x3;
    rUCON0 =  0x5;
    /*
    *11 10 9 8  7 6 5 4   3 2 1 0
    *0  0  0 0  0 0 0 0   0 1 0 1
    * */
    rUBRDIV0 = (int)(50000000/(115200*16))-1;

    rGPHCON = 0xa << 4;

}

char get_char(){
    while(1){
        if(rUTRSTAT0&0x1)
            return rURXH0;
    }
}

void put_char(char ch){
    while(1){
        if(rUTRSTAT0&0x4){
            rUTXH0 = ch;
            return;
        }
    }
}

void put_string(const char* str){
    while(*str){
        if(*str == '\n'){
            put_char('\r');
        }
        put_char(*str++);
    }
}

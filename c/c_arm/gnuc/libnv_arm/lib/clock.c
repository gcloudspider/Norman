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
#include "../include/gpio.h"

void init_clock(){
    //CLKDIVN 寄存器的 HDIVN[2:1]
    //f=200M, H=100M p=50M
    //1:2:4
    //f=400M,H=100M,p=50M
    //1:4:8
    rCLKDIVN = 3;  //1:2:4 200M
    //rCLKDIVN = 
    __asm__(
    "mrc p15,0,r0,c1,c0,0\n"
    "orr r0,r0,#0xc0000000\n"
    "mcr p15,0,r0,c1,c0,0\n"
    );

    rMPLLCON = 0x5c<<12|0x1<<4|0x2;
}

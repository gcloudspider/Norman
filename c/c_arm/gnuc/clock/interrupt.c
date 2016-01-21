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

#include "include/gpio.h"

void init_interrupt_for_key(){
    rINTMSK &= ~(1<<5);
    rEINTMSK &= EINTMASK8 & EINTMASK11 & EINTMASK13
            & EINTMASK14 & EINTMASK15 & EINTMASK18;

    rGPGCON |= GPG0_EINT|GPG3_EINT|GPG5_EINT|GPG6_EINT
            |GPG7_EINT|GPG11_EINT;

    //此处可以添加改变扩展GPIO复用中断类型的选择代码
    rEXTINT1 = 0;
}

void interrupt_f(){
    switch(rINTOFFSET){
        case 5:
            int_key();
            break;
        default:
            break;
    }
    //清理
    rSRCPND = rSRCPND;
    rINTPND = rINTPND;
    rEINTPEND = rEINTPEND;
}

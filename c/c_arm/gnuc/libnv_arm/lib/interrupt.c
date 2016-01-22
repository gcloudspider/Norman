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
        case 10:
            break;
        case 14:
            int_timer4();
            break;
        default:
            break;
    }
    //清理
    rSRCPND = rSRCPND;
    rINTPND = rINTPND;
    rEINTPEND = rEINTPEND;
}

void int_timer4(){
    //静态变量 数据存储在数据段(静态区) 需要使用lds 脚本方式去链接
    static int i=-1;
    i++;
    switch(i%8){
        case 0:
            led_on(1);
            beep_on();
            break;
        case 2:
            led_on(2);
            beep_on();
            break;
        case 4:
            led_on(3);
            beep_on();
            break;
        case 6:
            led_on(4);
            beep_on();
            break;
        default:
            led_off_all();
            beep_off();
            break;
    }
}

void init_interrupt_for_timer4(){
    rINTMSK &= ~(1<<14);
}

void init_interrupt_for_timer0(){
    rINTMSK &= ~(1<<10);
}

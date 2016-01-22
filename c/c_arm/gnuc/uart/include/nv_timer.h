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

//定时器寄存器地址
#define rTCFG0 \
        *(volatile unsigned*)0x51000000
#define rTCFG1 \
        *(volatile unsigned*)0x51000004
#define rTCON \
        *(volatile unsigned*)0x51000008
#define rTCNTB0 \
        *(volatile unsigned*)0x5100000C
#define rTCMPB0 \
        *(volatile unsigned*)0x51000010

#define rTCNTB4 \
        *(volatile unsigned*)0x5100003C
#define rTCNT04\
        *(volatile unsigned*)0x51000040

//定时器
void init_timer4();
void init_interrupt_for_timer4();
void int_timer4();

//pwm0 脉冲调制
void init_timer0();
void init_interrupt_for_timer0();
void init_pwm0();

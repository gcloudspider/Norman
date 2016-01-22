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

/*
*判断是哪个按键按的
* */
//GPG 配置寄存器
#define rGPGCON \
        *(volatile unsigned*) 0x56000060
/*按键设置输入输出模式---轮循方式才需要设置此寄存器*/
#define rGPGDAT \
        *(volatile unsigned*) 0x56000064

//按钮初始化为输入模式 轮循方式才需要设置此寄存器
#define GPG0_IN         ~(3<<0*2)
#define GPG3_IN         ~(3<<3*2)
#define GPG5_IN         ~(3<<5*2)
#define GPG6_IN         ~(3<<6*2)
#define GPG7_IN         ~(3<<7*2)
#define GPG11_IN        ~(3<<11*2)

//按钮没按下为高电平 1
//按钮按下为低电平 0
#define EINTMASK8        ~(1<<8)
#define EINTMASK11       ~(1<<11)
#define EINTMASK13       ~(1<<13)
#define EINTMASK14       ~(1<<14)
#define EINTMASK15       ~(1<<15)
#define EINTMASK18       ~(1<<19)

#define GPG0_EINT         2<<0*2
#define GPG3_EINT         2<<3*2
#define GPG5_EINT         2<<5*2
#define GPG6_EINT         2<<6*2
#define GPG7_EINT         2<<7*2
#define GPG11_EINT        2<<11*2

#define KEY_1             1
#define KEY_2             2
#define KEY_3             3
#define KEY_4             4
#define KEY_5             5
#define KEY_6             6

//此是轮循方式需要设置GPGDAT寄存器
//初始化按键
void init_key();

int key_press();

void int_key();
//判断按下数字键
static int press_keynum();

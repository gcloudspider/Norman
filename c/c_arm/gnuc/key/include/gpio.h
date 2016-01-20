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

#ifndef _GPIO_H_
#define _GPIO_H_

//GPG 配置寄存器
#define rGPGCON \
        *(volatile unsigned*) 0x56000060
#define rGPGDAT \
        *(volatile unsigned*) 0x56000064

//GPB 
#define	rGPBCON	\
	*(volatile unsigned long*)0x56000010
//数据寄存器
#define rGPBDAT	\
	*(volatile unsigned long*)0x56000014

//蜂鸣器初始化为输出模式
#define GPB0_OUT	1<<2*0

//LED灯初始化为输出模式
#define GPB5_OUT	1<<2*5
#define GPB6_OUT	1<<2*6
#define GPB7_OUT	1<<2*7
#define GPB8_OUT	1<<2*8

//按钮初始化为输入模式
#define GPG0_IN         ~(3<<0*2)
#define GPG3_IN         ~(3<<3*2)
#define GPG5_IN         ~(3<<5*2)
#define GPG6_IN         ~(3<<6*2)
#define GPG7_IN         ~(3<<7*2)
#define GPG11_IN        ~(3<<11*2)
//按钮没按下为高电平 1
//按钮按下为低电平 0

//蜂鸣器函数
void init_beep();
void beep_on();
void beep_off();

//按钮函数
void init_key();
int key_press();

//LED灯函数
void init_led();
void led_on(int num);
void led_off(int num);
void led_on_all();
void led_off_all();

#endif

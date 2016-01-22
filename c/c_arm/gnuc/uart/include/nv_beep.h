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

#ifndef _NVBEEP_H_
#define _NVBEEP_H_
/*
*volatile 告诉编译器每次取值从源取:如(tmp=a) (c=a) 编译器优化成c=tmp=a
* volatile 告诉编译器不需要优化。每次取值(c=a)
* */
//GPB设置模式(设置中断模式将GPG*设为10(EINT扩展))
#define	rGPBCON	\
	*(volatile unsigned long*)0x56000010
//数据寄存器
#define rGPBDAT	\
	*(volatile unsigned long*)0x56000014

//蜂鸣器初始化为输出模式
//#define GPB0_OUT	1<<2*0
#define GPB0_OUT	(1<<0)
#define GPB0_TOUT0	(1<<1)

//蜂鸣器函数
void init_beep();
void beep_on();
void beep_off();
#endif

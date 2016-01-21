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
/*
*volatile 告诉编译器每次取值从源取:如(tmp=a) (c=a) 编译器优化成c=tmp=a
* volatile 告诉编译器不需要优化。每次取值(c=a)
* */
//GPG 配置寄存器
#define rGPGCON \
        *(volatile unsigned*) 0x56000060
/*按键设置输入输出模式---轮循方式才需要设置此寄存器*/
#define rGPGDAT \
        *(volatile unsigned*) 0x56000064



//GPB设置模式(设置中断模式将GPG*设为10(EINT扩展))
#define	rGPBCON	\
	*(volatile unsigned long*)0x56000010
//数据寄存器
#define rGPBDAT	\
	*(volatile unsigned long*)0x56000014

//中断模式中各寄存器地址
//中断来了后是哪个中断
#define rSRCPND \
        *(volatile unsigned long*)0X4A000000
//中断寄存器模式(普通中断/快速中断) 快中断只能有一个(32位写1只能写一个)
#define rINTMOD \
        *(volatile unsigned long*)0X4A000004 
//中断掩码寄存器,让某一位屏蔽(禁掉) 位为1屏蔽 初始值32位都是关闭的
#define rINTMSK \
        *(volatile unsigned long*)0X4A000008
//优先级寄存器(普通中断)只能有一个(6个组 组排序--组内再排序)
#define rPRIORITY \
        *(volatile unsigned long*)0X4A00000C 
//经过优先级后只有一个中断写入该寄存器
#define rINTPND \
        *(volatile unsigned long*)0X4A000010
//帮助判断(共用)是哪个中断(此寄存器就是二进制的值)
#define rINTOFFSET \
        *(volatile unsigned long*)0X4A000014 
//对应子中断
#define rSUBSRCPND \
        *(volatile unsigned long*)0X4A000018 
//子中断掩码寄存器(串口一定要打开此)
#define rINTSUBMSK \
        *(volatile unsigned long*)0X4A00001C 

/*
*判断是哪个按键按的
* */
//悬而未决(未处理) 
//行为规则:
    //SRCPND:允许多个 (注意:返回之前清除,若有多个指定位写入)
    //INTPND:只能有一个 
    //EINTPND:
//注意:返回之前清除(往位写1---把原来的值再写一次(不是写0))
#define rEINTPEND \
        *(volatile unsigned long*)0x560000a8 
//把对应中断打开(清零)
#define rEINTMSK \
        *(volatile unsigned long*)0x560000a4 
//这三个扩展
#define rEXTINT0 \
        *(volatile unsigned long*)0x56000088 
#define rEXTINT1 \
        *(volatile unsigned long*)0x5600008c 
#define rEXTINT2 \
        *(volatile unsigned long*)0x56000090 

//蜂鸣器初始化为输出模式
#define GPB0_OUT	1<<2*0

//LED灯初始化为输出模式
#define GPB5_OUT	1<<2*5
#define GPB6_OUT	1<<2*6
#define GPB7_OUT	1<<2*7
#define GPB8_OUT	1<<2*8

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

//蜂鸣器函数
void init_beep();
void beep_on();
void beep_off();

//按钮函数
/*此是轮循方式需要设置GPGDAT寄存器
void init_key();
int key_press();
*/
void int_key();
static int press_keynum();

/*
*中断模式不设GPGDATA寄存器使用中断
* */
void init_interrupt_for_key();
void interrupt_f();

//LED灯函数
void init_led();
void led_on(int num);
void led_off(int num);
void led_on_all();
void led_off_all();

#endif

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

//中断模式不设GPGDATA寄存器使用中断
void init_interrupt_for_key();
void interrupt_f();

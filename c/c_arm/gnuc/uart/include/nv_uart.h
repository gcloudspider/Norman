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
//异步串口线路控制寄存器
//主要用于配置通信的校验,停止,数据位
#define rULCON0 \
        *(volatile unsigned long*) 0x50000000

//异步串口控制寄存器
//用于设定串口工作频率,收发方式
#define rUCON0 \
        *(volatile unsigned long*) 0x50000004

//串口收发状态寄存器
//用于判断硬件是否可以发送或接收数据
#define rUTRSTAT0 \
        *(volatile unsigned long*) 0x50000010

//串口发送数据的缓冲寄存器
//此寄存器会把写入数据发送出去
#define rUTXH0 \
        *(volatile unsigned long*) 0x50000020

//串口接收数据的缓冲寄存器
//用于把接收的数据暂时存放于此
#define rURXH0 \
        *(volatile unsigned long*) 0x50000024

//串口涌上特率配置寄存器
//用于设定异步串口工作的波特率
#define rUBRDIV0 \
        *(volatile unsigned long*) 0x50000028

//该寄存器的[7:4] 用于设定异步串口管脚复用
#define rGPHCON \
        *(volatile unsigned long*) 0x56000070

//初始化
void init_uart0();

//获取字符
char get_char();

//打印字符
void put_char(char ch);

//打印字符串
void put_string(const char* str);

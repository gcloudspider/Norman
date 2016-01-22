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

//时钟频率寄存器地址
#define rCLKDIVN \
        *(volatile unsigned long*)0x4C000014
#define rMPLLCON \
        *(volatile unsigned long*)0x4C000004

//时钟频率
void init_clock();

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
#define	rGPBCON	\
	*(volatile unsigned long*)0x56000010
#define rGPBDAT	\
	*(volatile unsigned long*)0x56000014
#define GPB0_OUT	1<<2*0

void init_beep(){
	rGPBCON |= GPB0_OUT;
}

void beep_on(){
    rGPBDAT |= (1<<0);
}
void beep_off(){
    rGPBDAT &= ~(1<<0);
}

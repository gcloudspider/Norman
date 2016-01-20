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
#include "include/gpio.h"
//& 二进制只要有一个为0则为0
//| 二进制只要有一个为1则为1

void init_beep(){
	rGPBCON |= GPB0_OUT;
}

void beep_on(){
    //蜂鸣器需要将置1为蜂鸣器响
    rGPBDAT |= (1<<0);
}
void beep_off(){
    //置0为蜂鸣器不响
    rGPBDAT &= ~(1<<0);
}

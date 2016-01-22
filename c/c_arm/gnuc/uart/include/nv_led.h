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

//LED灯初始化为输出模式
#define GPB5_OUT	1<<2*5
#define GPB6_OUT	1<<2*6
#define GPB7_OUT	1<<2*7
#define GPB8_OUT	1<<2*8

//LED灯函数
void init_led();
void led_on(int num);
void led_off(int num);
void led_on_all();
void led_off_all();

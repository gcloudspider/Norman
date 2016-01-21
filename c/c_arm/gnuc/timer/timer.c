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

void init_timer4(){
    /*
    *公式:
    *TF = PCLK /{prescaler value+1} /{divider value};
    *{prescaler value} = 0~255
    *{divider value} = 2,4,8,16
    * */
    rTCFG0 = 99<<8;  //prescaler:99+1=100
    rTCFG1 = 3<<16;  //divider 16
    rTCNTB4 = 31250/2;  //设置时间 0.5秒

    rTCON |= 1<<21;  //设置手动更新计时器4
    rTCON = 5<<20;
    //5  = 0101 左移20位
    //将[22] [21] [20] 第20 22位置1
    //开启计时器
    //开启自动重置数
}

int write_TCNTB4(int c){
    rTCNTB4 = c;
}
int read_TCNTB4(){
    return rTCNTB4;
}

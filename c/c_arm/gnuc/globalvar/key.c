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

void init_key(){
    rGPGCON &= GPG0_IN&GPG3_IN&GPG5_IN
        &GPG6_IN&GPG7_IN&GPG11_IN;
    //初始化为输入模式
    //1100 0000 1111 1100 1100 0011
}

int isKey(int num){
    //默认不按按钮是高电平rGPGDAT值为1
    //按下按钮为0
    switch(num){
        case 1:
            //0与1为0 否返回1
            return rGPGDAT&(1<<0)?0:1;
        case 2:
            return rGPGDAT&(1<<3)?0:1;
        case 3:
            return rGPGDAT&(1<<5)?0:1;
        case 4:
            return rGPGDAT&(1<<6)?0:1;
        case 5:
            return rGPGDAT&(1<<7)?0:1;
        case 6:
            return rGPGDAT&(1<<11)?0:1;
        default:
            return 0;
    }
}

int key_press(){
    int i;
    for(i=1;i<=6;i++){
        //判断按钮是否按下
        if(isKey(i)) return i;
    }   
}

static int press_keynum(){
    if(rEINTPEND &(1<<8)) return 1;
    if(rEINTPEND &(1<<11)) return 2;
    if(rEINTPEND &(1<<13)) return 3;
    if(rEINTPEND &(1<<14)) return 4;
    if(rEINTPEND &(1<<15)) return 5;
    if(rEINTPEND &(1<<19)) return 6;
}

void long_press(int key_num,int num){
    if((rEXTINT1 &(7<<num))==0){
        if(key_num == 5 || key_num == 6){
            led_on_all();
        }else{
            led_on(key_num);
        }
        beep_on();
        rEXTINT1 &= ~(7<<num);
        rEXTINT1 |= 0x4;
    } else if((rEXTINT1 &(7<<num)) == 0x4){
        led_off_all();
        beep_off();
        rEXTINT1 &= ~(7<<num);
    }
}

void int_key(){
    int k;
    int i=0xfffa;
    int num = press_keynum();
    switch(num){
        case KEY_1:{
            long_press(KEY_1,0);
            break;
        }
        case KEY_2:{
            //led_on(KEY_2);
            long_press(KEY_2,11);
            break;
        }
        case KEY_3:{
            //led_on(KEY_3);
            long_press(KEY_3,13);
            break;
        }
        case KEY_4:{
            //led_on(KEY_4);
            long_press(KEY_4,14);
            break;
        }
        case KEY_5:{
            //led_on_all();
            long_press(KEY_5,15);
            break;
        }
        case KEY_6:{
            //led_on_all();
            long_press(KEY_6,19);
            break;
        }   
    }
}

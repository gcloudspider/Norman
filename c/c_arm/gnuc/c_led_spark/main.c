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

int main(){
    //关闭看门狗
    //unsigned *WDT = 0x53000000;
    //*WDT = 0;
    unsigned *GPBCON = 0x56000010;
    unsigned *GPBDAT = 0x56000014;
    unsigned *gpbcon_b = 0x15400; 
    //[17:16][15:14][13:12] 开启输出模式
    //对应led1 led2 led3 led4
    //00 0001 0101 0100 0000 0000
    *GPBCON = gpbcon_b;

    int i;
    int j;
    
    while(1){
        for(j=0;j<4;j++){
            *GPBDAT = 0xffffffff;
            //1111 1111 1111 1111 1111 1111 1111 1111
            //将所在处于高电平
            for(i=0xfff1;i--;);
            //左移 取反将该位置0 低电平点亮led
            *GPBDAT = ~(0x1<<5+j);
            for(i=0xfff1;i--;);
        }   
    }
    return 0;
}

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
    //设置GPB5~8为输出模式
    unsigned *GPBCON = 0x56000010;
    unsigned *gpbcon_b = 0x15400;
    *GPBCON = gpbcon_b;

    unsigned *GPBDAT = 0x56000014;
    int i;
    while(1){
        *GPBDAT = 0xffffffff;

        for(i=0xffff;i--;);

        *GPBDAT = 0x0;

        for(i=0xffff;i--;);
    }
    return 0;
}

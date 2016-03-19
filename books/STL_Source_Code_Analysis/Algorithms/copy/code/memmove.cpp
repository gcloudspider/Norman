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
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "memmove can be very useful.....";
    //允许输出区间起始位置与输入区间重叠
    memmove(str+20,str+15,11);
    puts(str);
    return 0;
}

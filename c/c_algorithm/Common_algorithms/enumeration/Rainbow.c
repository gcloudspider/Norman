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
int main(){
    int i,j,count=0;
    printf("RED BALL WHITE BALL BLACK BALL\n");
    printf("------------------------------\n");
    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if((8-i-j)<=6)
                printf("%2d: %d %d %d\n",++count,i,j,8-i-j);
        }
    }
}

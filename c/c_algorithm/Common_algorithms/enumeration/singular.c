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
    int i,j,k;
    for(i=1;i<7;i++){
        for(j=0;j<7;j++){
            for(k=1;k<7;k++){
                if(i*9*9+j*9+k==i+j*7+k*7*7){
                    printf("the special number with 3 digits is:");
                    printf("%d%d%d(7)=%d%d%d(9)=%d(10)\n",k,j,i,i,j,k,i*9*9+j*9+k);
                }
            }
        }
    }
}

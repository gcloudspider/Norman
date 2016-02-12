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
    int i,j,n=0,x;
    for(i=23;n==0;i+=2){
        for(j=1,x=i;j<=4;j++){
            if((x+1)%(j+1)==0)
                x-=(x+1)/(j+1);
            else {
                x=0;
                break;
            }
        }
        if(x==11){
            printf("there are %d fishes at first.\n",i);
            n = 1;
        }
    }
}

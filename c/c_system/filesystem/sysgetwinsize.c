/*########################################################
##File Name: sysgetwinsize.c
##Created Time:2015年12月09日 星期三 12时28分21秒
##Author: Norman 
##Description: 
##
##Issue: 
##
##Analyze: 
##
##Induction:
##
##Summary:
##
##########################################################*/

#include<stdio.h>
#include"head.h"

int main(){
    struct winsize size;
    ioctl(1,TIOCGWINSZ,&size);
    printf("rows:%d,column:%d\n",size.ws_row,size.ws_col);
    return 0;
}
